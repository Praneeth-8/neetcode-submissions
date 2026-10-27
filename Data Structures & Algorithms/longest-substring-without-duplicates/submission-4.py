class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d = {}
        i=0
        n=len(s)
        maxlength=0
        j=0
        for j in range(n):
            if s[j] not in d:
                d[s[j]]=j+1
            else:
                i=max(d[s[j]],i)
                d[s[j]]=j+1
            maxlength = max(j-i+1,maxlength)
        return maxlength
            
                

        