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
    void reorderList(ListNode* head) {
        ListNode *s = head, *f = head, *rev = nullptr;

        //Finding location to start reversing
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }

        rev = s->next;
        s->next = nullptr;

        //Reverse second part of the list (rev to nullptr)
        ListNode *prev = nullptr;
        while(rev){
            ListNode *nextNode = rev->next;
            rev->next = prev;
            prev = rev;
            rev = nextNode;
        }
        rev = prev;

        //Merging the two lists
        ListNode *fst = head;
        while(fst && rev){
            ListNode *nextFst = fst->next;
            fst->next = rev;
            ListNode *nextRev = rev->next;
            rev->next = nextFst;
            fst = nextFst;
            rev = nextRev;
        }
        
    }
};
