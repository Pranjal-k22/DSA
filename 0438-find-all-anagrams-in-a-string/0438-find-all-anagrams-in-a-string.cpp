class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (p.size() > s.size()) {
            return ans;
        }

        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);

        for (int i = 0; i < p.size(); i++) {
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }

        if (freqP == freqS) {
            ans.push_back(0);
        }

        for (int i = p.size(); i < s.size(); i++) {
            freqS[s[i] - 'a']++;               // Add new character
            freqS[s[i - p.size()] - 'a']--;    // Remove old character

            if (freqP == freqS) {
                ans.push_back(i - p.size() + 1);
            }
        }

        return ans;
    }
};