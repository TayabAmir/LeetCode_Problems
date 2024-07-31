/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        set<ListNode*> s;
        ListNode* temp = head, *cycle = NULL;
        while(temp){
            cycle = temp;
            if(s.find(temp) == s.end())
                s.insert(temp);
            else
                return cycle;
            temp = temp->next;
        }
        return NULL;
    }
};