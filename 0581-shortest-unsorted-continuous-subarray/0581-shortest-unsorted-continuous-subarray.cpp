class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        // Find first unsorted position from left
        while (left < n - 1 && nums[left] <= nums[left + 1]) {
            left++;
        }

        // Array is already sorted
        if (left == n - 1) {
            return 0;
        }

        // Find first unsorted position from right
        while (right > 0 && nums[right - 1] <= nums[right]) {
            right--;
        }

        // Find minimum and maximum in the unsorted part
        int mn = nums[left];
        int mx = nums[left];

        for (int i = left; i <= right; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        // Expand left boundary
        while (left > 0 && nums[left - 1] > mn) {
            left--;
        }

        // Expand right boundary
        while (right < n - 1 && nums[right + 1] < mx) {
            right++;
        }

        return right - left + 1;
    }
};