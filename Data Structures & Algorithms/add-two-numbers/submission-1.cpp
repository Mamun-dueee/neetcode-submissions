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
        int sum = 0;
        ListNode *res = new ListNode(0);
        ListNode *cur = res;
        while(l1 && l2){
            int a = l1->val;
            int b = l2->val;
            sum = (carry + a + b)%10;
            carry = (carry + a + b) / 10;
            ListNode *sumNode = new ListNode(sum);
            cur->next = sumNode;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int v = l1->val;
            sum = (carry + v)%10;
            carry = (carry + v) / 10;
            ListNode *sumNode = new ListNode(sum);
            cur->next = sumNode;
            cur = cur->next;
            l1 = l1->next;

        }

        while(l2){
            int v = l2->val;
            sum = (carry + v)%10;
            carry = (carry + v) / 10;
            ListNode *sumNode = new ListNode(sum);
            cur->next = sumNode;
            cur = cur->next;
            l2 = l2->next;

        }
        if(carry){
            ListNode *carryNode = new ListNode(carry);
            cur->next = carryNode;
            cur = cur->next;

        }

        return res->next;

        
    }
};
