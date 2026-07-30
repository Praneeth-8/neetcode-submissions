class Solution {
public:
    bool isAnagram(string s, string t) {
        int n= s.size(),m = t.size();
        if(n!=m){
            return false;
        }
        std::map<char,int> x;
        std::map<char,int> y;
        for(int i=0;i<n;i++){
            x[s[i]]+=1;
        }
        for(int i=0;i<m;i++){
            y[t[i]]+=1;
        }
        return x==y;
        
        
    }
};
