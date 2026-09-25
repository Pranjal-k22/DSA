class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            int cnt=0;
            int num=nums[i];
            int digit=0;
            while(num>0){
                digit=num%10;
                cnt++;
                num=num/10;
            }
            if(cnt%2==0){
                ans++;
            }
        }
        return ans;
    }
};