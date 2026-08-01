class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j=heights.size()-1;
        int ans=0;
        while(i<j){
            int cap;
            if(heights[i]<heights[j]){
                cap = heights[i]*(j-i);
                i++;
            }
            else if(heights[j]<heights[i]){
                cap = heights[j]*(j-i);
                j--;

            }
            else{cap =  heights[j]*(j-i);
            i++;}
            if (cap>ans){
                ans=cap;
            }   
        }
        return ans;
    }
};
