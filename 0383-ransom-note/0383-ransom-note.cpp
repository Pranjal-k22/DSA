class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();
        int m=magazine.size();
        if(n>m){
            return false;
        }
        unordered_map<char,int> f;
        for(int i=0; i<m; i++){
            f[magazine[i]]++;
        }

        for(int i=0; i<n; i++){

            auto it = f.find(ransomNote[i]);
            if(it != f.end()){
                f[ransomNote[i]]--;
                if(f[ransomNote[i]]==0){
                    f.erase(ransomNote[i]);
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};