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
    ListNode* reverseList(ListNode* head) {
//         if(head==NULL) return {};
//         ListNode *curr=head;
//         ListNode *prev = NULL;
//         while(curr!=NULL){
//             ListNode *next=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=next;
//         }
//         return prev;
//     }
// };
        
        //Recursive solution
        if(head==NULL or head->next==NULL) return head;
        
        ListNode *rest_head = reverseList(head->next);
        ListNode *rest_tail=head->next;
        head->next=NULL;
        rest_tail->next=head;
        
        return rest_head;
    }
};
        