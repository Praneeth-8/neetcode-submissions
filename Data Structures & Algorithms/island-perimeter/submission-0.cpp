class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int prmtr =0;
        int rows=grid.size();
        int cols=grid[0].size();

        set<pair<int,int>> land;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(grid[row][col]==1){
                    pair<int,int> coor={row,col};
                    land.insert(coor);
                }
            }
        }
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        for(auto coor:land){
            int perm = 4;
            for(auto dis:dir){
                pair<int,int>neigh={coor.first+dis.first,coor.second+dis.second};
                if(neigh.first>=0 && neigh.first<rows && neigh.second>=0 && 
                neigh.second<cols && grid[neigh.first][neigh.second]==1){
                    perm-=1;
                }
            }
            prmtr+=perm;

        }
        return prmtr;

        
    }
};