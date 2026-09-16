
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> f;

        for (auto& word : words) {
            f[word]++;
        }

        vector<vector<string>> bucket(words.size() + 1);

        for (auto& p : f) {
            bucket[p.second].push_back(p.first);
        }

        vector<string> ans;

        for (int i = bucket.size() - 1; i >= 1; i--) {
            if (!bucket[i].empty()) {
                sort(bucket[i].begin(), bucket[i].end());

                for (auto& word : bucket[i]) {
                    ans.push_back(word);

                    if (ans.size() == k) {
                        return ans;
                    }
                }
            }
        }

        return ans;
    }
};