class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        # method-1
        # return Counter(s) == Counter(t)

        # method-2
        if len(s) != len(t):
            return False

        countS, countT = {}, {}
        for i in range (len(s)):
            countS[s[i]] = 1 + countS.get(s[i], 0)
            countT[t[i]] = 1 + countT.get(t[i], 0)

        for cnt_ele in countS:
            if countS[cnt_ele] != countT.get(cnt_ele, 0):
                return False
        
        return True
        