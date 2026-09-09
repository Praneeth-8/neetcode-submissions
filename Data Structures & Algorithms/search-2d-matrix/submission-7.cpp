class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int rowl=0,rowr=m-1;
        while(rowl<rowr){
            int mid = (rowr-rowl)/2 +rowl;
            if(matrix[mid][0]<=target && matrix[mid][n-1]>=target){
                rowl=mid;
                break;
            }
            else if(matrix[mid][0]>target){
                rowr=mid-1;
            }
            else{
                rowl = mid+1;
            }
        }
        int l=0,r=n-1;
        while(l<=r){
            int mid = (r-l)/2 +l;
            if(matrix[rowl][mid]==target){
                return true;
            }
            else if (matrix[rowl][mid]>target){
                r= mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return false;
        
    }
};
