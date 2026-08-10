
import java.util.ArrayList;
import java.util.List;

class Solution {

    static class Group {
        int diamond;
        int iron;
        int stone;

        Group(int diamond, int iron, int stone) {
            this.diamond = diamond;
            this.iron = iron;
            this.stone = stone;
        }

        int hardness() {
            return diamond * 25 + iron * 5 + stone;
        }
    }

    public int solution(int[] picks, String[] minerals) {
        int totalPicks = picks[0] + picks[1] + picks[2];

        int maxMinerals = Math.min(minerals.length, totalPicks * 5);

        List<Group> groups = new ArrayList<>();

        for (int i = 0; i < maxMinerals; i += 5) {
            int diamond = 0;
            int iron = 0;
            int stone = 0;

            for (int j = i; j < Math.min(i + 5, maxMinerals); j++) {
                switch (minerals[j]) {
                    case "diamond":
                        diamond++;
                        break;
                    case "iron":
                        iron++;
                        break;
                    case "stone":
                        stone++;
                        break;
                }
            }

            groups.add(new Group(diamond, iron, stone));
        }

        groups.sort((a, b) -> b.hardness() - a.hardness());

        int answer = 0;
        int index = 0;

        for (int i = 0; i < picks[0] && index < groups.size(); i++) {
            Group group = groups.get(index++);
            answer += group.diamond;
            answer += group.iron;
            answer += group.stone;
        }

        for (int i = 0; i < picks[1] && index < groups.size(); i++) {
            Group group = groups.get(index++);
            answer += group.diamond * 5;
            answer += group.iron;
            answer += group.stone;
        }

        for (int i = 0; i < picks[2] && index < groups.size(); i++) {
            Group group = groups.get(index++);
            answer += group.diamond * 25;
            answer += group.iron * 5;
            answer += group.stone;
        }

        return answer;
    }
}