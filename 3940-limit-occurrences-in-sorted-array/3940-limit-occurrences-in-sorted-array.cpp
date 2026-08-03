class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> res;

        for (int x : nums) {
            if (freq[x] < k) {
                res.push_back(x);
                freq[x]++;
            }
        }

        return res;
    }
};