#include <iostream>
using namespace std;

class treenode {
	friend class bstree;
private:
	int key;
	char data;
	treenode* pleft;
	treenode* pright;
public:
	char readdata() { return data; }
	int readkey() { return key; }
	treenode* getleft() { return pleft; }
	treenode* getright() { return pright; }
	treenode(int val, char Data);

};

treenode::treenode(int val,char Data):key(val),data(Data),pleft(NULL),pright(NULL){}

class bstree {
private:
	treenode* proot;
public:
	bstree();
	bstree(int val, char Data);
	~bstree();
	treenode* getroot();
	treenode* insertnode(treenode* root, int val, char Data);
	void PrintPreorder(treenode* t);
	void PrintInorder(treenode* t);
	void PrintPostorder(treenode* t);
	void visit(treenode* t);
};

bstree::bstree():proot(NULL){}
bstree::~bstree() { delete proot; }
treenode* bstree::getroot() {
	return proot;
}

treenode* bstree::insertnode(treenode* root, int val, char Data) {
	if (root == NULL) {
		root = new treenode(val, Data);
	}
	else {
		if (val <= root->key) {
			root->pleft = insertnode(root->pleft, val, Data);
		}
		else {
			root->pright = insertnode(root->pright, val, Data);
		}
	}
	return root;
}

void bstree::PrintPreorder(treenode* t) {
	if (t != NULL) {
		visit(t);
		PrintPreorder(t->getleft());
		PrintPreorder(t->getright());
	}
}

void bstree::PrintInorder(treenode* t) {
	if (t != NULL) {
		PrintInorder(t->getleft());
		visit(t);
		PrintInorder(t->getright());

	}
}

void bstree::PrintPostorder(treenode* t){
	if (t != NULL) {
		PrintPostorder(t->getleft());
		PrintPostorder(t->getright());
		visit(t);
	}
}

void bstree::visit(treenode* t) {
	cout << "key value : " << t->readkey() << endl;
	cout << "data : " << t->readdata() << endl;
	cout << "left child : " << t->getleft() << endl;
	cout << "right child : " << t->getright() << endl;
	cout << endl;
}

int main() {
	bstree a(15, 'a');
	a.insertnode(a.getroot(), 10, 'b');
	a.insertnode(a.getroot(), 20, 'c');
	a.insertnode(a.getroot(), 8, 'd');
	a.insertnode(a.getroot(), 12, 'e');
	a.insertnode(a.getroot(), 17, 'f');
	a.insertnode(a.getroot(), 5, 'g');
	a.insertnode(a.getroot(), 9, 'h');
	a.insertnode(a.getroot(), 13, 'i');
	a.insertnode(a.getroot(), 19, 'j');

	cout << "---------------PreOrder------------" << endl;
	a.PrintPreorder(a.getroot());
	cout << "---------------InOrder------------" << endl;
	a.PrintInorder(a.getroot());
	cout << "---------------PostOrder------------" << endl;
	a.PrintPostorder(a.getroot());

}