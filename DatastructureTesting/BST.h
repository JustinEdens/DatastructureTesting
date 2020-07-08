#ifndef _BST_H
#define _BST_H

template <typename T>
class BST
{
public:
	BST();
	~BST();
	void add(T value);
	void remove(T value);
	T find(T value);
	void print();
	bool isEmpty();
protected:
private:
	typedef struct node {
		T data;
		node* left;
		node* right;
	}node;

	node* root;
	void print(node* p);
};

template <typename T>
BST<T>::BST() {
	root = NULL;
}

template <typename T>
BST<T>::~BST() {
	while (!isEmpty()) {
		remove(root->data);
	}
	printf("BST Destroyed!!!");
}

template <typename T>
void BST<T>::remove(T value) {
	//check empty
	if (isEmpty()) {
		return;
	}
	//find target
	node* target = root;
	node* beforeT = root;
	while (target->data != value) {
		if (value > target->data) {
			if (target->right == NULL) {
				return;
			}
			beforeT = target;
			target = target->right;
		}
		else if (value < target->data) {
			if (target->left == NULL) {
				return;
			}
			beforeT = target;
			target = target->left;
		}
	}

	//checks left side
	if (target->left != NULL) {
		//move left then right
		node* p = target->left;
		node* parent = target;

		while (p->right != NULL) {
			parent = p;
			p = p->right;
		}
		T temp = p->data;
		//check if theres a left node
		if (p->left != NULL) {
			if (parent->data > p->data) {
				parent->left = p->left;
			}
			else if(parent->data < p->data) {
				parent->right = p->left;
			}
		}
		else {
			if (parent->data > p->data) {
				parent->left = NULL;
			}
			else if (parent->data < p->data) {
				parent->right = NULL;
			}
		}
		//swap data with root
		target->data = temp;
		//delete target
		delete p;
	}
	//checks right side if theres no left side
	else if (target->right != NULL) {
		//move right then left
		node* p = target->right;
		node* parent = target;

		while (p->left != NULL) {
			parent = p;
			p = p->left;
		}
		T temp = p->data;
		//check if theres a right node
		if (p->right != NULL) {
			if (parent->data > p->data) {
				parent->left = p->right;
			}
			else if (parent->data < p->data) {
				parent->right = p->right;
			}
		}
		else {
			if (parent->data > p->data) {
				parent->left = NULL;
			}
			else if (parent->data < p->data) {
				parent->right = NULL;
			}
		}
		//swap data with root
		target->data = temp;
		//delete target
		delete p;
	}
	//check leaf
	else if (target->left == NULL && target->right == NULL) {
		if (target == root) {
			root = NULL;
			delete target;
		}
		else {
			if (beforeT->data > target->data) {
				beforeT->left = NULL;
			}
			else if (beforeT->data < target->data) {
				beforeT->right = NULL;
			}
			delete target;
		}
		return;
	}
}

template <typename T>
T BST<T>::find(T value) {
	node* p = root;
	while (true) {
		if (p->data == value) {
			return p->data;
		}
		else if (value > p->data) {
			if (p->right != NULL) {
				p = p->right;
			}
			else {
				return NULL;
			}
		}
		else if (value < p->data) {
			if (p->left != NULL) {
				p = p->left;
			}
			else {
				return NULL;
			}
		}
	}
}

template <typename T>
void BST<T>::add(T value) {
	node* n = new node;
	n->data = value;
	n->left = NULL;
	n->right = NULL;

	//check empty
	if (isEmpty()) {
		root = n;
	}
	else {
		node* p = root;
		//while for finding node where the new item should be added
		while (true) {
			if (value > p->data) {
				if (p->right != NULL) {
					p = p->right;
				}
				else {
					//spot found
					p->right = n;
					return;
				}
			}
			else if (value < p->data) {
				if (p->left != NULL) {
					p = p->left;
				}
				else {
					//spot found
					p->left = n;
					return;
				}
			}
		}
	}
}

template <typename T>
void BST<T>::print() {
	//check if empty
	if (isEmpty())
		return;
	node* p = root;
	print(p);
	std::cout << std::endl;
}

template <typename T>
void BST<T>::print(node* p) {
	std::cout << p->data << ",";
	if (p->left != NULL) {
		print(p->left);
	}
	else if (p->left == NULL) {
		std::cout << "NULL,";
	}
	if (p->right != NULL) {
		print(p->right);
	}
	else if (p->right == NULL) {
		std::cout << "NULL,";
	}
}

template <typename T>
bool BST<T>::isEmpty() {
	if (root == NULL) {
		return true;
	}
	return false;
}

#endif