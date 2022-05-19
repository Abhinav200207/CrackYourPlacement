class Solution(object):
    def spiralOrder(self, matrix):
        def spiralPrint(m, n, a):
            k = 0
            l = 0
            l = []
            while (k < m and l < n):
                for i in range(l, n):
                    print(a[k][i], end=" ")
                    l.append(a[k][i])
                k += 1
                for i in range(k, m):
                    print(a[i][n - 1], end=" ")
                    l.append(a[i][n - 1])
                n -= 1
                if (k < m):
                
                    for i in range(n - 1, (l - 1), -1):
                        print(a[m - 1][i], end=" ")
                        l.append(a[m - 1][i])
                    m -= 1
                if (l < n):
                    for i in range(m - 1, k - 1, -1):
                        print(a[i][l], end=" ")
                        l.append(a[i][l])
                    l += 1
            return l
        return spiralPrint(len(matrix),len(matrix),matrix)
