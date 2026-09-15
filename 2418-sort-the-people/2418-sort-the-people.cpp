class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> ind(names.size());

        iota(ind.begin(), ind.end(), 0);

        sort(ind.begin(), ind.end(), [&](int a, int b) {
            return heights[a] > heights[b];
        });

        vector<string> ans;

        for(int i : ind){
            ans.push_back(names[i]);
        }

        return ans;
    }
};