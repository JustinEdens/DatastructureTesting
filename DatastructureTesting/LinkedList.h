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
		node* p = head;
		head = head->next;
		remove(p->data);
	}
	printf("LinkedList Destroyed!!!");
}

template <typename T>
void LinkedList<T>::remove(T value) {
	//check empty
	if (isEmpty()) {
		return;
	}
	//check head
	if (head->data == value) {
		node* p = head;
		head = head->next;
		delete p;
		return;
	}
	//check rest
	node* prev = head;
	node* cur = head->next;
	while (cur != NULL) {
		if (cur->data == value) {
			break;
		}
		cur = cur->next;
		prev = prev->next;
	}
	//cur is on value or null
	//if value is not in list
	if (cur == NULL)
		return;
	//if value is tail
	if (cur == tail) {
		tail = prev;
		tail->next = NULL;
		delete cur;
		return;
	}
	//if value is between head and tail
	prev->next = cur->next;
	cur->next = NULL;
	delete cur;
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

