def exist(board, word):
    ROWS, COLS = len(board), len(board[0])
    path = set(board[1])

    def dfs(i, j, k):
        if k == len(word):
            return True
        if i < 0 or j < 0 or i >= ROWS or j >= COLS or board[i][j] != word[k] or (i, j) in path:
            return False
        path.add((i, j))
        res = (dfs(i+1, j, k+1) or
               dfs(i, j+1, k+1) or
               dfs(i-1, j, k+1) or
               dfs(i, j-1, k+1))
        path.remove((i, j))
        return res
    
    for i in range(ROWS):
        for j in range(COLS):
            if dfs(i,j,0):
                return True
    return False


# #include <bits/stdc++.h>
# using namespace std;

# class Solution
# {
#     set<pair<int, int>> s;
#     bool utill(vector<vector<char>> board, string word, int i, int j, int k)
#     {
#         if (k == word.size())
#         {
#             return true;
#         }
#         if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k] || s.find({i, j}) != s.end())
#         {
#             return false;
#         }
#         s.insert({i, j});
#         bool res = utill(board, word, i + 1, j, k + 1) ||
#                utill(board, word, i, j + 1, k + 1) ||
#                utill(board, word, i - 1, j, k + 1) ||
#                utill(board, word, i, j - 1, k + 1);
#         s.erase({i,j});
#         return res;
#     }

# public:
#     bool exist(vector<vector<char>> board, string word)
#     {
#         for (int i = 0; i < board.size(); i++)
#         {
#             for (int j = 0; j < board[i].size(); j++)
#             {

#                 if (utill(board,word,i,j,0))
#                 {
#                     return true;
#                 }
#             }
#         }
#         return false;
#     }
# };

# int main()
# {
#     Solution obj;
#     vector<vector<char>> board{{'a'}};
#     obj.exist(board, "a");
# }
