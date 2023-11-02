#include <iostream>
#include <DList.h>

using namespace std;

int main()
{
    DList<int> L;
    L.print();
	L.addHead(30);
	L.print();
	L.addHead(13);
	L.print();
	L.addHead(40);
	L.print();
	L.addHead(50);
	L.print();
	L.addTail(20);
	L.print();
	L.addTail(40);
	L.print();
	cout<<L.getAt(3)<<endl;
	L.delAt(3);
	L.addAt(3, 15);

	DList<int> N(L);
	N.print();
	L.delTail();
	L.print();
	N.delHead();
	N.print();
	L.delHead();
	L.print();
	N.delTail();
	N.print();

	DList<int> R;
	R.print();
	if(R.empty())
		cout << "List R empty" << endl;

	L.delHead();
	L.print();
	L.delTail();
	L.print();
	if(L.empty())
		cout << "List L empty" << endl;

	else{
		cout << "List L contains " << L.length() << " nodes" << endl;
		cout << "Head element of list L is: " << L.headElement() << endl;
	}
	N.print();
	if(N.empty())
		cout << "List N empty" << endl;

	else{
		cout << "List N contains " << N.length() << " nodes" << endl;
		cout << "Head element of list N is: " << N.headElement() << endl;
	}
	N.Clear();
	N.print();
	if(N.empty())
		cout << "List N empty" << endl;

	else{
		cout << "List N contains " << N.length() << " nodes" << endl;
		cout << "Head element of list N is: " << N.headElement() << endl;
	}

	L.print();
	N.print();
	R.print();

    return 0;
}
