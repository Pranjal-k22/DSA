class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int mid=0;
        int low=0;
        int high=n-1;
        while(high>=mid){
            if(nums[mid]==2){
                int temp=nums[high];
                nums[high]=nums[mid];
                nums[mid]=temp;
                high--;
            }
            else if(nums[mid]==0){
                int temp=nums[low];
                nums[low]=nums[mid];
                nums[mid]=temp;
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
        }
        

    }
};