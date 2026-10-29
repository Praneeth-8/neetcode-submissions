class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = [0]*n
        suffix = [0]*n

        #loop for prefix
        prefix_prod=1
        for i in range(n):
            prefix[i]=prefix_prod
            prefix_prod*=nums[i]
        #suffix 
        suffix_prod=1
        for i in range(n-1,-1,-1):
            suffix[i]=suffix_prod
            suffix_prod*=nums[i]
        ans=[0]*n
        for i in range(n):
            ans[i] = suffix[i] * prefix[i]
        return ans
