import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int solution(String s) {
        Deque<Character> stack = new ArrayDeque<>();

        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() && stack.peekLast() == c) {
                stack.pollLast();
            } else {
                stack.offerLast(c);
            }
        }

        return stack.isEmpty() ? 1 : 0;
    }
}