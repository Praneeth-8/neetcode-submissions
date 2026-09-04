class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1){
            return false;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(!(mp.contains(nums[i]))){
                mp[nums[i]]=i;
            }
            else{
            if(i-mp[nums[i]]<=k){
                return true;
            }
            else{
                mp[nums[i]]=i;
            }}


        }
        return false;
        
    }
};