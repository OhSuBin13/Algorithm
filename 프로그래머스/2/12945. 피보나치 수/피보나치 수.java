class Solution {
    public int solution(int n) {
        int a = 0;
        int b = 1;
        for (int i = 0; i < n; i++) {
            int tmp = a;
            a = b;
            b = (b + tmp) % 1234567;
        }
        return a;
    }
}