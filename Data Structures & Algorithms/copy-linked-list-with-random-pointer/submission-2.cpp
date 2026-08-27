/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void printList(Node *head){
        Node *cur = head;
        while(cur){
            cout << cur->val << " -> ";
            cur = cur->next;
        }
        cout << endl; 
    }
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }

        //insert a new copy next to each node
        Node *cur = head;
        while(cur){
            Node *copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        //printList(head);

        cur = head;
        //linked random to original->random->next
        while(cur){
            if(cur->random != nullptr){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        //printList(head);

        //save the newHead
        Node *newHead = head->next;
        Node *l1 = head;
        while(l1 != nullptr){
            Node* l2 = l1->next;
            l1->next = l2->next;
            if(l2->next){
                l2->next = l2->next->next;
            }
            l1 = l1->next;
        }
        return newHead;


        
    }
};
