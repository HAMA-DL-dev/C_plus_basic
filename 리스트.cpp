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
			for (int i = 1; i < capacity; i++) { // capacity-1 만큼 loop가 돈다.
				pTemp->pNext = new Node(i + 1);
				pTemp->pNext->pPrev = pTemp;
				pTemp = pTemp->pNext; // pTemp는 다음 노드로 넘어간다. 
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
	if (order <= (capacity / 2 + 1) && order > 0) {// 100개의 노드중 30번에 넣고 싶다면
		                                           // pHead부터 출발하는게 효율적이다. 이에 해당하는 구문
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
			for (int i = 0; i < (order - 2); i++) { // 앞서 노드가 한 개 존재하므로 -2. 
				pTemp = pTemp->pNext; //다음 노드로 넘어감
			}

			Node* pNewNode = new Node(data, pTemp->pNext, pTemp); // new node를 양단에 연결.
			                         // new node 양단의 노드가 가리키는 방향을 조절.     
			pTemp->pNext = pNewNode; // 새로 만든 노드가 pTemp의 Next값이 되도록 함
			pTemp->pNext->pPrev = pNewNode; // 반대로 새로만든 노드의 Prev값도 할당함. 
											// new node 양단의 노드가 가리키는 방향을 조절.
		}
		capacity++; // 리스트값 증가. 
		return true;
	}
	else if (order > (capacity / 2 + 1) && order <= capacity + 1) { // Tail에서 시작하는게 빠른 경우
		pTemp = pTail; // pTail에서부터 시작하라는 의미.
		if (order == capacity + 1) { // 순서가 capacity값에 다다른 경우
			pTail = new Node(data, NULL, pTemp);
			pTemp->pNext = pTail;
		}
		else {
			for (int i = 0; i < (capacity - order); i++) {
				pTemp = pTemp->pPrev; // 이전 노드로 넘어감. 
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
	delete pTemp; // pTemp를 삭제.
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
		pTemp = pTemp->pNext; // 다음값 출력을 위해 pNext 포인터 값을 대입 
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