import java.util.Arrays;

class Solution {
    public int solution(int[] A, int[] B) {
        Arrays.sort(A);
        Arrays.sort(B);
        int answer = 0;
        int aPoint = 0;
        int bPoint = 0;
        int n = A.length;

        while (bPoint < n) {
            if (A[aPoint] < B[bPoint]) {
                answer++;
                aPoint++;
            }
            bPoint++;
        }
        return answer;
    }
}