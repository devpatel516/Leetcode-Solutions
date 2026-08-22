class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        temp=x
        if x<0:
            return False
        
        rev=0
        while x!=0:
            r=x%10
            rev=rev*10+r
            x=x/10
        
        print(rev)
        if rev==temp:
            return True
        
        return False