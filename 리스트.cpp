#include <iostream>
class Node {
public:
	Node();
	Node(int data);
	Node(int data, Node* pNext, Node* pPrev);
	~Node();
	int getData();
	Node* pNext;
	Node* pPrev;
private:
	int data_;
};

Node::Node() :data_(0), pNext(NULL), pPrev(NULL) {}

Node::Node(int data) : data_(data), pNext(NULL), pPrev(NULL) {}

Node::Node(int data, Node* pNext, Node* pPrev) : data_(data), pNext(pNext), pPrev(pPrev) {}

Node::~Node(){}

int Node::getData() {
	return data_;
}

////////////////////////////////////////////////////////////////////////////////////////////

class DLinkedList {
public:
	DLinkedList();
	DLinkedList(int num_node);
	~DLinkedList();
	bool insertNode(int order, int data);
	bool deleteNode(int order);
	void printDLL();

private:
	int capacity;
	Node* pHead;
	Node* pTail;
};

DLinkedList::DLinkedList():capacity(0),pHead(NULL),pTail(NULL){}

DLinkedList::DLinkedList(int num_node) : capacity(num_node){
	if (capacity > 0) {
		pHead = new Node(1);
		Node* pTemp;
		pTemp = pHead;

		if (capacity > 1) {
			for (int i = 1; i < capacity; i++) { // capacity-1 ��ŭ loop�� ����.
				pTemp->pNext = new Node(i + 1);
				pTemp->pNext->pPrev = pTemp;
				pTemp = pTemp->pNext; // pTemp�� ���� ���� �Ѿ��. 
			}
		}
		pTail = pTemp;
}
	else {
		capacity = 0;
		std::cout << "Number of node must be greater than zero" << std::endl;
	}
	}

DLinkedList::~DLinkedList() {
	Node* pTemp = pHead;
	for (int i = 0; i < capacity; i++) {
		pTemp = pTemp->pNext;
		delete pHead;
		pHead = pTemp;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////

bool DLinkedList::insertNode(int order, int data) {
	Node* pTemp = pHead;
	if (order <= (capacity / 2 + 1) && order > 0) {// 100���� ����� 30���� �ְ� �ʹٸ�
		                                           // pHead���� ����ϴ°� ȿ�����̴�. �̿� �ش��ϴ� ����
		if (order == 1) {
			if (capacity == 0) {
				pHead = new Node(data);
				pTail = pHead;
			}
			else {
				pHead = new Node(data, pTemp, NULL);
				pTemp->pPrev = pHead;
			}
		}
		else {
			for (int i = 0; i < (order - 2); i++) { // �ռ� ��尡 �� �� �����ϹǷ� -2. 
				pTemp = pTemp->pNext; //���� ���� �Ѿ
			}

			Node* pNewNode = new Node(data, pTemp->pNext, pTemp); // new node�� ��ܿ� ����.
			                         // new node ����� ��尡 ����Ű�� ������ ����.     
			pTemp->pNext = pNewNode; // ���� ���� ��尡 pTemp�� Next���� �ǵ��� ��
			pTemp->pNext->pPrev = pNewNode; // �ݴ�� ���θ��� ����� Prev���� �Ҵ���. 
											// new node ����� ��尡 ����Ű�� ������ ����.
		}
		capacity++; // ����Ʈ�� ����. 
		return true;
	}
	else if (order > (capacity / 2 + 1) && order <= capacity + 1) { // Tail���� �����ϴ°� ���� ���
		pTemp = pTail; // pTail�������� �����϶�� �ǹ�.
		if (order == capacity + 1) { // ������ capacity���� �ٴٸ� ���
			pTail = new Node(data, NULL, pTemp);
			pTemp->pNext = pTail;
		}
		else {
			for (int i = 0; i < (capacity - order); i++) {
				pTemp = pTemp->pPrev; // ���� ���� �Ѿ. 
			}
			Node* pNewNode = new Node(data, pTemp, pTemp->pPrev);

			pTemp->pPrev = pNewNode;           
			pNewNode->pPrev->pNext = pNewNode;
			capacity++;
			return true;
		}
	
	}
	else {
		std::cout << "Inser order must be in 0< order<=" << capacity + 1 << "." << std::endl;
		return false;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////

bool DLinkedList::deleteNode(int order) {
	Node* pTemp = pHead;
	if ((order > 0) && order < (capacity / 2) + 1) { 
		for (int i = 0; i < order - 1; i++) {
			pTemp = pTemp->pNext;
		}
		if (order == 1) {
			pHead = pTemp->pNext;
			pHead->pPrev = NULL;
		}
		else {
			pTemp->pNext -> pPrev = pTemp->pPrev;
			pTemp->pNext->pPrev = pTemp->pNext;
		}
		capacity--;
		delete pTemp;
		return true;
	}


	else if (order >= (capacity / 2) + 1 && order < capacity + 1) {
		pTemp = pTail;
		for (int i = 0; i < (capacity - order); i++) {
			pTemp = pTemp->pPrev;
		}
		if (order == capacity) {
			if (capacity == 1) {
				pHead = NULL;
				pTail = NULL;
			}
			else {
				pTail = pTemp->pPrev;
				pTail->pNext = NULL;
			}
		}
	}
	else {
		pTemp->pPrev->pNext = pTemp->pNext;
		pTemp->pPrev->pNext = pTemp->pPrev;
	}
	capacity--;
	delete pTemp; // pTemp�� ����.
	return true;
}
else {
std::cout << "Delete order must be in 0 <order <=" << capacity << "." << std::endl;
return false;
}
	


void DLinkedList::printDLL() {
	Node* pTemp = pHead;
	for (int i = 0; i < capacity; i++) {
		std::cout << i + 1 << "th data: " << pTemp->getData() << std::endl;
		pTemp = pTemp->pNext; // ������ ����� ���� pNext ������ ���� ���� 
	}
	std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	DLinkedList test(20);
	test.printDLL();
	if (test.insertNode(3, 5)) {
		test.printDLL();
	}
	if (test.deleteNode(5)) {
		test.printDLL();
	}
	if (test.insertNode(1,11)) {
		test.printDLL();
	}
	if (test.insertNode(12,7)) {
		test.printDLL();
	}
	if (test.deleteNode(1)) {
		test.printDLL();
	}
	if (test.deleteNode(11)) {
		test.printDLL();
	}
	return 0;
}