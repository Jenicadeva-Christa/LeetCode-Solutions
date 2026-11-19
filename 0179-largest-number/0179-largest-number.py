from functools import cmp_to_key
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        strs = [str(num) for num in nums]
        
        def compare(a, b):
            if a + b > b + a:
                return -1 
            elif a + b < b + a:
                return 1  
            else:
                return 0
        
        strs.sort(key=cmp_to_key(compare))
        
        result = "".join(strs)
        
        return "0" if result[0] == "0" else result
        