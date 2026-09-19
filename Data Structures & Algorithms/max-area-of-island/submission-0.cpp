#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        int rows = grid.size();
        int cols = grid[0].size();
		set<pair<int,int>> visited;
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
				pair<int,int> elem ={row,col};
				if(visited.contains(elem)){
					continue;
				}
				else if(grid[row][col]==1){
					int area =1;
                    visited.insert({row,col});
						deque<pair<int,int>> q={{row,col}};
						while(!(q.empty())){
						auto node = q.front();
						q.pop_front();

						for(auto dir:dirs){
							int x = node.first + dir.first;
							int y = node.second + dir.second;
                            pair<int,int> neigh = {x,y};
							if(x>=0 && x<rows && y>=0 && y<cols){
								if(grid[x][y]==1 && !visited.contains(neigh)){
									area+=1;
									visited.insert(neigh);
									q.push_back(neigh);
								}
							}
						}
						maxarea=max(maxarea,area);
					}
				}
                
            }
        }
		return maxarea;
        
    }
};
