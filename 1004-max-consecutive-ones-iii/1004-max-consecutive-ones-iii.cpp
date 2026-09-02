class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0;
        int high=0;
        int cnt=0;
        int res=0;
        for(high=0; high<nums.size(); high++){
            if(nums[high]==0){
                cnt++;
            }
            while(cnt>k){
                if(nums[low]==0){
                    cnt--;
                }
                low++;
            }
            int len=high-low+1;
            res=max(res,len);
        }
        return res;
    }
};