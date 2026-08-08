class Solution {
  public int solution(int[] players, int m, int k) {
    int answer = 0;
    int time[] = new int[24];

    for (int i = 0; i < players.length; i++) {
      if (players[i] / m > time[i]) {
        int add = players[i] / m - time[i];
        answer += add;
        for (int j = i; j < players.length && j < i + k; j++) {
          time[j] += add;
        }
      }
    }
    return answer;
  }
}