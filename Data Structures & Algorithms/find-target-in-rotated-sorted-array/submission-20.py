class Solution:
    def search(self, nums: List[int], target: int) -> int:
        ind=-1
        i=0
        j=len(nums)-1

        while(i<=j):
            if target==nums[i]:
                return i
            if target == nums[j]:
                return j
            mid = (j-i)//2 +i
            if nums[mid]==target:
                return mid

            elif target < nums[mid]:
                if nums[i]<nums[mid]:
                    if target > nums[i]:
                        j=mid-1
                    else:
                        i+=1
                else:
                    j=mid-1

            elif target > nums[mid]:
                if nums[mid]<nums[j]:
                    if target < nums[j]:
                        i=mid+1
                    else:
                        j-=1
                else:
                    i=mid+1
            
        return ind
        