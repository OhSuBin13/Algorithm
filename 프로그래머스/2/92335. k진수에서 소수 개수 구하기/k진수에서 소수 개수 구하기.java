class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        String baseK = to_base(n, k);
        String[] parts = baseK.split("0");
        for (String part : parts) {
            if (!part.isEmpty()) {
                long num = Long.parseLong(part);
                if (isPrime(num)) {
                    answer++;
                }
            }
        }
        return answer;
    }

    private String to_base(int n, int k) {
        String result = "";
        while (n > 0) {
            result = (n % k) + result;
            n /= k;
        }

        return result;
    }

    private boolean isPrime(long num) {
        if (num < 2) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        for (long i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}