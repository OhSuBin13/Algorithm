import java.util.HashSet;
import java.util.Set;

class Solution {
    private Set<Integer> set = new HashSet<>();
    private boolean[] visited;

    public int solution(String numbers) {
        visited = new boolean[numbers.length()];
        dfs(numbers, "");

        int count = 0;
        for (int num : set) {
            if (isPrime(num))
                count++;
        }

        return count;
    }

    private void dfs(String numbers, String current) {
        if (!current.isEmpty()) {
            set.add(Integer.parseInt(current));
        }

        for (int i = 0; i < numbers.length(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(numbers, current + numbers.charAt(i));
                visited[i] = false;
            }
        }
    }

    private boolean isPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}