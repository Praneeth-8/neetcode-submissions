class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num;
        int count=0;
        for(int ans:nums){
            if(count==0){
                num=ans;
            }
            if(ans==num){
                count+=1;
            }
            else{
                count-=1;
            }        
        }
        return num;
        
    }
};