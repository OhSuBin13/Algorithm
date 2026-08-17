class Solution {
  public String solution(String m, String[] musicinfos) {
    String target = normalize(m);

    String answer = "(None)";
    int maxPlayTime = -1;

    for (String musicinInfo : musicinfos) {
      String[] info = musicinInfo.split(",");

      String start = info[0];
      String end = info[1];
      String title = info[2];
      String melody = normalize(info[3]);

      int playTime = toMinutes(end) - toMinutes(start);

      String playedMelody = makePlayedMelody(melody, playTime);

      if (playedMelody.contains(target)) {
        if (playTime > maxPlayTime) {
          maxPlayTime = playTime;
          answer = title;
        }
      }
    }

    return answer;
  }

  private int toMinutes(String time) {
    String[] parts = time.split(":");

    int hour = Integer.parseInt(parts[0]);
    int minute = Integer.parseInt(parts[1]);

    return hour * 60 + minute;
  }

  private String normalize(String melody) {
    return melody
        .replace("C#", "c")
        .replace("D#", "d")
        .replace("F#", "f")
        .replace("G#", "g")
        .replace("A#", "a");

  }

  private String makePlayedMelody(String melody, int playTime) {
    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < playTime; i++) {
      sb.append(melody.charAt(i % melody.length()));
    }

    return sb.toString();
  }

}