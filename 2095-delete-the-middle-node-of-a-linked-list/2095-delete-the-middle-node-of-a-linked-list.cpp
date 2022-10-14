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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast = head;
        if(slow->next==NULL) return NULL;
        if(slow->next->next==NULL){
            slow->next=NULL;
            return slow;
        }
        
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->val=slow->next->val;
        slow->next=slow->next->next;
        
        return head;
    }
};