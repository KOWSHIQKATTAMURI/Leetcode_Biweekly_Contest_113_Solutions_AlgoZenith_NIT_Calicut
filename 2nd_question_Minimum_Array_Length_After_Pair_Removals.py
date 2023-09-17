class Solution:
    def minLengthAfterRemovals(self, nums):
        n = len(nums)
        high_frequency = 0
        i = 0
        # this is to count the highest frequency possible
        while i < n:
            count = 1
            present = nums[i]
            i += 1
            while i < n and nums[i] == present:
                count += 1
                i += 1
            high_frequency = max(high_frequency, count)

        # if double the high_frequency is greater than the size of the array, that means (n - high_frequency) elements will be compensated by high_frequency elements
        # so the remaining is high_frequency - (n - high_frequency) = 2*high_frequency - n, so we return this value.
        if 2*high_frequency > n:
            return 2*high_frequency - n

        # if n is odd and 2*high_frequency is not greater than n, there will be only one element that is left, so we return 1.
        # if n is even and 2*high_frequency is not greater than n, there will be no element left, so we return 0.
        if n % 2 == 1:
            return 1
        return 0
