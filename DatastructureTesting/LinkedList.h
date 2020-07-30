#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void add(T value);
	void remove(T value);
	T find(T value);
	void print();
	bool isEmpty();
protected:
private:
	typedef struct node {
		T data;
		node* next;
	}node;

	node* head;
	node* tail;
};

template <typename T>
LinkedList<T>::LinkedList() {
	head = NULL;
	tail = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	while (head != NULL) {
		remove(head->data);
	}
}

template <typename T>
void LinkedList<T>::remove(T value) {
	//check empty
	if (isEmpty()) {
		return;
	}
	node* p = head;
	node* prev = head;
	while (p != NULL) {
		if (value == p->data) {
			break;
		}
		else {
			prev = p;
			p = p->next;
		}
	}
	if (p == NULL) return;
	//check head
	if (p == head) {
		head = head->next;
		delete p;
		return;
	}
	//if value is tail
	if (p == tail) {
		tail = prev;
		tail->next = NULL;
		delete p;
		return;
	}
	//if value is between head and tail
	prev->next = p->next;
	delete p;
	return;

}

template <typename T>
void LinkedList<T>::add(T value) {
	node* n = new node;
	n->data = value;
	n->next = NULL;

	if (head == NULL) {
		head = n;
		tail = n;
	}
	else {
		tail->next = n;
		tail = n;
	}
}

template <typename T>
T LinkedList<T>::find(T value) {
	if (isEmpty()) return NULL;
	node* p = head;
	while (p != NULL) {
		if (value == p->data) {
			return p->data;
		}
		else {
			p = p->next;
		}
	}
	//not found
	return NULL;
}

template <typename T>
void LinkedList<T>::print() {
	//check if empty
	if (isEmpty())
		return;
	node* p = head;
	while (p != NULL) {
		std::cout << p->data;
		p = p->next;
	}
	std::cout<<std::endl;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
	if (head == NULL) {
		return true;
	}
	return false;
}

#endif

