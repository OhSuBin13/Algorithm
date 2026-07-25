class Solution {
    public String solution(String play_time, String adv_time, String[] logs) {
        int playSeconds = toSeconds(play_time);
        int advSeconds = toSeconds(adv_time);

        long[] viewers = new long[playSeconds + 1];

        for (String log : logs) {
            String[] times = log.split("-");

            int start = toSeconds(times[0]);
            int end = toSeconds(times[1]);

            viewers[start]++;
            viewers[end]--;
        }

        for (int second = 1; second <= playSeconds; second++) {
            viewers[second] += viewers[second - 1];
        }

        for (int second = 1; second <= playSeconds; second++) {
            viewers[second] += viewers[second - 1];
        }

        long maxWatchTime = viewers[advSeconds - 1];
        int bestStart = 0;

        for (int start = 1; start + advSeconds <= playSeconds; start++) {
            int end = start + advSeconds;

            long watchTime = viewers[end - 1] - viewers[start - 1];

            if (watchTime > maxWatchTime) {
                maxWatchTime = watchTime;
                bestStart = start;
            }
        }

        return toTimeString(bestStart);
    }

    private int toSeconds(String time) {
        String[] parts = time.split(":");

        int hours = Integer.parseInt(parts[0]);
        int minutes = Integer.parseInt(parts[1]);
        int seconds = Integer.parseInt(parts[2]);

        return hours * 3600 + minutes * 60 + seconds;
    }

    private String toTimeString(int seconds) {
        int hours = seconds / 3600;
        seconds %= 3600;

        int minutes = seconds / 60;
        int remainingSeconds = seconds % 60;

        return String.format("%02d:%02d:%02d", hours, minutes, remainingSeconds);
    }
}