#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
       ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
       dummy -> next = head;
       for (int i = 0; i < m - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
       return dummy -> next;
   }
};

// 18 11 11 18
// 8 7 7 8
// 18 11 11 18

// 8 + 8 + 8 + 14 + 2 + 1 + 9 + 9 + 2

// 1 2 3 1
// 5 6 7 5
// 1 2 3 1

// 8 + 8 + 14 + 3 + 3 + 3 + 3

// 9 10 11 4
// 5 6 7 8
// 9 10 11 18