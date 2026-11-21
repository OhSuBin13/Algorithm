import java.util.ArrayDeque;
import java.util.Deque;

class Solution {

  public long solution(String expression) {
    long answer = 0;
    // Generate all permutations of operator priorities
    char[][] permutations = {
        { '+', '-', '*' },
        { '+', '*', '-' },
        { '-', '+', '*' },
        { '-', '*', '+' },
        { '*', '+', '-' },
        { '*', '-', '+' }
    };
    for (char[] perm : permutations) {
      answer = Math.max(answer, calculate(expression, perm));
    }
    return answer;
  }

  private long calculate(String expression, char[] operatorPriority) {
    // Implement the calculation logic based on the operator priority
    Deque<Long> numbers = new ArrayDeque<>();
    Deque<Character> operators = new ArrayDeque<>();

    for (int i = 0; i < expression.length(); i++) {
      char ch = expression.charAt(i);
      if (Character.isDigit(ch)) {
        int j = i;
        while (j < expression.length() && Character.isDigit(expression.charAt(j))) {
          j++;
        }
        long number = Long.parseLong(expression.substring(i, j));
        numbers.push(number);
        i = j - 1;
      } else {
        while (!operators.isEmpty()
            && getPriority(operators.peek(), operatorPriority) >= getPriority(ch, operatorPriority)) {
          long b = numbers.pop();
          long a = numbers.pop();
          char op = operators.pop();
          numbers.push(applyOperation(a, b, op));
        }
        operators.push(ch);
      }
    }

    while (!operators.isEmpty()) {
      long b = numbers.pop();
      long a = numbers.pop();
      char op = operators.pop();
      numbers.push(applyOperation(a, b, op));
    }

    return Math.abs(numbers.pop());
  }

  private int getPriority(char ch, char[] operatorPriority) {
    for (int i = 0; i < operatorPriority.length; i++) {
      if (operatorPriority[i] == ch) {
        return i;
      }
    }
    return -1;
  }

  private Long applyOperation(long a, long b, char op) {
    switch (op) {
      case '+':
        return a + b;
      case '-':
        return a - b;
      case '*':
        return a * b;
      default:
        throw new IllegalArgumentException("Invalid operator: " + op);
    }
  }
}