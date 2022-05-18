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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nxt = head->next;
        while (prev)
        {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        head = curr;
        return head;
    }
};

void push(ListNode **head_ref, int new_data)
{
    ListNode *new_node = new ListNode();
    new_node->val = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printLL(ListNode *head)
{
    while (head)
    {
        cout << head->val << "-> ";
        head = head->next;
    }
}

int main()
{
    ListNode *head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);


    Solution solve;
    head = solve.reverseList(head);

    printLL(head);

    return 0;
}