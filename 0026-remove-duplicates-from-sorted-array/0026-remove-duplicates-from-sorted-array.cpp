class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        int count=1;
        int j=0;
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
                count++;

            }
        }
        return count;
    }
};