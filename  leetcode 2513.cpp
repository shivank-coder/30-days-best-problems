class Solution {
public:
    long long gcd(long long a, long long b) {
        return ((!b) ? a : (gcd(b, a % b)));
    }

    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long l = 1, h = (long long)(2 * (1e9) + 1);
        long long ans = h;
        unsigned long long lcm =
            (d1 / gcd(d1, d2)) *
            d2; // Tricky might get overflowed for (d1*d2)/gcd(d1,d2)
        while (l <= h) {
            long long m = l + (h - l) / 2;
            long long d_1 = m / d1 - m / lcm, d_2 = m / d2 - m / lcm,
                      d_1_2 = m / lcm;
            long long need = m - d_1_2 - ((d_1 > u2) ? (d_1 - u2) : 0) -
                             ((d_2 > u1) ? (d_2 - u1) : 0);
            if (need >= (u1 + u2)) {
                ans = m;
                h = m - 1;
            } else
                l = m + 1;
        }
        return ans;
    }
};