# I use divide-and-conquer method to
# solve the maximum-subarray problem

def cross_sm(arr, l, m, r):
    # Elements from left of mid
    sm = 0
    left_sm = -100
    for i in range(m, l-1, -1):
        sm = sm + arr[i];
        if sm > left_sm:
            left_sm = sm
    # Elements from right of mid
    sm = 0
    right_sm = -100
    for i in range(m + 1, r + 1):
        sm = sm + arr[i]
        if sm > right_sm:
            right_sm = sm;
    return left_sm + right_sm;

def Max_SubArray_sm(arr, l, r):
    if l == r:
        return arr[l]
    m = (l + r) // 2
    return max(Max_SubArray_sm(arr, l, m),
               Max_SubArray_sm(arr, m + 1, r),
               cross_sm(arr, l, m, r))

# Driver Code
arr = [2,3,-5,7,8,-2,7,-3]
length = len(arr)
max_sum = Max_SubArray_sm(arr, 0, length - 1)
print("Maximum contiguous sum is ", max_sum)