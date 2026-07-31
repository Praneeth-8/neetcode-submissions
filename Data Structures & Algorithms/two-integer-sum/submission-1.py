class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map={}
        n=len(nums)
        for i in range(n):
            rem=target-nums[i]
            if rem in map:
                return [map[rem],i]
            if not nums[i] in map:
                map[nums[i]]=i
            
        