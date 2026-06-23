class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            int start=nums[i];
            int more=target-start;

            if(mpp.find(more)!=mpp.end()){
                return {i,mpp[more]};
            }
            mpp[start]=i;

        }
        return {-1, -1};

    }
};