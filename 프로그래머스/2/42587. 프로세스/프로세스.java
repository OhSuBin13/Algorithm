import java.util.LinkedList;
import java.util.Queue;

class Process {
  int priority;
  int location;

  public Process(int priority, int location) {
    this.priority = priority;
    this.location = location;
  }
}

class Solution {
  public int solution(int[] priorities, int location) {
    int answer = 0;
    int targetPriority = priorities[location];
    Queue<Process> queue = new LinkedList<>();

    // Add all priorities to the queue
    for (int i = 0; i < priorities.length; i++) {
      queue.offer(new Process(priorities[i], i));
    }

    while (!queue.isEmpty()) {
      Process currentProcess = queue.poll();
      int currentPriority = currentProcess.priority;
      boolean hasHigherPriority = false;

      // Check if there is any higher priority in the queue
      for (Process process : queue) {
        if (process.priority > currentPriority) {
          hasHigherPriority = true;
          break;
        }
      }

      if (hasHigherPriority) {
        // If there is a higher priority, put the current one back to the end of the
        // queue
        queue.offer(currentProcess);
      } else {
        // If the current priority is the highest, increment the answer
        answer++;
        if (currentPriority == targetPriority && currentProcess.location == location) {
          return answer;
        }
      }
    }
    return answer;
  }
}