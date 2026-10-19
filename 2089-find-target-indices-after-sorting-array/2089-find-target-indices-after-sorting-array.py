class Solution:
    def targetIndices(self, nums: list[int], t: int) -> list[int]:
        nums.sort()
        ans=[]
        for i in range (0 , len(nums)):
            if nums[i]==t:
                ans.append(i)
        return ans

