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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;
        ListNode *a = head;
        while(p && p->next && p ->next->next )
        {
            p = p->next->next;
            q = q->next;
            if(p == q)
            {
                while(q != a)
                {
                    a = a->next;
                    q = q->next;
                }
                return a;
            }
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

return 0;
}