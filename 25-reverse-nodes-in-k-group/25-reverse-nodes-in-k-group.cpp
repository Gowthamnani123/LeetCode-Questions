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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(!head || !head->next)
            return head;
        
        ListNode *t=head,*p=NULL,*n;
        int i=0;
        
        while(t && i++<k)
            t=t->next;
        
        if(i<k)
            return head;
        
        t=head;
        i=0;
        while(t && i<k)
        {
            n=t->next;
            t->next=p;
            
            p=t;
            t=n;
            
            i++;
        }
        
        head->next=reverseKGroup(t,k);
        
        return p;
    }
    
};