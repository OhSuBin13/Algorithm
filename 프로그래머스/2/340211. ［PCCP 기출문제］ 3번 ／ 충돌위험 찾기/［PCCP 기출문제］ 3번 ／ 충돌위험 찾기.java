import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int solution(int[][] points, int[][] routes) {
        List<Map<Integer, Integer>> timeline = new ArrayList<>();

        for (int[] route : routes) {
            List<int[]> robotPath = createPath(points, route);

            for (int time = 0; time < robotPath.size(); time++) {
                while (timeline.size() <= time) {
                    timeline.add(new HashMap<>());
                }

                int[] position = robotPath.get(time);
                int coordinateKey = encode(position[0], position[1]);

                Map<Integer, Integer> positionCount = timeline.get(time);
                positionCount.put(coordinateKey, positionCount.getOrDefault(coordinateKey, 0) + 1);
            }
        }

        int answer = 0;

        for (Map<Integer, Integer> positionCount : timeline) {
            for (int count : positionCount.values()) {
                if (count >= 2) {
                    answer++;
                }
            }
        }

        return answer;
    }

    private int encode(int row, int col) {
        return row * 101 + col;
    }

    private List<int[]> createPath(int[][] points, int[] route) {
        List<int[]> path = new ArrayList<>();

        int startPointNumber = route[0];
        int currentRow = points[startPointNumber - 1][0];
        int currentCol = points[startPointNumber - 1][1];

        path.add(new int[] { currentRow, currentCol });

        for (int i = 1; i < route.length; i++) {
            int nextPointer = route[i];
            int targetRow = points[nextPointer - 1][0];
            int targetCol = points[nextPointer - 1][1];

            while (currentRow != targetRow) {
                currentRow += currentRow < targetRow ? 1 : -1;
                path.add(new int[] { currentRow, currentCol });
            }

            while (currentCol != targetCol) {
                currentCol += currentCol < targetCol ? 1 : -1;
                path.add(new int[] { currentRow, currentCol });
            }
        }
        return path;
    }
}