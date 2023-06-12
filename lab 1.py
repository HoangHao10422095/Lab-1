a = 5
b = 10
arr = [24, -2, 4 ,5, 9, 1,]

def sum(a, b):
    return (a + b)
def subtract(a, b):
    return (a - b)

def print_arr(arr2):
    for i in arr2:
        print(i, end = " ")

def find_max(arr2):
    res = -1000000
    for i in arr2:
        if (res < i):
            res = i
    return res

def bbsort(arr2):
    for i in  range(0, len(arr2)-1):
        for j in range(i, len(arr2)):
            if (arr2[i] > arr2[j]):
                arr2[i], arr2[j] = arr2[j], arr2[i]
    return arr2

#1.6
print(a, "+", b, "=", sum(a, b)), 
print(a, "-", b, "=", subtract(a, b))
#1.7
print(print_arr(arr))
#1.8
print(find_max(arr))
#1.9
print(bbsort(arr))