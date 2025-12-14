class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        l=s.split(" ")
        p=l[0]
        
        c=0
        ans=""
        ans+=p
        for i in p:
            if i in "aeiou":
                c=c+1
        for i in range (1 , len(l)):
            d=0
            for j in l[i]:
                if j in "aeiou":
                    d=d+1
            if d==c:
                ans+=" "
                ans+=l[i][::-1]
            else:
                ans+=" "
                ans+=l[i]
        return ans