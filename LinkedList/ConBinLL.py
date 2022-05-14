# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def getDecimalValue(self, head):
        s = ""
        while (head):
            s += str(head.val)
            head = head.next
        return int(s,2)