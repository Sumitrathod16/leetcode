class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
           ans = -1
           for i, num in enumerate(nums):
             if num != i:
                ans &= num
           return max(ans, 0)            
        