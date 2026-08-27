class Solution {
    public int solution(int[] cards) {
        boolean[] visited = new boolean[cards.length];

        int first = 0;
        int second = 0;

        for (int i = 0; i < cards.length; i++) {
            if (visited[i]) {
                continue;
            }

            int count = 0;
            int current = i;

            while (!visited[current]) {
                visited[current] = true;
                count++;
                current = cards[current] - 1;
            }

            if (count > first) {
                second = first;
                first = count;
            } else if (count > second) {
                second = count;
            }
        }

        return first * second;
    }
}