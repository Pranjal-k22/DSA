class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestend=nums[0];
        int ans=nums[0];
        for(int i=1; i<nums.size(); i++ ){
            int s1=bestend+nums[i];
            int s2=nums[i];
            bestend=max(s1,s2);
            ans=max(ans,bestend);
        }
        return ans;
    }
};