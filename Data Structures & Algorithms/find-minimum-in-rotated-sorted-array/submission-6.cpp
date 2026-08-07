class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low<high){
            mid = ((high -low)/2) + low;
            if (nums[mid]>nums[high]){
                low =mid+1;
            }
            else if (nums[mid]<nums[low]){
                high=mid;
            }
            else {
                break;
            }
        }
        return nums[low];

        
    }
};
