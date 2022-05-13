
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int l = 0;
        ListNode* ptr = head;
        while (ptr){
            ptr = ptr->next;
            l++;
        }
        int index = l/2;
        ptr = head;
        while (index--){
            ptr = ptr->next;
        }
        return ptr;
    }
};