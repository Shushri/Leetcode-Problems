class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        lst=list(s)
        vwl=['a','e','i','o','u','A','E','I','O','U']
        i=0
        j=len(s)-1
        while i<j:
            if(lst[i] in vwl):
                if lst[j] in vwl:
                    temp=lst[i]
                    lst[i]=lst[j]
                    lst[j]=temp
                    i=i+1
                    j=j-1
                else:
                    j=j-1
            elif lst[j] in vwl:
                i=i+1
            else:
                i=i+1
                j=j-1
        s=""
        for i in lst:
            s=s+i
        return s