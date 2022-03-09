#include<stack>
#include<queue>
#include<cstdlib>
#include<cstdio>

int max(int x1, int x2) {
	return x1 > x2 ? x1 : x2;
}

template<class Elem>
struct BinNode {
	Elem data;
	BinNode<Elem>* left;
	BinNode<Elem>* right;
	bool isFirst;
	int height;
	bool isDelete;
	BinNode(Elem x) {
		data = x;
		left = right = nullptr;
		isFirst = false;
		height = 0;
	}
};
template <class Elem>
class Avl_Tree {
protected:
	BinNode<Elem>* root;
	int getHei(BinNode<Elem>* r) {
		if (!r)return -1;
		return r->height;
	}
	BinNode<Elem>* LL_Rotate(BinNode<Elem>* r){
		printf("%d", r->data);
		printf("LL_Rotate\n");
		BinNode<Elem>* child;
		child = r->left;
		r->left = child->right;
		child->right = r;
		//更新高度
		r->height = max(getHei(r->left), getHei(r->right)) + 1;
		child->height = max(getHei(child->left), getHei(child->right)) + 1;
		return child;
	}
	BinNode<Elem>* RR_Rotate(BinNode<Elem>* r) {
		printf("%d", r->data);
		printf("RR_Rotate\n");
		BinNode<Elem>* child;
		child = r->right;
		r->right = child->left;
		child->left = r;
		//update height
		r->height = max(getHei(r->left), getHei(r->right)) + 1;
		child->height = max(getHei(child->left), getHei(child->right)) + 1;
		return child;
	}
	BinNode<Elem>* LR_Rotate(BinNode<Elem>* r) {
		printf("LR_Rotate\n -");
		r->left = RR_Rotate(r->left);
		printf(" -");
		r = LL_Rotate(r);
		return r;
	}
	BinNode<Elem>* RL_Rotate(BinNode<Elem>* r) {
		printf("RL_Rotate\n -");
		r->right = LL_Rotate(r->right);
		printf(" -");
		r = RR_Rotate(r);
		return r;
	}
	BinNode<Elem>* r_insert( Elem x, BinNode<Elem>* r) {
		if (!r) {
			r = new BinNode<Elem>(x);
			if (!r) throw - 1;//No memory is availble
		}
		else if (x < r->data) { 
			r->left = r_insert(x, r->left);
			if (getHei(r->left) - getHei(r->right) == 2) {
				if (x < r->left->data) r = LL_Rotate(r);
				else r = LR_Rotate(r);
			}
		}
		else if (x > r->data) { 
			r->right = r_insert(x, r->right); 
			if (getHei(r->right) - getHei(r->left) == 2) {
				if (x >r->right->data) {
					r = RR_Rotate(r);
				}
				else {
					r = RL_Rotate(r);
				}
			}
		}
		else throw - 2;//Inserting existed element
		r->height = max(getHei(r->left), getHei(r->right)) + 1;
		//printf("%d\n", r->data);
		return r;
	}
	void r_fprint(BinNode<Elem>* r,int depth) {
		for (int i = 0; i < depth; i++)putchar(' ');
		if (r == nullptr) { printf("[/]\n"); return; }
		else printf("%d\n", r->data);
		r_fprint(r->left, depth + 1);
		r_fprint(r->right, depth + 1);
	}	
	void r_preprint(BinNode<Elem>* r) {
		if (r == nullptr)return;
		else printf("%d ", r->data);
		r_preprint(r->left);
		r_preprint(r->right);
	}	
	BinNode<Elem>* r_getMax(BinNode<Elem>* r) {
		if (!r)return nullptr;
		while (r->right) {
			r = r->right;
		}
		return r;
	}
public:
	Avl_Tree() {
		root = nullptr;
	}
	bool insert(int x) {
		try {
			root = r_insert(x,root);
		}
		catch (int e) {
			return false;
		}
		return true;
	}
	void f_print() {
		if (!root)return;
		r_fprint(root,0);
		putchar('\n');
	}
	void preprint() {
		r_preprint(root);
		putchar('\n');
	}
	
	BinNode<Elem>* getMax() {
		if (!root)throw - 1;
		return r_getMax(root);
	}
};