class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1,j=0;
        int sum=0;
        for(int bana:piles){
            sum+=bana;
            if(bana>j){
                j=bana;}
        }
        int res = j;
        while(i<=j){
            int k = (j+i)/2 ;
            long long totaltime = 0;
            for(int p : piles){
                totaltime+= ceil(static_cast<double>(p)/k);
            }
            if(totaltime<=h){
                res = k;
                j=k-1;
            }
            else{
                i=k+1;
            }
        }
        return res;

        
        
    }
};
