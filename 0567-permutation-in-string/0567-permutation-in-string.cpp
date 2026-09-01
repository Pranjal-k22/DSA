class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        vector<int> freqs1(26,0);
        vector<int> freqs2(26,0);
        for(int i=0; i<s1.size(); i++){
            freqs1[s1[i]-'a']++;
            freqs2[s2[i]-'a']++;
        }
        if(freqs1==freqs2){
            return true;
        }
        for(int i=s1.size(); i<s2.size();i++){
            freqs2[s2[i]-'a']++;
            freqs2[s2[i -s1.size()]-'a']--;

            if(freqs1==freqs2){
                return true;
            }
        }
        
        return false;
    }
};