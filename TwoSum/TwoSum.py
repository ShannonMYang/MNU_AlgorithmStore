class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lookup = {}
        # enumerate() 函数用于将一个可遍历的数据对象(如列表、元组或字符串) 组合为一个索引序列，同时列出数据和数据下标，一般用在 for 循环当中。
        for i, num in enumerate(nums):
            if target - num in lookup:
                return [lookup[target-num], i]
            else:
                lookup[num] = i

# 测试代码是否正确有效
number = [3,2,4,1,5]
target = 6
a = Solution()
print(a.twoSum(number,target))