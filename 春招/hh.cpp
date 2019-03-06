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

class A{
public:
	virtual void t(){
		cout << "A::t" <<endl;
	}
	void k(){
		cout << "A::k" <<endl;
	}
};
class B:public A{
public:
	void t(){
		cout << "B::t" <<endl;
	}
	void k(){
		this.A::k();
		cout << "B::k" <<endl;
	}
};
int main()
{
	A *a = new B();
	a->k();
	a->t();
	return 0;
}
