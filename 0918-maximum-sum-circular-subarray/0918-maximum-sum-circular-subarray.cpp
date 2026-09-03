class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=nums[0];
        int A1=nums[0];
        for(int i=1; i<nums.size(); i++){
            int v1=maxsum+nums[i];
            int v2=nums[i];
            maxsum=max(v1,v2);
            A1=max(A1,maxsum);
        }

        int minsum=nums[0];
        int A2=nums[0];
        for(int i=1; i<nums.size(); i++){
            int v1=minsum+nums[i];
            int v2=nums[i];
            minsum=min(v1,v2);
            A2=min(A2,minsum);
        }
        int sumArr=0;
        for(int i=0; i<nums.size(); i++){
            sumArr=sumArr+nums[i];
        }
        int A3=sumArr-A2;
        if(A1<0){
            return A1;
        }
        return max(A3,A1);
    }
};