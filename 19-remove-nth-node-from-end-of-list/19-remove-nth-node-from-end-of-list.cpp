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
   ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int size=0, pos;
        ListNode *temp = head, *prev = head;
        
        while(temp) temp = temp->next, ++size;
        
        pos = size-n;
        temp = head;
        
        if(pos == 0) return head->next;
        
        while(pos-- and temp)
        {
            prev = temp;
            temp = temp->next;      
        }
        
        if(temp) prev->next = temp->next;
        else prev->next = NULL;
        
        return head;
    }
};