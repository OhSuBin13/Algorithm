class Solution {
  public int solution(String word) {
    int answer = 0;

    int[] weight = { 781, 156, 31, 6, 1 }; // 각 자리수의 가중치

    for (int i = 0; i < word.length(); i++) {
      int index = "AEIOU".indexOf(word.charAt(i));
      answer += index * weight[i] + 1; // 가중치 곱하고 1을 더함
    }
    return answer;
  }
}