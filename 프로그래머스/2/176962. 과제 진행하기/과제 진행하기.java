
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Deque;
import java.util.List;

class Solution {

  static class Plan {
    String name;
    int start;
    int playTime;

    Plan(String name, int start, int playTime) {
      this.name = name;
      this.start = start;
      this.playTime = playTime;
    }
  }

  public String[] solution(String[][] plans) {
    List<Plan> planList = new ArrayList<>();

    for (String[] plan : plans) {
      String name = plan[0];
      int start = toMinute(plan[1]);
      int playTime = Integer.parseInt(plan[2]);

      planList.add(new Plan(name, start, playTime));
    }

    planList.sort(Comparator.comparingInt(p -> p.start));

    List<String> answer = new ArrayList<>();
    Deque<Plan> stack = new ArrayDeque<>();

    for (int i = 0; i < planList.size() - 1; i++) {
      Plan current = planList.get(i);
      Plan next = planList.get(i + 1);

      int availableTime = next.start - current.start;

      if (current.playTime <= availableTime) {
        answer.add(current.name);

        int remainTime = availableTime - current.playTime;

        while (remainTime > 0 && !stack.isEmpty()) {
          Plan paused = stack.pop();

          if (paused.playTime <= remainTime) {
            remainTime -= paused.playTime;
            answer.add(paused.name);
          } else {
            paused.playTime -= remainTime;
            stack.push(paused);
            remainTime = 0;
          }
        }
      } else {
        current.playTime -= availableTime;
        stack.push(current);
      }
    }

    Plan last = planList.get(planList.size() - 1);
    answer.add(last.name);

    while (!stack.isEmpty()) {
      answer.add(stack.pop().name);
    }

    return answer.toArray(String[]::new);
  }

  private int toMinute(String time) {
    String[] split = time.split(":");

    int hour = Integer.parseInt(split[0]);
    int minute = Integer.parseInt(split[1]);

    return hour * 60 + minute;
  }
}