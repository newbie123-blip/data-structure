#include<iostream>
using namespace std;

template<class T>
class chain;

template<class T>
class Stack;

template<class T>
class Queue;

template<class T>
class chainNode {
	friend chain<T>;
	friend Stack<T>;
	friend Queue<T>;
private:
	T data;
	chainNode<T>* link = nullptr;
public:
	chainNode() {}
	chainNode(const T& data) { this->data = data; }
	chainNode(const T& data, chainNode<T>* link) { this->data = data; this->link = link; }
};

template<class T>
class chain {
private:
	chainNode<T>* first;
public:
	chain() { first = 0; }
	~chain() {
		while (first != nullptr) {
			chainNode<T>* next = first->link;
			delete first;
			first = next;
		}
	}
};
template<class T>
class Stack {
private:
	chainNode<T>* header;
public:
	Stack() {
		header = new chainNode<T>();
		header->link = header;
	}

	void push(const T& ndata) {
		header->link = new chainNode<T>(ndata, header->link);
	}
	void pop() {
		chainNode<T>* delnode = header->link;
		header->link = delnode->link;
		delete delnode;
	}
	bool isempty() { return header->link == header; }

	void top() {
		cout << header->link->data << "\n";
	}
	void display() {
		if (!isempty()) {
			chainNode<T>* point = header->link;
			while (point != header) {
				cout << point->data << " -> ";
				point = point->link;
			}
			cout << "NULL\n";
		}
		else {
			cout << "空的stack\n";
		}
	}
};

template<class T>
class Queue {
private:
	chainNode<T>* front;
	chainNode<T>* rear;
public:
	Queue() {
		front = new chainNode<T>();
		front->link = front;
		rear = new chainNode<T>();
		rear = front;
		rear->link = front;
	}

	void push(const T& ndata) {
		chainNode<T>* newnode = new chainNode<T>(ndata, rear->link);
		rear->link = newnode;
		rear = newnode;

	}
	void pop() {
		chainNode<T>* delnode = front->link;
		front->link = delnode->link;
		delete delnode;
	}
	bool isempty() { return front->link == front; }

	void ffront() {
		cout << front->link->data << "\n";
	}

	void rrear() {
		cout << rear->data << "\n";
	}

	void display() {
		if (!isempty()) {
			chainNode<T>* point = front->link;
			while (point != front) {
				cout << point->data << " -> ";
				point = point->link;
			}
			cout << "NULL\n";
		}
		else {
			cout << "空的stack\n";
		}
	}
};

int main() {
	Queue<int> test;
	cout << "===== Queue Menu =====\n";
	cout << "1. Push\n";
	cout << "2. Pop\n";
	cout << "3. front\n";
	cout << "4. rear\n";
	cout << "5. isempty\n";
	cout << "6. display\n";
	cout << "7. Exit\n";
	cout << "choice : ";
	int x;
	while (cin >> x) {
		int temp = x;

		if (temp == 1) {
			int y;
			cout << "輸入 ";
			cin >> y;
			test.push(y);
		}
		else if (temp == 2) {
			test.pop();
		}
		else if (temp == 3) {
			test.ffront();
		}
		else if (temp == 4) {
			test.rrear();
		}
		else if (temp == 5) {
			test.isempty();
			if (test.isempty()) {
				cout << "空陣列\n";
			}
			else {
				cout << "不是空陣列\n";
			}
		}
		else if (temp == 6) {
			test.display();
		}
		else if (temp == 7) {
			break;
		}
		cout << "===== Queue Menu =====\n";
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. front\n";
		cout << "4. rear\n";
		cout << "5. isempty\n";
		cout << "6. display\n";
		cout << "7. Exit\n";
		cout << "choice : ";
	}

	return 0;
}
