class Solution(object):
    def solve(self,i,temp,nums,ans):
        if i==len(nums):
            ans.append(temp[:])
            return 
        
        temp.append(nums[i])
        self.solve(i+1,temp,nums,ans)
        temp.pop()
        self.solve(i+1,temp,nums,ans)
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        ans=[]
        temp=[]
        self.solve(0,temp,nums,ans)
        return ans
        