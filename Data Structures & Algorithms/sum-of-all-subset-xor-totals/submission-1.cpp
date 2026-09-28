class Solution {
public:
    int Xor(vector<int>& nums){
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int ans = nums[0];
        for(int i = 1;i<n;i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
    int res=0;
    vector<int> sol;
    void backtrack(int index,int n,vector<int>&nums){
        if(index==n){
            res+=Xor(sol);
            return;
        }
        //Don't include the number
        backtrack(index+1,n,nums);
        
        //include
        sol.push_back(nums[index]);
        backtrack(index+1,n,nums);
        sol.pop_back();
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        backtrack(0,n,nums);
        return res;
        
    }
};