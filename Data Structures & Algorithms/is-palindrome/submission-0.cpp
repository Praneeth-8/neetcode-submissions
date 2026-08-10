class Solution {
public:
    bool isPalindrome(string s) {
        int r = s.length()-1;
        int l=0;
        while(l<r){
            char x=tolower(s[l]);
            char y = tolower(s[r]);
            if (not(iswalnum(x))){
                l++;
            }
            else if (not iswalnum(y)){
                r--;
            }
            else{
            if (x==y){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
    }
        return true;

        
    }
};
