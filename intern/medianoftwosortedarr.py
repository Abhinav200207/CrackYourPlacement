def mergeArrays(num1, num2, n1, n2):
    newArr = [0] * (n1 + n2)
    i = 0
    j = 0
    k = 0
    while i < n1 and j < n2:
        if num1[i] < num2[j]:
            newArr[k] = num1[i]
            k = k + 1
            i = i + 1
        else:
            newArr[k] = num2[j]
            k = k + 1
            j = j + 1
    while i < n1:
        newArr[k] = num1[i];
        k = k + 1
        i = i + 1
    while j < n2:
        newArr[k] = num2[j];
        k = k + 1
        j = j + 1
    return newArr
class Solution(object):
    def findMedianSortedArrays(self, num1, num2):
        newArr = mergeArrays(num1,num2,len(num1),len(num2));
        if (len(newArr)%2 == 0):
            return float(newArr[len(newArr)/2 - 1] + newArr[len(newArr)/2])/2.0
        else:
            return newArr[len(newArr)/2]