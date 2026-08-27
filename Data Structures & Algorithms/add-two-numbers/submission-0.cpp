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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* res = new ListNode(0);
        ListNode* it = res;
        while(l1 && l2){
            int val1 = l1->val;
            int val2 = l2->val;
            
            ListNode* cur = new ListNode((val1+val2+carry)%10);
            carry = (val1+val2+carry) / 10;
            it->next = cur;
            it = cur;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int val1 = l1->val;
            ListNode* cur = new ListNode((val1+carry)%10);
            carry = (val1+carry)/10;
            it->next = cur;
            it = cur;
            l1 = l1->next;
        }
        while(l2){
            int val2 = l2->val;
            ListNode* cur = new ListNode((val2+carry)%10);
            carry = (val2+carry)/10;
            it->next = cur;
            it = cur;
            l2 = l2->next;
        }
        if(carry){
            ListNode* cur = new ListNode(carry);
            it->next = cur;
            it = cur;
        }
        return res->next;
        
    }
};
