def celebrity(self, M, n):
    ans = -1
    l = [0]*n
    for i in range(len(M)):
        if (M[i] == l):
            ans = i
            break
    for i in range(len(M)):
        if (M[i][ans] != 1 and i != ans):
            return -1
    return ans
