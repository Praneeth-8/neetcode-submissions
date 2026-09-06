class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for(int a:asteroids){
            while(!(s.empty())&& a<0 && s.back()>0){
                int diff = a+s.back();
                if(diff<0){
                    s.pop_back();
                }
                else if(diff>0){
                    a=0;
                }
                else{
                    s.pop_back();
                    a=0;
                }

            }
            if (a){
                s.push_back(a);}
        }
        return s;

        
    }
};