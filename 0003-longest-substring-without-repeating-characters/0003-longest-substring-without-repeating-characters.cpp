class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0, high=0;
        int res=INT_MIN;
        unordered_map<char,int> frq;
        int n=s.size();
        for(high=0; high<n; high++){
            frq[s[high]]++;
            int k=high-low+1;
            while(frq.size()<k){
                frq[s[low]]--;
                if(frq[s[low]]==0){
                    frq.erase(s[low]);

                }
                low++;
                k=high-low+1;
            }
            int len=high-low+1;
            res=max(res,len);
        }
        if(s.empty()){
            return 0;
        }
        return res;
    }
};