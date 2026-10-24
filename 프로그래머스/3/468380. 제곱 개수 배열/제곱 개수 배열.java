class Solution {
    int n;
    long[] a, S, E, B;
    public long[] solution(int[] arr, long l, long r) {
        n = arr.length;
        a = new long[n];
        S = new long[n];
        E = new long[n];
        B = new long[n];

        long pos = 1, sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = arr[i];
            S[i] = pos;
            E[i] = pos + a[i] - 1;
            B[i] = sum;
            pos += a[i];
            sum += a[i] * a[i];
        }
        long M = pos - 1; // brr 길이

        long K = P(r) - P(l - 1);
        long L = r - l + 1;
        long maxS = M - L + 1; // 가능한 마지막 시작 위치

        long C = 0;
        int i = 0, j = findBlock(L); // s = 1일 때 끝 위치 L이 속한 블록
        long cur = 1;

        while (cur <= maxS) {
            long segEnd = Math.min(E[i], Math.min(E[j] - L + 1, maxS));

            long val0 = B[j] + (cur + L - S[j]) * a[j]
                - B[i] - (cur - S[i]) * a[i];

            long d = a[j] - a[i];

            if (d == 0) {
                if (val0 == K) C += segEnd - cur + 1;
            } else {
                long diff = K - val0;
                if (diff % d == 0) {
                    long t = diff / d;
                    if (t >= 0 && t <= segEnd - cur) C++;
                }
            }

            cur = segEnd + 1;
            while (i < n && E[i] < cur) i++;
            while (j < n && E[j] < cur + L - 1) j++;
        }
        return new long[]{K, C};
    }

    // brr[1..x]의 합
    long P(long x) {
        if (x <= 0) return 0;
        int i = findBlock(x);
        return B[i] + (x - S[i] + 1) * a[i];
    }

    // S[i] <= x 인 가장 큰 i
    int findBlock(long x) {
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) >>> 1;
            if (S[mid] <= x) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
}