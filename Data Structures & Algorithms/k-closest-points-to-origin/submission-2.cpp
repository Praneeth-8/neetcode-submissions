class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> heap;
        vector<vector<int>> ans;
        int i =0;

        for (auto point:points){
            int dist = pow(point[0],2) + pow(point[1],2);
            heap.push({-dist,i});
            i++;
        }
        while (k){
            ans.push_back(points[heap.top().second]);
            heap.pop();
            k--;
        }
        return ans;

        
    }
};
