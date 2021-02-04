package influencemuncher;
import battlecode.common.*;

import java.util.ArrayDeque;
import java.util.ArrayList;

public class PathBuild {
    ArrayDeque<Direction> currPath;

    public boolean empty() { return currPath.isEmpty(); }
    public Direction front() { return currPath.getFirst(); }
    public Direction back() { return currPath.getLast(); }
    public void append(Direction next) { currPath.addLast(next); }
    public void prepend(Direction next) { currPath.addFirst(next); }
    public Direction popFront() { return currPath.removeFirst(); }
    public Direction popBack() { return currPath.removeLast();}

    public void setPath(ArrayList<Direction> path) {
        int n = path.size();
        for(int i=0; i<n; ++i) this.append(path.get(i));
    }
}
