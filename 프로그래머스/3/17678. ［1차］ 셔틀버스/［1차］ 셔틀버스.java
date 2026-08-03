import java.util.Arrays;

class Solution {
  public String solution(int n, int t, int m, String[] timetable) {
    int[] crewTimes = new int[timetable.length];

    for (int i = 0; i < timetable.length; i++) {
      crewTimes[i] = toMinutes(timetable[i]);
    }

    Arrays.sort(crewTimes);

    int crewIndex = 0;
    int answer = 0;

    for (int bus = 0; bus < n; bus++) {
      int busTime = 9 * 60 + bus * t;
      int boarded = 0;
      int lastBoardedTime = -1;

      while (crewIndex < crewTimes.length
          && crewTimes[crewIndex] <= busTime
          && boarded < m) {
        lastBoardedTime = crewTimes[crewIndex];
        crewIndex++;
        boarded++;
      }

      if (bus == n - 1) {
        if (boarded < m) {
          answer = busTime;
        } else {
          answer = lastBoardedTime - 1;
        }
      }
    }

    return toTimeString(answer);
  }

  private int toMinutes(String time) {
    int hour = Integer.parseInt(time.substring(0, 2));
    int minute = Integer.parseInt(time.substring(3, 5));

    return hour * 60 + minute;
  }

  private String toTimeString(int minutes) {
    int hour = minutes / 60;
    int minute = minutes % 60;

    return String.format("%02d:%02d", hour, minute);
  }
}