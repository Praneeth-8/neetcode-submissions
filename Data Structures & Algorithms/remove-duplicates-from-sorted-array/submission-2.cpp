class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int n = nums.size();
        int k =1;
        while(i<n){
            if(nums[i]!=nums[i-1]){
                nums[k]=nums[i];
                k+=1;
            }
            i++;
        }
        return k;
        
    }
};