class Solution {
    public String solution(int n) {
        String[] digits = {"1", "2", "4"};
        StringBuilder sb = new StringBuilder();

        while(n > 0) {
            n -= 1;
            sb.append(digits[n % 3]);
            n /= 3;
        }
        return sb.reverse().toString();
    }
}