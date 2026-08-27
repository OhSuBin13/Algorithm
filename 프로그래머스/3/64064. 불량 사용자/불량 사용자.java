import java.util.HashSet;
import java.util.Set;

class Solution {
    private Set<Integer> cases = new HashSet<>();

    public int solution(String[] user_id, String[] banned_id) {
        dfs(user_id, banned_id, 0, 0);

        return cases.size();
    }

    private void dfs(
            String[] userId,
            String[] bannedId,
            int bannedIndex,
            int selected) {
        if (bannedIndex == bannedId.length) {
            cases.add(selected);
            return;
        }

        for (int i = 0; i < userId.length; i++) {
            if ((selected & (1 << i)) != 0) {
                continue;
            }

            if (!matches(userId[i], bannedId[bannedIndex])) {
                continue;
            }

            dfs(userId, bannedId, bannedIndex + 1, selected | (1 << i));
        }
    }

    private boolean matches(String userId, String bannedId) {
        if (userId.length() != bannedId.length()) {
            return false;
        }

        for (int i = 0; i < userId.length(); i++) {
            char bannedChar = bannedId.charAt(i);

            if (bannedChar == '*') {
                continue;
            }

            if (userId.charAt(i) != bannedChar) {
                return false;
            }
        }
        return true;
    }
}