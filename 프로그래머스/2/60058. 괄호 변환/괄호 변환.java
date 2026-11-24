class Solution {
    public String solution(String p) {
        return convert(p);
    }

    private String convert(String w) {
        if (w.isEmpty())
            return "";

        int balance = 0;
        int idx = 0;
        boolean isCorrect = true;
        for (; idx < w.length(); idx++) {
            balance += (w.charAt(idx) == '(') ? 1 : -1;
            if (balance < 0)
                isCorrect = false;
            if (balance == 0)
                break;
        }
        String u = w.substring(0, idx + 1);
        String v = w.substring(idx + 1);

        if (isCorrect) {
            return u + convert(v);
        }

        StringBuilder sb = new StringBuilder();
        sb.append('(');
        sb.append(convert(v));
        sb.append(')');
        for (int i = 1; i < u.length() - 1; i++) {
            sb.append(u.charAt(i) == '(' ? ')' : '(');
        }
        return sb.toString();
    }
}