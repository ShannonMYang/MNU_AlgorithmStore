def quicksort(array):
    if len(array) < 2:
        return array
    else:
        pivot = array[0]
        # 进入循环遍历，将小于基准值pivot的，都放进左边的数组
        less = [i for i in array[1:] if i <= pivot]
        # 进入循环遍历，将大于基准值pivat的，都放进右边的数组
        greater = [i for i in array[1:] if i > pivot]
        # 递归调用，继续变动基准值，继续遍历，指导排序完成
        return quicksort(less) + [pivot] + quicksort(greater)

print(quicksort([10, 5, 2, 3]))