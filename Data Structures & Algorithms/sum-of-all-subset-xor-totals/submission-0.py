class Solution:
    res=0
    def xor(self,lst):
        if not lst:
            return 0
        ans=lst[0]
        n=len(lst)
        for i in range(1,n):
            ans = ans ^ lst[i]
        return ans
    def subsetXORSum(self, nums: List[int]) -> int:
        
        sol=[]
        n=len(nums)

        def backtrack(i):
            if i==n:
                global res
                self.res+=self.xor(sol)
                return 
            backtrack(i+1)

            sol.append(nums[i])
            backtrack(i+1)
            sol.pop()
        
        backtrack(0)
        return self.res

        