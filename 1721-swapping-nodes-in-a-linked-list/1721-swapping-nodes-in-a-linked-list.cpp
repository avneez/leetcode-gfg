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
    ListNode* swapNodes(ListNode* head, int k) {
         vector<int> nums;
        
        //step-1: Convert LL to array
        while(head != NULL){  //nums: 1 2 3 4 5
            nums.push_back(head->val);
            head = head->next;
        }
        
        //step-2: now find those two elements and swap
        int n = nums.size();
        swap(nums[k-1], nums[n-k]);
        
      
        //step-3: convert back array to LL
        ListNode* cur = new ListNode(NULL);
        head = cur;
        for(int i=0; i<n; i++){
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }    
        
        return head->next;
    }
};