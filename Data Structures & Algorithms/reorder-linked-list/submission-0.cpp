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
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reverse the second part
        ListNode* second = slow->next; //save as second
        ListNode* prev = slow->next = nullptr;//set as null
        while(second != nullptr){
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;    
        }

        //Merge the two half
        ListNode* first = head;
        second = prev;
        while(second != nullptr){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
        
    }
};
