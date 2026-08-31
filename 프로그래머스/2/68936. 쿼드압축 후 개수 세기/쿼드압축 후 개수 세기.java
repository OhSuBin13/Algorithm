class Solution {
    private int[] answer = new int[2];

    public int[] solution(int[][] arr) {
        compress(arr, 0, 0, arr.length);
        return answer;
    }

    private void compress(int[][] arr, int row, int col, int size) {
        if (isSame(arr, row, col, size)) {
            answer[arr[row][col]]++;
            return;
        }
        int half = size / 2;

        compress(arr, row, col, half);
        compress(arr, row, col + half, half);
        compress(arr, row + half, col, half);
        compress(arr, row + half, col + half, half);
    }

    private boolean isSame(int[][] arr, int row, int col, int size) {
        int value = arr[row][col];

        for (int r = row; r < row + size; r++) {
            for (int c = col; c < col + size; c++) {
                if (arr[r][c] != value) {
                    return false;
                }
            }
        }
        return true;
    }
}