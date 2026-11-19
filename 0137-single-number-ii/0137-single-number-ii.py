class Solution:

    def singleNumber(self, nums: list[int]) -> int:
        ideal_sum = sum(set(nums)) * 3
        actual_sum = sum(nums)
        c= (ideal_sum - actual_sum)//2
        return c
