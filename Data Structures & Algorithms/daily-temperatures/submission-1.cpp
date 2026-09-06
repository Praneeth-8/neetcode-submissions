class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        int last_elem;
        vector<int> ans(n,0);
        for(int i =n-1;i>-1;i--){
            if(!(s.empty())){
                last_elem=s.top();
            while(!(s.empty()) && temperatures[i]>=temperatures[last_elem]){
                s.pop();
                last_elem=s.top();
            }
            if(!s.empty()){
               ans[i]=last_elem-i;
            }
            else{
                ans[i]=0;}
            s.push(i);}
            else{
                ans[i]=0;
                s.push(i);


            }
        }
        return ans;
    }
};
