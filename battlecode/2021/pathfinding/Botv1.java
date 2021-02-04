package Botv1;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.HashMap;
import java.util.Comparator;
import java.util.Arrays;

import battlecode.common.*;

public strictfp class RobotPlayer {
    static RobotController rc;

    static final RobotType[] spawnableRobot = {
        RobotType.POLITICIAN,
        RobotType.SLANDERER,
        RobotType.MUCKRAKER,
    };

    static final Direction[] directions = {
        Direction.NORTH,
        Direction.NORTHEAST,
        Direction.EAST,
        Direction.SOUTHEAST,
        Direction.SOUTH,
        Direction.SOUTHWEST,
        Direction.WEST,
        Direction.NORTHWEST,
    };


    // List to store known enlightenment centres
    // Constant length for now. Probably change this.
    static MapLocation[] KNOWN_CENTRES = new MapLocation[30];
    static int FOUND_CENTRES = 0;

    static int turnCount;

    // Used to centre our working map.
    static MapLocation origin;
    // Map to store terrain data.
    static int MAPSIZE = 129;
    static double[][] terrainMap = new double[MAPSIZE][MAPSIZE];
    
    /**
     * run() is the method that is called when a robot is instantiated in the Battlecode world.
     * If this method returns, the robot dies!
     **/
    @SuppressWarnings("unused")
    public static void run(RobotController rc) throws GameActionException {

        // This is the RobotController object. You use it to perform actions from this robot,
        // and to get information on its current status.
        RobotPlayer.rc = rc;

        RobotType thisType = rc.getType();

        // Get HQ Location for a spawned unit.
        if (thisType == RobotType.POLITICIAN || thisType == RobotType.SLANDERER || thisType == RobotType.MUCKRAKER) {
                RobotInfo[] adjacent_bots = rc.senseNearbyRobots(2, rc.getTeam());

                for (RobotInfo bot: adjacent_bots) {
                    if (bot.type == RobotType.ENLIGHTENMENT_CENTER) {
                        KNOWN_CENTRES[FOUND_CENTRES] = bot.location;
                        FOUND_CENTRES++;
                    }
                }
        }

        turnCount = 0;

        // Setup map of the board
        // Arrays.fill(terrainMap, -1);
        origin = rc.getLocation();

        System.out.println("I'm a " + rc.getType() + " and I just got created!");
        while (true) {
            turnCount += 1;
            // Try/catch blocks stop unhandled exceptions, which cause your robot to freeze
            try {
                // Here, we've separated the controls into a different method for each RobotType.
                // You may rewrite this into your own control structure if you wish.
                System.out.println("I'm a " + rc.getType() + "! Location " + rc.getLocation());
                switch (rc.getType()) {
                    case ENLIGHTENMENT_CENTER: runEnlightenmentCenter(); break;
                    case POLITICIAN:           runPolitician();          break;
                    case SLANDERER:            runSlanderer();           break;
                    case MUCKRAKER:            runMuckraker();           break;
                }

                // Clock.yield() makes the robot wait until the next turn, then it will perform this loop again
                Clock.yield();

            } catch (Exception e) {
                System.out.println(rc.getType() + " Exception");
                e.printStackTrace();
            }
        }
    }

    static void runEnlightenmentCenter() throws GameActionException {
        RobotType toBuild = randomSpawnableRobotType();
        int influence = 50;
        for (Direction dir : directions) {
            if (rc.canBuildRobot(toBuild, dir, influence)) {
                rc.buildRobot(toBuild, dir, influence);
            } else {
                break;
            }
        }
    }

    static void runPolitician() throws GameActionException {
        Team enemy = rc.getTeam().opponent();
        int actionRadius = rc.getType().actionRadiusSquared;
        RobotInfo[] attackable = rc.senseNearbyRobots(actionRadius, enemy);
        if (attackable.length != 0 && rc.canEmpower(actionRadius)) {
            System.out.println("empowering...");
            rc.empower(actionRadius);
            System.out.println("empowered");
            return;
        }
        if (rc.getRoundNum() > 400) {
            tryMove(stochastic_pathfind(rc.getLocation(),KNOWN_CENTRES[0]));
        }
        else if (tryMove(randomDirection()))
            System.out.println("I moved!");
    }

    static void runSlanderer() throws GameActionException {
        if (tryMove(randomDirection()))
            System.out.println("I moved!");
    }

    static void runMuckraker() throws GameActionException {
        Team enemy = rc.getTeam().opponent();
        int actionRadius = rc.getType().actionRadiusSquared;

        for (RobotInfo robot : rc.senseNearbyRobots(actionRadius, enemy)) {
            if (robot.type.canBeExposed()) {
                // It's a slanderer... go get them!
                if (rc.canExpose(robot.location)) {
                    System.out.println("e x p o s e d");
                    rc.expose(robot.location);
                    return;
                }
            }
        }

        if (tryMove(randomDirection()))
            System.out.println("I moved!");
    }

    // random direction
    static Direction randomDirection() {
        return directions[(int) (Math.random() * directions.length)];
    }


    static RobotType randomSpawnableRobotType() {
        return spawnableRobot[(int) (Math.random() * spawnableRobot.length)];
    }
    static Direction reconstruct_path(HashMap<MapLocation,MapLocation> cameFrom, MapLocation current) {
        MapLocation last = current;
        System.out.println("Reconstructing a path to" + current.x+","+current.y);
        while (cameFrom.containsKey(current)) {
            last = current;
            current = cameFrom.get(current);
        }
        System.out.println("Closest Square" + last.x+","+last.y);
        return rc.getLocation().directionTo(last);

    }

    /** Gives the preferred direction to pathfind between two squares
     * 
     * @return a direction
     */
    static Direction a_star(MapLocation goal)  throws GameActionException {

        HashMap<MapLocation,Double> fScore = new HashMap<MapLocation, Double>();

        Comparator<MapLocation> compar = new Comparator<MapLocation>() {
            @Override
            public int compare(MapLocation a, MapLocation b) {
                double fa = 0;
                if (fScore.get(a) == null) {
                    fa = 10000000;
                } else {
                    fa = fScore.get(a);
                }
                double fb = 0;
                if (fScore.get(b) == null) {
                    fb = 10000000;
                } else {
                    fb = fScore.get(b);
                }
                return (int) (fa - fb);
            }
        };


        PriorityQueue<MapLocation> open = new PriorityQueue<MapLocation>(compar);
        HashMap<MapLocation,MapLocation> cameFrom = new HashMap<MapLocation, MapLocation>();
        HashMap<MapLocation, Double> gScore = new HashMap<MapLocation, Double>();
        
        
        gScore.put(rc.getLocation(),0.0);
        fScore.put(rc.getLocation(),heuristic(rc.getLocation(),goal));

        open.add(rc.getLocation());

        double lowestfScore = 100000000;
        MapLocation bestF = null;

        MapLocation current;
        while (!open.isEmpty()) {
            current = open.poll();

            if (fScore.get(current) < lowestfScore) {
                bestF = current;
                lowestfScore = fScore.get(current);
            }

            if (current.equals(goal)) {
                return reconstruct_path(cameFrom, current);
            }

            for (MapLocation adj_node: getAdjacent(current)) {
                if (adj_node == null) break;
                double thisG = 0;
                if (gScore.get(current)==null) {
                    thisG = 10000000;
                } else {
                    thisG = gScore.get(current);
                }

                double neighbourG = 0;
                if (gScore.get(adj_node)==null) {
                    neighbourG = 10000000;
                } else {
                    neighbourG = gScore.get(adj_node);
                }

                double tentative_gScore;
                if (rc.canDetectLocation(current)) {
                    tentative_gScore = thisG +  1/(rc.sensePassability(current)+0.01);
                } else {
                    tentative_gScore = thisG +  1/(0+0.01);
                }

                if (tentative_gScore < neighbourG) {
                    cameFrom.put(adj_node,current);
                    gScore.put(adj_node,tentative_gScore);
                    fScore.put(adj_node, tentative_gScore + heuristic(rc.getLocation(), adj_node));
                    if (!open.contains(adj_node)) {
                        open.add(adj_node);
                    }
                    
                }
                
            }
            System.out.println("Size of Open Queue: "+open.size());

            
        }
        // Change this to keep track of the best element found so far and reverse it.
        System.out.println("Pathing Failed - Target likely out of range");
        return reconstruct_path(cameFrom, bestF); // Paths towards the target tht
        /*
        Direction dir = rc.getLocation().directionTo(goal);
        if (rc.canMove(dir)) return dir;
        return Direction.CENTER;
        */
    }
    

    /** A* Heuristic Function based on passability 
     * 
     * @return a cost to reach a target node from the bot's current position
     */
    static double heuristic(MapLocation start, MapLocation end) {
        return Math.sqrt(start.distanceSquaredTo(end))/0.1;
    }

    // Attempt to pathfind stochastically
    static Direction stochastic_pathfind(MapLocation start, MapLocation end) throws GameActionException {

        // Keeps track of best path found yet
        MapLocation bestVertex = null;
        double highestPassability = Double.POSITIVE_INFINITY;

        // Get new RNG
        Random r = new Random();
        double std_dev = 3.0;

        // Start with one vertex on the plane halfway between start and end.
        // Sets the mean point to be this mid x
        int mean = (end.x + start.x)/2;
        
        // Hardcoded 10 loops for now.
        for (int i=0;i<6;i++) {

            // Find x by a gaussian distribution.
            int x = (int) (r.nextGaussian()*std_dev)+mean;

            // Calculate y from x.
            int y = mid_plane_y(x, start, end);

            MapLocation vertex = new MapLocation(x,y);
            
            // Sums together the total path passability
            double score = path_passabiity(start, vertex) + path_passabiity(vertex, end);

            if (score < highestPassability) {
                highestPassability = score;
                bestVertex = vertex;
            }
        }
        // Precaution in case execution fails somehow
        if (bestVertex == null) return Direction.CENTER;

        // Paths towards the best vertex.
        return rc.getLocation().directionTo(bestVertex);
    }

    // For two points and an x value, gets the y value of the point on the hyperplane between them.
    static int mid_plane_y(int x, MapLocation start, MapLocation end) {

        int dx = end.x-start.x;
        int dy = end.y-start.y;
        if (dy == 0) return start.y;
        double separating_grad = -dx/dy;
        double mid_point_x = (start.x + end.x)/2;
        double mid_point_y = (start.y + end.y)/2;
        double c = mid_point_y - separating_grad*(mid_point_x);
        return (int) (separating_grad*x + c);
    }

    // Uses Bresenham's Line drawing algorithm to iterate over points on the line joining two points.
    // Standard wikipedia implementation
    static double path_passabiity(MapLocation start, MapLocation end) throws GameActionException {
        int x0 = start.x;
        int y0 = start.y;
        int x1 = end.x;
        int y1 = end.y;

        if (Math.abs(y1-y0)<Math.abs(x1-x0)) {
            if (x0 > x1) {
                return path_passability_low(x1,y1,x0,y0);
            } else {
                return path_passability_low(x0,y0,x1,y1);
            }
        }
        else {
            if (y0 > y1) {
                return path_passability_high(x1,y1,x0,y0);
            } else {
                return path_passability_high(x0,y0,x1,y1);
            }
        }
    }

    static double path_passability_high(int x0, int y0, int x1, int y1) throws GameActionException {
        
        double passability = 0;

        int dx = x1-x0;
        int dy = y1-y0;
        int xi = 1;
        if (dx < 0) {
            xi = -1;
            dx = -dx;
        }
        int D = (2*dx) - dy;
        int x = x0;

        for (int y=y0;y<=y1;y++)  {
            System.out.println("Coords:" + x + ","+ y + " y0: " +y0 + " y1: "+ y1+ " Remaining Bytecodes: " + Clock.getBytecodesLeft());
            passability += square_passability(x, y);
            if (D > 0) {
                x += xi;
                D = D + (2*(dx-dy));
            }
            else {
                D = D + 2*dx;
            }
        }

        return passability;
    }

    static double path_passability_low(int x0, int y0, int x1, int y1) throws GameActionException {

        double passability = 0;

        int dx = x1-x0;
        int dy = y1-y0;
        int yi = 1;
        if (dx < 0) {
            yi = -1;
            dy = -dy;
        }
        int D = (2*dy) - dx;
        int y = y0;

        for (int x=x0;x<=x1;x++)  {
            System.out.println("Coords:" + x + ","+ y + " x0: " +x0 + " x1: "+ x1+ " Remaining Bytecodes: " + Clock.getBytecodesLeft());
            passability += square_passability(x, y);
            if (D > 0) {
                y += yi;
                D = D + (2*(dy-dx));
            }
            else {
                D = D + 2*dy;
            }
        }

        return passability;
    }

    // Wrapper around passability to handle un-detectable squares
    // TODO: Expand this to use our cached map once squares have been stored.
    static double square_passability(int x, int y) throws GameActionException {
        MapLocation loc = new MapLocation(x,y);
        if (terrainMap[x-origin.x+MAPSIZE/2][y-origin.y+MAPSIZE/2] != 0) {
            return terrainMap[x-origin.x+MAPSIZE/2][y-origin.y+MAPSIZE/2];
        }
        if (rc.canDetectLocation(loc)) {
            terrainMap[x-origin.x+MAPSIZE/2][y-origin.y+MAPSIZE/2] = rc.sensePassability(loc);
            return 1/rc.sensePassability(loc);
        } 
        if (rc.canDetectRadiusSquared(loc.distanceSquaredTo(rc.getLocation()))) {
            terrainMap[x-origin.x+MAPSIZE/2][y-origin.y+MAPSIZE/2] = 0.00001;
        }

        return 1/0.1;
    }


    static MapLocation[] getAdjacent(MapLocation loc) {

        MapLocation[] l = new MapLocation[8];
        int cnt = 0;

        for (Direction dir: Direction.allDirections()) {
            if (dir == Direction.CENTER) continue;
            MapLocation tmp = loc.add(dir);
            if (rc.canDetectLocation(tmp)) {
                l[cnt] = tmp;
                cnt++;
            }
        }

        return l;

    }

    /*
    static int[][] getAdjacent(int[] point) {}
    */
    /**
     * Attempts to move in a given direction.
     *
     * @param dir The intended direction of movement
     * @return true if a move was performed
     * @throws GameActionException
     */
    static boolean tryMove(Direction dir) throws GameActionException {
        System.out.println("I am trying to move " + dir + "; " + rc.isReady() + " " + rc.getCooldownTurns() + " " + rc.canMove(dir));
        if (rc.canMove(dir)) {
            rc.move(dir);
            return true;
        } else return false;
    }
}
