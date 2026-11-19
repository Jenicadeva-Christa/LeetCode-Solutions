
class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        ideal_sum = sum(set(nums)) * 2
        actual_sum = sum(nums)
        return ideal_sum - actual_sum

            