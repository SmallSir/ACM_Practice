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
    bool hasCycle(ListNode *head) {
        ListNode *p = head,*q = head;
	    if(head == NULL || p->next == NULL)
		    return false;
	    for(;;)
	    {
		    if(p->next == NULL ||q->next == NULL ||q->next->next == NULL)
			    return false;
		    p = p->next;
		    q = q->next->next;
		    if(p->val == q->val && p->next->val == q ->next ->val)
			    return true;
	    }
    }
};
