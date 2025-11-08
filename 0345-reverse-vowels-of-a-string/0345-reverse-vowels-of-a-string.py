class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        lst = list(s)
        vowels = set('aeiouAEIOU')   # faster lookup
        i, j = 0, len(lst) - 1

        while i < j:
            if lst[i] not in vowels:
                i += 1
                continue
            if lst[j] not in vowels:
                j -= 1
                continue

            # Swap vowels
            lst[i], lst[j] = lst[j], lst[i]
            i += 1
            j -= 1

        # Join list back into string
        return ''.join(lst)
