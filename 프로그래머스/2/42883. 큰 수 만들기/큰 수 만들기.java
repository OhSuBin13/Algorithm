class Solution {
    public String solution(String number, int k) {
        char[] stack = new char[number.length()];
        int top = 0;

        for (int i = 0; i < number.length(); i++) {
            char c = number.charAt(i);

            while (k > 0 && top > 0 && stack[top - 1] < c) {
                top--;
                k--;
            }
            stack[top++] = c;
        }

        return new String(stack, 0, top - k);
    }
}
