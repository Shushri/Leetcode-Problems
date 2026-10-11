class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        ans=0
        n=len(nums)
        for i in range(0,n):
            if n%(i+1)==0:
                ans+=nums[i]*nums[i]
        return ans