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
    int getDecimalValue(ListNode* head) {
        int p = 0,dec = 0;
        ListNode* temp = head;
        while(temp != NULL){
            p++;
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            dec += (temp->val * pow(2,--p));
            temp = temp->next;
        }
        return dec;
    }
};