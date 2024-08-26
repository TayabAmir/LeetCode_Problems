/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *temp = head;
        while(temp){
            if(temp->child && temp->next){
                Node *temp2 = temp->child;
                while(temp2->next){
                    temp2 = temp2->next; 
                }
                temp2->next = temp->next;
                temp->next->prev = temp2;
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = NULL;
            } else if(temp->child && !temp->next){
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = NULL;
            }
            temp = temp->next;
        }
        return head;
    }
};