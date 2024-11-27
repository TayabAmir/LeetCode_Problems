/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = NULL;
        ListNode* res = head;
        int a;
        for(a = 0; a < left - 1; a++){
            prev = current;
            current = current->next;
        }
        ListNode* conn = prev;
        ListNode* tail = current;
        // next = current->next;
        for(;a < right; a++){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        if (conn != NULL)
            conn->next = prev;
        else 
            head = prev;

        tail->next = current;
        return head;
    }
};