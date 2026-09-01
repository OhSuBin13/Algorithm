class Solution {
    public int[] solution(long[] numbers) {
        int[] answer = new int[numbers.length];

        for (int i = 0; i < numbers.length; i++) {
            String binary = Long.toBinaryString(numbers[i]);
            String tree = padToFullBinaryTree(binary);

            answer[i] = isValid(tree, 0, tree.length() - 1, false) ? 1 : 0;
        }

        return answer;
    }

    private String padToFullBinaryTree(String binary) {
        int length = binary.length();

        int fullLength = 1;

        while (fullLength < length) {
            fullLength = fullLength * 2 + 1;
        }

        return "0".repeat(fullLength - length) + binary;
    }

    private boolean isValid(String tree, int left, int right, boolean parentIsDummy) {
        if (left > right) {
            return true;
        }

        int mid = (left + right) / 2;
        boolean currentIsDummy = tree.charAt(mid) == '0';

        if (parentIsDummy && !currentIsDummy) {
            return false;
        }

        return isValid(tree, left, mid - 1, currentIsDummy) && isValid(tree, mid + 1, right, currentIsDummy);
    }
}