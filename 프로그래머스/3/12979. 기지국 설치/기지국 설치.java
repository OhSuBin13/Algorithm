class Solution {
  public int solution(int n, int[] stations, int w) {
    int answer = 0;
    int range = 2 * w + 1;
    int start = 1;

    for (int s : stations) {
      int left = s - w;
      if (start < left) {
        int gap = left - start;
        answer += (gap + range - 1) / range;
      }
      start = s + w + 1;
    }

    if (start <= n) {
      int gap = n - start + 1;
      answer += (gap + range - 1) / range;
    }

    return answer;
  }
}