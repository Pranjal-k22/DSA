
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> f;

        for (int i = 0; i < words.size(); i++) {
            f[words[i]]++;
        }

        auto cmp = [](pair<int, string> a, pair<int, string> b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        };

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            decltype(cmp)
        > pq(cmp);

        for (auto i : f) {
            pair<int, string> curr = {i.second, i.first};

            pq.push(curr);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> str;

        while (!pq.empty()) {
            str.push_back(pq.top().second);
            pq.pop();
        }

        reverse(str.begin(), str.end());

        return str;
    }
};