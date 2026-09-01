class Solution {
public:
    int getMaxCount(unordered_map<char, int>& f) {
        int maxcount = 0;

        for (auto it : f) {
            maxcount = max(maxcount, it.second);
        }

        return maxcount;
    }

    int characterReplacement(string s, int k) {
        int low = 0;
        int res = 0;

        unordered_map<char, int> f;

        for (int high = 0; high < s.size(); high++) {
            f[s[high]]++;

            int len = high - low + 1;
            int maxcount = getMaxCount(f);

            while (len - maxcount > k) {
                f[s[low]]--;
                low++;

                len = high - low + 1;
                maxcount = getMaxCount(f);
            }

            res = max(res, high - low + 1);
        }

        return res;
    }
};