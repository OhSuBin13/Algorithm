import java.util.HashSet;
import java.util.Set;

class Solution {
    public int solution(int[] elements) {
        int n = elements.length;
        Set<Integer> sums = new HashSet<>();

        // 부분 수열의 시작 위치
        for (int start = 0; start < n; start++) {
          int sum = 0;

          // 부분 수열의 길이
          for (int length = 0; length < n; length++) {
            int index = (start + length) % n; // 원형 배열 처리
            sum += elements[index];
            sums.add(sum);
          }
        }
        return sums.size();
    }
}