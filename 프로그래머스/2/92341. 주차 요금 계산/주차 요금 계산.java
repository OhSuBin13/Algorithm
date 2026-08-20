import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

class Solution {

  private static final int END_OF_DAY = 23 * 60 + 59;

  public int[] solution(int[] fees, String[] records) {
    Map<String, Integer> entryTimes = new HashMap<>();
    Map<String, Integer> totalTimes = new TreeMap<>();

    for (String record : records) {
      String[] parts = record.split(" ");

      int time = toMinutes(parts[0]);
      String carNumber = parts[1];
      String action = parts[2];

      if (action.equals("IN")) {
        entryTimes.put(carNumber, time);
      } else {
        int entryTime = entryTimes.remove(carNumber);
        int parkingTime = time - entryTime;

        totalTimes.merge(carNumber, parkingTime, Integer::sum);
      }
    }

    for (Map.Entry<String, Integer> entry : entryTimes.entrySet()) {
      String carNumber = entry.getKey();
      int entryTime = entry.getValue();
      int parkingTime = END_OF_DAY - entryTime;

      totalTimes.merge(carNumber, parkingTime, Integer::sum);
    }

    int[] answer = new int[totalTimes.size()];
    int index = 0;

    for (int totalTime : totalTimes.values()) {
      answer[index++] = calculateFee(totalTime, fees);
    }

    return answer;
  }

  private int calculateFee(int totalTime, int[] fees) {
    int basicTime = fees[0];
    int basicFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];

    if (totalTime <= basicTime) {
      return basicFee;
    }

    int excessTime = totalTime - basicTime;

    int units = (excessTime + unitTime - 1) / unitTime;

    return basicFee + units * unitFee;
  }

  private int toMinutes(String time) {
    String[] parts = time.split(":");

    int hour = Integer.parseInt(parts[0]);
    int minute = Integer.parseInt(parts[1]);

    return hour * 60 + minute;
  }
}