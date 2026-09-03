class Solution {
  public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int start = toSeconds(h1, m1, s1);
    int end = toSeconds(h2, m2, s2);

    int answer = countUntil(end) - countUntil(start);

    if (isAlarmTime(start)) {
      answer++;
    }
    return answer;
  }

  private int toSeconds(int hour, int minute, int second) {
    return hour * 3600 + minute * 60 + second;
  }

  private int countUntil(int t) {
    int secondMinute = t * 59 / 3600;
    int secondHour = t * 719 / 43200;
    int duplicated = t / 43200;
    return secondMinute + secondHour - duplicated + 1;
  }

    private boolean isAlarmTime(int t) {
      return t % 3600 == 0;
    }
}