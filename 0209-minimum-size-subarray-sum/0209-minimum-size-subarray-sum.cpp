class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0, high=0;
        int res=INT_MAX;
        int sum=0;
        while(high<nums.size()){
            sum=sum+nums[high];
            while(sum>=target){
                int len=high-low+1;
                res=min(res,len);
                sum=sum-nums[low];
                low++;
            }
            high++;
        }
        if(res>nums.size()){
            return 0;
        }
        return res;
    }
};