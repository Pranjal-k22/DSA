class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<pair<int, int>> v;

        // {value, original index}
        for(int k = 0; k < n; k++) {
            v.push_back({nums[k], k});
        }

        sort(v.begin(), v.end());

        int i = 0;
        int j = n - 1;

        while(i < j) {

            int sum = v[i].first + v[j].first;

            if(sum == target) {
                return {v[i].second, v[j].second};
            }
            else if(sum > target) {
                j--;
            }
            else {
                i++;
            }
        }

        return {-1, -1};
    }
};