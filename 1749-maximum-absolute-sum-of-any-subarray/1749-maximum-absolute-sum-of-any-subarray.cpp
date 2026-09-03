class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum=nums[0];
        int maxres=nums[0];

        for(int i=1;i<nums.size(); i++){
            int v1=maxsum+nums[i];
            int v2=nums[i];
            maxsum=max(v1,v2);
            maxres=max(maxres,maxsum);
        }
        int absmax=abs(maxres);

        int minsum=nums[0];
        int minres=nums[0];
        for(int i=1; i<nums.size(); i++){
            int v1=minsum+nums[i];
            int v2=nums[i];
            minsum=min(v1,v2);
            minres=min(minres,minsum);
        }
        int absmin=abs(minres);
        int ans=max(absmin,absmax);
        return ans;
    }
};