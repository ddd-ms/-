#include<iostream>
#include"AVL_Tree.h"
using namespace std;
int main() {
	Avl_Tree<int> bt;

	bt.insert(3);
	bt.insert(5);
	bt.insert(1);
	bt.insert(9);
	bt.insert(7);
	//bt.insert(11);

	/*bt.insert(1);
	bt.insert(3);
	bt.insert(5);
	bt.insert(7);*/

	

	bt.f_print();
	bt.preprint();
	return 0;
}