class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg, pos;
        int n = nums.size();

        for (int x : nums) {
            if (x >= 0)
                pos.push_back(x);
            else
                neg.push_back(x);
        }

        if (neg.empty()) {
            for (int &x : nums)
                x *= x;
            return nums;
        }

        if (pos.empty()) {
            for (int &x : nums)
                x *= x;
            reverse(nums.begin(), nums.end());
            return nums;
        }

        for (int &x : neg)
            x *= x;
        reverse(neg.begin(), neg.end());

        for (int &x : pos)
            x *= x;

        int i = 0, j = 0, id = 0;
        int p = neg.size(), m = pos.size();

        vector<int> res(n);

        while (i < p && j < m) {
            if (neg[i] <= pos[j])
                res[id++] = neg[i++];
            else
                res[id++] = pos[j++];   // fixed
        }

        while (i < p)
            res[id++] = neg[i++];

        while (j < m)
            res[id++] = pos[j++];

        return res;
    }
};