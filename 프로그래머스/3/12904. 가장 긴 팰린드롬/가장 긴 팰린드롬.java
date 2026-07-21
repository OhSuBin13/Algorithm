class Solution
{
    public int solution(String s)
    {
        int answer = 1;

        for (int center = 0; center < s.length(); center++) {
          answer = Math.max(answer, expand(s, center, center));

          answer = Math.max(answer, expand(s, center, center + 1));
        }
        return answer;
    }

    private int expand(String s, int left, int right) {
      while (left >= 0 
        && right < s.length()
        && s.charAt(left) == s.charAt(right)) {
          left--;
          right++;
        }

        return right - left - 1;
    }
}