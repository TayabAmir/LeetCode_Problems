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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* modify = head;
        int sum = 0;
        while(temp != NULL){
            if(temp->val == 0){
                modify->val = sum, sum = 0;
                if(temp->next == NULL)
                    modify->next = NULL;
                else
                    modify = modify->next;
            }
            sum += temp->val;
            temp = temp->next;
        }
        return head;
    }
};