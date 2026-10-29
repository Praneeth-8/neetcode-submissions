class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        suffix = [0]*n
        prefix_prod=1
        #suffix 
        suffix_prod=1
        for i in range(n-1,-1,-1):
            suffix[i]=suffix_prod
            suffix_prod*=nums[i]
        for i in range(n):
            suffix[i] = suffix[i] * prefix_prod
            prefix_prod*=nums[i]
        return suffix
