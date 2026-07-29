class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0;

        // merge alternately
        while(i < word1.size() && i < word2.size()){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
            i++;
        }

        // append remaining
        ans += word1.substr(i);
        ans += word2.substr(i);

        return ans;
    }
};
