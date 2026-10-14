import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class User {
    String uid;
    String nickname;

    public User(String uid, String nickname) {
        this.uid = uid;
        this.nickname = nickname;
    }
}

class Solution {
    public String[] solution(String[] record) {
        List<String> answerList = new ArrayList<>();
        Map<String, User> userMap = new HashMap<>();
        for (String r : record) {
            String[] parts = r.split(" ");
            String action = parts[0];
            String uid = parts[1];
            switch (action) {
                case "Enter":
                    String nickname = parts[2];
                    userMap.put(uid, new User(uid, nickname));
                    break;
                case "Leave":
                    // No action needed for Leave, just keep the user in the map
                    break;
                case "Change":
                    String newNickname = parts[2];
                    userMap.put(uid, new User(uid, newNickname));
                    break;
            }
        }

        for (String r : record) {
            String[] parts = r.split(" ");
            String action = parts[0];
            String uid = parts[1];

            switch (action) {
                case "Enter":
                    answerList.add(userMap.get(uid).nickname + "님이 들어왔습니다.");
                    break;
                case "Leave":
                    answerList.add(userMap.get(uid).nickname + "님이 나갔습니다.");
                    break;
                case "Change":
                    // No output for Change action
                    break;
            }
        }
        String[] answer = answerList.toArray(new String[0]);
        return answer;
    }
}