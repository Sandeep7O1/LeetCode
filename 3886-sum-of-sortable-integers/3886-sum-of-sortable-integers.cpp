
class Solution {
public:
    void computeLPS(const vector<int>& pattern, vector<int>& lps) {
        int m = pattern.size();
        if (m == 0) return;

        int len = 0;
        for (int i = 1; i < m;) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }

    bool search(const vector<int>& pat, const vector<int>& txt) {
        int m = pat.size(), n = txt.size();
        if (m == 0) return true;
        if (m > n) return false;

        vector<int> lps(m, 0);
        computeLPS(pat, lps);

        int i = 0, j = 0;
        while (i < n) {
            if (pat[j] == txt[i]) {
                ++i;
                ++j;
            }

            if (j == m) return true;

            if (i < n && pat[j] != txt[i]) {
                if (j > 0) {
                    j = lps[j - 1];
                } else {
                    ++i;
                }
            }
        }
        return false;
    }

    bool isRotationPossible(const vector<int>& a, const vector<int>& b) {
        if (a.size() != b.size()) return false;

        vector<int> doubled = b;
        doubled.insert(doubled.end(), b.begin(), b.end());

        return search(a, doubled);
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int start = 0; start < n; start += k) {
                vector<int> a(nums.begin() + start,
                              nums.begin() + start + k);
                vector<int> b(sorted.begin() + start,
                              sorted.begin() + start + k);

                if (!isRotationPossible(a, b)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};
