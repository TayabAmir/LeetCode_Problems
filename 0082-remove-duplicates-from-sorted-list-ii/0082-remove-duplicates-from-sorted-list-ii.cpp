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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> m;
        while(head){
            m[head->val]++;
            head = head->next;
        }
        ListNode *dummy = new ListNode(0);
        head = dummy;
        for(auto pair : m)
            if(pair.second == 1){
                head->next = new ListNode(pair.first);
                head = head->next;
            }
        return dummy->next;
    }
};