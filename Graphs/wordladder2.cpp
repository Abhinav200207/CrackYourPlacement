#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());

        queue<vector<string>> q;
        q.push({beginWord});

        vector<string> usedOnLevel;
        wordList.push_back(beginWord);
        int level = 0;

        vector<vector<string>> ans;

        while (!q.empty()){
            auto vec = q.front();
            q.pop();

            if (vec.size() > level){
                level++;
                for (auto it : usedOnLevel){
                    st.erase(it);
                }
            }

            string s = vec.back();

            if (s == endWord){
                if (ans.size() == 0){
                    ans.push_back(vec);
                }else if (ans.back().size() == vec.size()){
                    ans.push_back(vec);
                }
            }

            for (int i = 0; i < s.size(); i++){
                char original = s[i];
                for (char c = 'a'; c <= 'z'; c++){
                    s[i] = c;
                    if (st.count(s)){
                        vec.push_back(s);
                        q.push(vec);
                        vec.pop_back();

                        usedOnLevel.push_back(s);
                    }
                }
                s[i] = original;
            }
        }
        return ans;
    }
};