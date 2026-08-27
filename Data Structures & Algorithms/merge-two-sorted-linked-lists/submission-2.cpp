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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* m = new ListNode(0);
        ListNode* ans = m;

        while(l1 && l2){
            if(l1->val < l2->val){
                m->next = l1;
                l1 = l1->next;
                m = m->next;
            }
            else{
                m->next = l2;
                l2 = l2->next;
                m = m->next;
            }
        }

        while(l1){
            m->next = l1;
            l1 = l1->next;
            m = m->next;
        }
        while(l2){
            m->next = l2;
            l2 = l2->next;
            m = m->next;
        }

        return ans->next;
    }
};
