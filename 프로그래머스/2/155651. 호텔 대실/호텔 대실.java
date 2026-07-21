import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int solution(String[][] book_time) {
        int[][] bookings = new int[book_time.length][2];

        for (int i = 0; i < book_time.length; i++) {
          bookings[i][0] = toMinutes(book_time[i][0]);
          bookings[i][1] = toMinutes(book_time[i][1]) + 10;
        }

        Arrays.sort(bookings, (a, b) -> Integer.compare(a[0], b[0]));

        PriorityQueue<Integer> availableTimes = new PriorityQueue<>();

        int maxRooms = 0;

        for (int[] booking : bookings) {
          int startTime = booking[0];
          int availableTime = booking[1];

          while (!availableTimes.isEmpty()
              && availableTimes.peek() <= startTime) {
            availableTimes.poll();
          }

          availableTimes.offer(availableTime);

          maxRooms = Math.max(maxRooms, availableTimes.size());
        }

        return maxRooms;
    }

    private int toMinutes(String time) {
      String[] parts = time.split(":");

      int hour = Integer.parseInt(parts[0]);
      int minute = Integer.parseInt(parts[1]);

      return hour * 60 + minute;
    }
}