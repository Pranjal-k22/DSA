class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int n=matrix.size();
        int idx=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(idx<k){
                    pq.push(matrix[i][j]);
                    idx++;
                    continue;
                }
                if(matrix[i][j]<pq.top()){
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
    }
};