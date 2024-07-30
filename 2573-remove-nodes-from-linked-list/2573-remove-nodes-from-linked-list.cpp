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
    ListNode* reverseList(ListNode* head){
        ListNode *prev = NULL, *current = head, *next;
        while(current){
            next = current->next;
            current-> next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(!head->next) return head;
        head = reverseList(head);
        int max = head->val;
        ListNode *prev = head, *curr = head->next, *temp = NULL;
        while(curr){
            if(curr->val >= max){
                max = curr->val;
                prev = curr;
                curr = curr->next;
            } else {
                temp = curr;
                curr = curr->next;
                prev->next = curr;
                temp->next = NULL;
            }
        }
        return reverseList(head);
    }
};