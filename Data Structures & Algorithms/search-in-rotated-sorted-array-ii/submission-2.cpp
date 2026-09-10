class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;

        while(i<=j){
            int mid = (j-i)/2 +i;
            if(nums[mid]==target){
                return true;
            }
            else if (nums[i]<nums[mid]){
                if(target>=nums[i] && target<nums[mid]){
                    j=mid-1;

                }
                else{
                    i=mid+1;
                }

            }
            else if(nums[i]>nums[mid]){
                if(nums[mid]<target && nums[j]>=target){
                    i=mid+1;
                }
                else{
                    j=mid-1;

                }
            }
            else{
                i++;
            }
        }
        return false;
        
    }
};