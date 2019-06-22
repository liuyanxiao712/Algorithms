print("This program is the implementation of Bitonic Sort")
# It works when the size of input in a power of 2
# If the number is not the power of 2, padding is in need.

# Bitonic Sort: data-independent, always in parallel-computing
# Well-done introduction: https://blog.csdn.net/xbinworld/article/details/76408595

def Com_Swap(a, i, j, direc):
    """

    :param a: numbers
    :param i:
    :param j:
    :param direc: ascending or descending
    :return:
    """
    if (direc == 1 and a[i] > a[j]) or (direc == 0 and a[i] < a[j]):
        a[i], a[j] = a[j], a[i]

def Merge(a, low, cnt, direc):
    if cnt > 1:
        k = int(cnt / 2)
        for i in range(low, low + k):
            Com_Swap(a, i, i+k, direc)
        Merge(a, low, k ,direc)
        Merge(a, low + k, k, direc)

def Sort(a, low, cnt, direc):
    if cnt < 1:
        k = int(cnt / 2)
        Sort(a, low, k, 1)
        Sort(a, low + k, k, 0)
        Merge(a, low, cnt, direc)

def main(a, N, up):
    Sort(a, 0, N, up)

#test:
a = []
n = int(input())
for i in range(n):
    a.append(int(input()))
up = 1

Sort(a, n, up)
print("\n\nSorted array is")
for i in range(n):
    print("%d" % a[i])