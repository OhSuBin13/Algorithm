class Solution {
    public String solution(int n, int t, int m, int p) {
        StringBuilder sequence = new StringBuilder();

        int number = 0;

        while (sequence.length() < t * m) {
            sequence.append(
                    Integer.toString(number, n).toUpperCase());
            number++;
        }

        StringBuilder answer = new StringBuilder();

        for (int i = 0; i < t; i++) {
            int index = (p - 1) + i * m;
            answer.append(sequence.charAt(index));
        }

        return answer.toString();
    }
}