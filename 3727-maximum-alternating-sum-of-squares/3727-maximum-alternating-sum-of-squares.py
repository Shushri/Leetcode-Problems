class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        arr=[]
        n=len(nums)
        for ele in nums:
            arr.append(abs(ele))
        arr.sort()
        ans=0
        l=0
        h=n-1
        while l<h:
            ans+=arr[h]*arr[h]
            ans-=arr[l]*arr[l]
            l=l+1
            h=h-1
        if l==h:
            ans+=arr[h]*arr[h]
        return ans
        
