class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> s;
        for(string score:operations){
            if(score[0]=='C'){
                s.pop_back();
            }
            else if(score[0]=='+'){
                    int last = s.back();
                    int plast = s[s.size()-2];
                    s.push_back(last+plast);
            }
            else if(score[0] == 'D'){
                    s.push_back(2*s.back());
            }
            else{
                s.push_back(stoi(score));
            }
            

        }
        int sum=0;
        for(int el:s){
            sum+=el;
        }
        return sum;
        
    }
};