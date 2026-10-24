
import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
    public int solution(int[][] jobs) {
        int n = jobs.length;

        // {작업 번호, 요청 시각, 소요 시간}
        int[][] list = new int[n][3];
        for (int i = 0; i < n; i++) {
            list[i] = new int[]{i, jobs[i][0], jobs[i][1]};
        }

        // 요청 시간 오름차 순 (같으면 번호순)
        Arrays.sort(list, (x, y) -> x[1] != y[1] ? Integer.compare(x[1], y[1])
            : Integer.compare(x[0], y[0]));
        
        // 우선순위 : 소요시간 -> 요청 시각 -> 작업 번호
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> {
            if (x[2] != y[2]) return Integer.compare(x[2], y[2]);
            if (x[1] != y[1]) return Integer.compare(x[1], y[1]);
            return Integer.compare(x[0], y[0]);
        });

        int time = 0; // 현재 시각
        int idx = 0; // 다음에 대기 큐에 넣을 작업 위치
        int done = 0; // 완료한 작업 수
        int total = 0; // 반환 시간 합

        while (done < n) {
            while (idx < n && list[idx][1] <= time) {
                pq.offer(list[idx++]);
            }

            if (pq.isEmpty()) {
                // 하드디스크가 쉬는 구간 : 다음 요청 시각으로 이동
                time = list[idx][1];
                continue;
            }

            int[] job = pq.poll();
            time += job[2];
            total += time - job[1];
            done++;
        }

        return (int) (total / n);
    }
}