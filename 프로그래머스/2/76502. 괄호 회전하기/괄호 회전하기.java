import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int solution(String s) {
        int answer = 0;
        int length = s.length();

        // x칸 왼쪽으로 회전한 모든 경우 검사
        for (int x = 0; x < length; x++) {
          if (isValidRotation(s, x)) {
            answer++;
          }
        }
        return answer;
    }

    private boolean isValidRotation(String s, int rotation) {
      Deque<Character> stack = new ArrayDeque<>();
      int length = s.length();

      for (int i = 0; i < length; i++) {
        // rotation 칸 왼쪽으로 회전한 문자열의 i번째 문자
        char current = s.charAt((i + rotation) % length);

        if (current == '(' || current == '[' || current == '{') {
          stack.push(current);
          continue;
        }

        // 닫는 괄호인데 대응하는 여는 괄호가 없음
        if (stack.isEmpty()) {
          return false;
        }

        char open = stack.pop();
        if (!isMatchingPair(open, current)) {
          return false;
        }
      }

      // 처리되지 않은 여는 괄호가 없어야 함
      return stack.isEmpty();
    }

    private boolean isMatchingPair(char open, char close) {
      return (open == '(' && close == ')') ||
             (open == '[' && close == ']') ||
             (open == '{' && close == '}');
    }
  }
