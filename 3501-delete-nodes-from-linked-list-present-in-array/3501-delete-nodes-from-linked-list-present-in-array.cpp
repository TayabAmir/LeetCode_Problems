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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *dummy = new ListNode(-1), *res = dummy;
        set<int> s;
        for(int i : nums) s.insert(i);
        while(head){
            if(s.find(head->val) == s.end())
                res->next = new ListNode(head->val), res = res->next;
            head = head->next;
        }
        return dummy->next;
    }
};