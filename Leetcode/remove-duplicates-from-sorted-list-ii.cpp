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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)return head;
        ListNode* temp = head;
        int len = 0;
        
        while(temp->next != nullptr && temp->next->val == temp->val){
            len++;
            temp = temp->next;
        }
        if(len){
            return deleteDuplicates(temp->next);
        }else{
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};
