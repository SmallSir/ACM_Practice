#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n<=0) return head;
	    ListNode *p = head,*q = head;
	    int num = 1;
        if(head->next == NULL && n == 1)
        {
            head = NULL;
            return head;
        }
	    while(p->next!=NULL)
	    {
		    p = p->next;
		    num++;
	    }
        if(num < n)
            return head;
        int i;
	    for(i=0;i<num-n-1;i++)
		    q = q->next;
        if(n!=num && n!=1)
        {
            p = q->next;
	        q->next = q->next->next;
            delete p;
        }
        else if(n == 1)
        {
            p = q->next;
            q->next = NULL;
            delete p;
        }
        else
        {
            head = q->next;
            delete q;
        }
        return head;
    }
};
