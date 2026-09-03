class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if(arr.size()==1){
            return arr[0];
        }
        int nodel=arr[0];
        int onedel=INT_MIN;
        int ans=arr[0];

        for(int i=1; i<arr.size(); i++){
            int prevnodel=nodel;
            int prevonedel=onedel;

            nodel=max((nodel+arr[i]),arr[i]);
            int v2;
            if(prevonedel==INT_MIN){
                v2=arr[i];
            }
            else{
                v2=prevonedel+arr[i];
            }
            onedel=max(v2,prevnodel);
            ans=max(ans,max(onedel,nodel));
        }
        return ans;
    }
};