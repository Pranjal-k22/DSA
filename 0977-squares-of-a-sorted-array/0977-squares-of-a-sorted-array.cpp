class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg, pos;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<0){
                neg.push_back(nums[i]*nums[i]);
            }
            else{
                pos.push_back(nums[i]*nums[i]);
            }
        }
        int m=neg.size();
        int o=pos.size();
        int j=m-1;
        int k=0;
        int id=0;
        while(j >= 0 && k < o){
            if(neg[j]>=pos[k]){
                nums[id]=pos[k];
                id++;
                k++;
            }
            else if(neg[j]<pos[k]){
                nums[id]=neg[j];
                id++;
                j--;
            }
        }
        while(j>=0){
            nums[id]=neg[j];
            id++;
            j--;
        }
        while(k<o){
            nums[id]=pos[k];
            id++;
            k++;
        }
        return nums;
    }
};