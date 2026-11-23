
class Solution {
public:
    int mergeSort(vector<long long>& prefix, int lower, int upper, int left, int right) {

        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;

        int count = mergeSort(prefix, lower, upper, left, mid);
        count += mergeSort(prefix, lower, upper, mid + 1, right);

        int j = mid + 1;
        int k = mid + 1;

        for (int i = left; i <= mid; i++) {

            while (j <= right && prefix[j] - prefix[i] < lower) {
                j++;
            }

            while (k <= right && prefix[k] - prefix[i] <= upper) {
                k++;
            }

            count += k - j;
        }

        vector<long long> temp;

        int i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (prefix[i] <= prefix[j]) {
                temp.push_back(prefix[i++]);
            }
            else {
                temp.push_back(prefix[j++]);
            }
        }

        while (i <= mid) {
            temp.push_back(prefix[i++]);
        }

        while (j <= right) {
            temp.push_back(prefix[j++]);
        }

        for (int i = left; i <= right; i++) {
            prefix[i] = temp[i - left];
        }

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {

        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(prefix, lower, upper, 0, n);
    }
};
