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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1,-1};
        vector<int> v;
        int min = INT_MAX, max=-1,node = 2,prev = head->val;
        ListNode* temp = head->next;
        while(temp->next){
            if((temp->val > prev && temp->val > temp->next->val) || (temp->val < prev && temp->val < temp->next->val)){
                v.push_back(node);
            }
            prev=temp->val,node++,temp=temp->next;
        }
        if(v.size() > 1){
            max = v[v.size()-1] - v[0];
            for(int i = 0; i < v.size()-1; i++)
                if(v[i+1]-v[i] < min)
                    min = v[i+1]-v[i];
        } else {
            return {-1,-1};
        }
        return {min,max};
    }
};