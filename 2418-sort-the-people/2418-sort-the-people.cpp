class Solution {
public:
    int findind(int num, vector<int> arr){
        for(int i=0; i<arr.size(); i++){
            if(num==arr[i]){
                return i;
            }
        }
        return 0;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> h;
        vector<string> ans;

        for(int i=0; i<heights.size(); i++){
            h.push_back(heights[i]);
        }
        sort(h.begin(), h.end(), greater<int>());
        for(int i=0; i<h.size(); i++){
            int a=findind(h[i],heights);

            ans.push_back(names[a]);
        }

        return ans;
    }
};