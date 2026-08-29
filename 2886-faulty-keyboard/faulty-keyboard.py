class Solution(object):
    def finalString(self, s):
        """
        :type s: str
        :rtype: str
        """
        result=""

        for c in s:
            if c=='i':
                temp=result
                temp=temp[::-1]
                result=temp
            else:
                result+=c


        return result