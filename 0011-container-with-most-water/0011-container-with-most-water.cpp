class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end=height.size()-1;
        int ans=0;
        while(start<end){
            int h1=height[start];
            int h2=height[end];
            int ht=min(h1,h2);
            int bt=end-start;
            int sz=ht*bt;
            ans=max(sz,ans);
            if(h1<h2){
                start++;
            }
            else{
                end--;
            }
        }
        return ans;
    }
};