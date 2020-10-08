/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;      
        ListNode *temp2 = headB;      
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 == temp2)return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        int diff = 0;
        //Temp1 reached end first
        if(temp1 == NULL){
            while(temp2 != NULL){
                diff++;
                temp2 = temp2->next;
            }
            temp1 = headA;
            temp2 = headB;
            while(diff--){
                temp2 = temp2->next;
            }
            
            while(temp1 != NULL && temp2 != NULL){
                if(temp1 == temp2)return temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return NULL; 
        }else{
            //Temp2 reached the end first
            
            while(temp1 != NULL){
                diff++;
                temp1 = temp1->next;
            }
            temp1 = headA;
            temp2 = headB;
            while(diff--){
                temp1 = temp1->next;
            }
            
            while(temp1 != NULL && temp2 != NULL){
                if(temp1 == temp2)return temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return NULL; 
        }
    }
};
