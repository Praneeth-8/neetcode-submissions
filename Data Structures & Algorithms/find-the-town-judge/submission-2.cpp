class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> v;
        unordered_map<int,int> mp;
        for(auto edge:trust){
            v.insert(edge[0]);
            if(!mp.contains(edge[1])){
                mp[edge[1]]=0;
            }
            mp[edge[1]]+=1;
        }
        for(int i=1;i<=n;i++){
            if(!v.contains(i) && mp[i]==n-1){
                return i;
            }
        }
        return -1;
    
        
    }
};