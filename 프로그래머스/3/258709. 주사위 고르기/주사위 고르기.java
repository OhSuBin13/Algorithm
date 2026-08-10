import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {

    private int[][] dice;
    private int n;
    private int half;

    private long maxWins = -1;
    private int[] answer;

    public int[] solution(int[][] dice) {
        this.dice = dice;
        this.n = dice.length;
        this.half = n / 2;

        int[] selected = new int[half];

        chooseDice(0, 0, selected);

        return answer;
    }

    private void chooseDice(int start, int depth, int[] selected) {
        if (depth == half) {
            calculateWins(selected);
            return;
        }

        for (int i = start; i < n; i++) {
            selected[depth] = i;
            chooseDice(i + 1, depth + 1, selected);
        }
    }

    private void calculateWins(int[] selected) {
        boolean[] isSelected = new boolean[n];

        for (int index : selected) {
            isSelected[index] = true;
        }

        int[] aDice = new int[half];
        int[] bDice = new int[half];

        int aIndex = 0;
        int bIndex = 0;

        for (int i = 0; i < n; i++) {
            if (isSelected[i]) {
                aDice[aIndex++] = i;
            } else {
                bDice[bIndex++] = i;
            }
        }

        List<Integer> aSums = new ArrayList<>();
        List<Integer> bSums = new ArrayList<>();

        makeSums(aDice, 0, 0, aSums);
        makeSums(bDice, 0, 0, bSums);

        Collections.sort(bSums);

        long wins = 0;

        for (int aSum : aSums) {
            wins += lowerBound(bSums, aSum);
        }

        if (wins > maxWins) {
            maxWins = wins;

            answer = new int[half];

            for (int i = 0; i < half; i++) {
                answer[i] = selected[i] + 1;
            }
        }
    }

    private int lowerBound(List<Integer> list, int target) {
        int left = 0;
        int right = list.size();

        while (left < right) {
            int mid = (left + right) / 2;

            if (list.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    private void makeSums(int[] selectedDice, int depth, int sum, List<Integer> sums) {
        if (depth == selectedDice.length) {
            sums.add(sum);
            return;
        }

        int diceIndex = selectedDice[depth];

        for (int face : dice[diceIndex]) {
            makeSums(selectedDice, depth + 1, sum + face, sums);
        }
    }
}