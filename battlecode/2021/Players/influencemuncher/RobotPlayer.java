package influencemuncher;
import battlecode.common.*;

import influencemuncher.PathBuild;

public strictfp class RobotPlayer {
    static RobotController rc;
    static MapLocation currGoal;
    static PathBuild currPath;

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

    static int turnCount;

    @SuppressWarnings("unused")
    public static void run(RobotController rc) throws GameActionException {

        // This is the RobotController object. You use it to perform actions from this robot,
        // and to get information on its current status.
        RobotPlayer.rc = rc;

        turnCount = 0;

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

    static RobotType getRobotFromDistribution(float pol, float muc, float sla) {
        float rand = Math.random();
        float pref_pol = pol;
        float pref_muc = pol + muc;
        float pref_sla = pref_muc + sla;
        if(rand < pref_pol) return spawnableRobot[0];
        else if(rand < pref_muc) return spawnableRobot[1];
        else if(rand < pref_sla) return spawnableRobot[2];

    }

    static void runEnlightenmentCenter() throws GameActionException {
        /*
        Let's pick our influence-muncher distribution to be a heavy
        focus on politicians
        
         - 50% politicians
         - 30% muckrakers
         - 10% slanderers
        
        adjust for the enemy team using communication (to be done)
        */
        
        // building robots
        int influence = 150;
        for (Direction dir : directions) {
            RobotType nextRobot = getRobotFromDistribution(0.6, 0.3, 0.1);
            if (rc.canBuildRobot(nextRobot, dir, influence)) {
                rc.buildRobot(nextRobot, dir, influence);
            } else {
                break;
            }
        }

        // bidding
    }

    static void runPolitician() throws GameActionException {
        // we want to navigate to the 
        /*
        Team enemy = rc.getTeam().opponent();
        int actionRadius = rc.getType().actionRadiusSquared;
        RobotInfo[] attackable = rc.senseNearbyRobots(actionRadius, enemy);
        if (attackable.length != 0 && rc.canEmpower(actionRadius)) {
            System.out.println("empowering...");
            rc.empower(actionRadius);
            System.out.println("empowered");
            return;
        }
        if (tryMove(randomDirection()))
            System.out.println("I moved!");
        */
    }

    static void runSlanderer() throws GameActionException {
        /*
        if (tryMove(randomDirection()))
            System.out.println("I moved!");
            */
    }

    static void runMuckraker() throws GameActionException {
        /*
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
            */
    }

    /*
    static Direction randomDirection() {
        return directions[(int) (Math.random() * directions.length)];
    }

    static RobotType randomSpawnableRobotType() {
        return spawnableRobot[(int) (Math.random() * spawnableRobot.length)];
    }

    static boolean tryMove(Direction dir) throws GameActionException {
        System.out.println("I am trying to move " + dir + "; " + rc.isReady() + " " + rc.getCooldownTurns() + " " + rc.canMove(dir));
        if (rc.canMove(dir)) {
            rc.move(dir);
            return true;
        } else return false;
    }
    */

    static int[][] map 

    static Direction destinationMoveFinder(MapLocation start, MapLocation end) {
        // run dijkstras with edge weight 1/passability


        // path 
    }
}
