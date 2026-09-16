class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        set<pair<int,int>> visited;

        int islands=0;
        
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if (visited.contains(pair<int,int>{row,col})){
                    continue;
                }
                if(grid[row][col]=='1'){
                    islands+=1;
                    deque<pair<int,int>> q={{row,col}};
                    visited.insert({row,col});
                    while(!q.empty()){
                        auto node = q.front();
                        q.pop_front();
                        int x=node.first;
                        int y=node.second;

                        for (auto cor:dir){
                            int x1=x+cor.first;
                            int y1=y+cor.second;
                            pair<int,int> neigh={x1,y1};
                            if(x1 >= 0 && x1 < rows && y1 >= 0 && y1 < cols){
                                if(grid[x1][y1]=='1' && !visited.contains(neigh)){
                                    q.push_back(neigh);
                                    visited.insert(neigh);
                                }
                            }

                        }
                    }
                }
            }
        }
        return islands;
        
        
    }
};
