class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int max_length=0;
        int n=s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            if(!(mp.contains(s[i]))){
                mp[s[i]]=i+1;
            }
            else{
                start=max(mp[s[i]],start);
                mp[s[i]]=i+1;
                
            }
            max_length=max(max_length,i-start+1);
        }  
        return max_length;      
    }
};
