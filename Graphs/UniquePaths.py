class Solution(object):
    def uniquePaths(self, m, n):
        d = {}

        def fun(m, n):
            if ((m, n) in d):
                return d[(m, n)]
            if (m == 1 and n == 1):
                return 1
            if (m == 0 or n == 0):
                return 0
            d[(m, n)] = fun(m-1, n) + fun(m, n-1)
            return d[(m, n)]
        return fun(m, n)


class Solution {
    public:
    int uniquePaths(int m, int n) {
        vector < int > pre(n, 1), cur(n, 1)
        for (int i=1
             i < m
             i++) {
            for (int j=1
                 j < n
                 j++) {
                cur[j] = pre[j] + cur[j - 1]
            }
            swap(pre, cur)
        }
        return pre[n - 1]
    }
}


class Solution {
    public:
    int uniquePaths(int m, int n) {
        vector < int > cur(n, 1)
        for (int i=1
             i < m
             i++) {
            for (int j=1
                 j < n
                 j++) {
                cur[j] += cur[j - 1]
            }
        }
        return cur[n - 1]
    }
}
