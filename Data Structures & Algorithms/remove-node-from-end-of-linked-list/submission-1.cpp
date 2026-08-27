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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> arr;
        ListNode *cur = head;
        while(cur){
            arr.push_back(cur);
            cur = cur->next;
        }
        int sz = arr.size();
        int delNodeIdx = sz - n; 

        ListNode *prev = (delNodeIdx-1 < 0) ? nullptr : arr[delNodeIdx-1];
        if(!prev){
            head = head->next;
            return head;
        }
        ListNode *nxt = (delNodeIdx+1) >= sz ? nullptr : arr[delNodeIdx+1];
        prev->next = nxt;
        return head;
        
    }
};
