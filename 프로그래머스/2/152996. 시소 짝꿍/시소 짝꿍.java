class Solution {
    public long solution(int[] weights) {
        long answer = 0;
        long [] count = new long[1001];

        // 몸무게별 인원 수
        for (int weight : weights) {
          count[weight]++;
        }

        for (int weight = 100; weight <= 1000; weight++) {
          if (count[weight] == 0) continue;

          // 1. 몸무게가 같은 경우
          answer += count[weight] * (count[weight] - 1) / 2;

          // 2. 몸무게 비율이 2 : 3인 경우
          // weight : partner = 2 : 3
          if (weight * 3 % 2 == 0) {
            int partner = weight * 3 / 2;

            if (partner <= 1000) {
              answer += count[weight] * count[partner];
            }
          }

          // 3. 몸무게 비율이 1 : 2인 경우
          // weight : partner = 1 : 2
          int partner = weight * 2;
          if (partner <= 1000) {
            answer += count[weight] * count[partner];
          }

          // 4. 몸무게 비율이 3 : 4인 경우
          // weight : partner = 3 : 4
          if (weight * 4 % 3 == 0) {
            partner = weight * 4 / 3;

            if (partner <= 1000) {
              answer += count[weight] * count[partner];
            }
          }
        }
        return answer;
    }
}