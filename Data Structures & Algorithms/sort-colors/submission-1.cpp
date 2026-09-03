class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        int temp;
        while(i<j){
            while(i<n-1 && nums[i]!=2){
                i++;
            }
            while(j>=0 && nums[j]==2){
                j--;
            }
            if(i<j){
            temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;}

        }
        int k=0;
        int l=n-1;
        while(l>=0 &&nums[l]==2){
            l--;
        }
        int copy=l;
        while(k<l){
            while(k<copy+1 &&nums[k]!=1){
                k++;
            }
            while(l>=0 && nums[l]==1){
                l--;
            }
            if(k<l){
            temp=nums[k];
            nums[k]=nums[l];
            nums[l]=temp;
            k++;
            l--;}
            
        }


        
    }
};