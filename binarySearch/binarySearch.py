def binarySearch(list, item):
    # min 和 max 用于跟踪要在其中查找的列表部分
    low = 0
    high = len(list) - 1

    # 只要范围没有缩小到只包含一个元素，就检查中间的元素是不是符合所需要求
    while low <= high:
        # 此处需要强制转换，不然得出的值会是小数，导致报错
        mid = int((low + high) / 2)
        guess = list[mid]
        if guess == item:
            return mid
        if guess > item:
            high = mid - 1
        else:
            low = mid + 1
    return None

# 测试
my_list = [1, 3, 5, 7, 9, 11]

print()

print(binarySearch(my_list, 11))
print(binarySearch(my_list, -3))