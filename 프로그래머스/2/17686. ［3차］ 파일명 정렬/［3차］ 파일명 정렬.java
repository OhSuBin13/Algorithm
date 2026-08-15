import java.util.Arrays;

class Solution {
    public String[] solution(String[] files) {
        Arrays.sort(files, (a, b) -> {
            FileInfo fileA = parse(a);
            FileInfo fileB = parse(b);

            int headCompare = fileA.head.compareToIgnoreCase(fileB.head);

            if (headCompare != 0) {
                return headCompare;
            }

            return Integer.compare(fileA.number, fileB.number);
        });

        return files;
    }

    private FileInfo parse(String file) {
        int index = 0;

        while (index < file.length() && !Character.isDigit(file.charAt(index))) {
            index++;
        }

        String head = file.substring(0, index);

        int numberStart = index;

        while (index < file.length() && Character.isDigit(file.charAt(index)) && index - numberStart < 5) {
            index++;
        }

        int number = Integer.parseInt(file.substring(numberStart, index));

        return new FileInfo(head, number);
    }

    private static class FileInfo {
        String head;
        int number;

        FileInfo(String head, int number) {
            this.head = head;
            this.number = number;
        }
    }
}