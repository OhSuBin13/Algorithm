class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;

        int start = 1;
        int end = 1;

        for(int station : stations) {
            end = station - w;
            answer += (end - start + 2 * w) / (2 * w + 1);
            start = station + w + 1;
        }

        answer += (n - start + 1 + 2 * w) / (2 * w + 1);

        return answer;
    }
}
