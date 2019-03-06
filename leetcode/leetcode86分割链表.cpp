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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p = head;
        ListNode *l = new ListNode(0);
        ListNode *n = l;
        
        ListNode *r = new ListNode(0);
        ListNode *u = r;
        if(head == NULL)
            return head;
        while(p!=NULL)
        {
            if(p->val < x)
            {
                l->next = p;
                l = l->next;
            }
            else
            {
                r->next = p;
                r = r->next;
            }
            p = p->next;
        }
        n = n->next;
        u = u->next;
        if(n!=NULL)
        {
            r->next = NULL;
            l->next = u;
            return n;
        }
        else
            return u;
    }
};