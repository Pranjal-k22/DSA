class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        // If there are 2 or fewer elements, all are allowed
        if (n <= 2) {
            return n;
        }

        int k = 2;

        for (int i = 2; i < n; i++) {
            
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};