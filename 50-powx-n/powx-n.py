class Solution(object):
    def solve(self,x,n):
        if n==0:
            return 1
        
        half=self.solve(x,n//2)

        if n%2==0:
            return half*half
        return x*half*half
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n<0:
            return 1/self.solve(x,abs(n))
        
        return self.solve(x,n)