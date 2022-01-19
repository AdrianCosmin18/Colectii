#include"List.h"

template<typename T>
class Stack
{
private:
	Node<T>* top = NULL;

public:

	Node<T>* get_top() { return top; }

	void push(T t) {

		if (top == NULL) {

			Node<T>* node = new Node<T>();
			node->set_data(t);
			node->set_next(NULL);
			top = node;
		}
		else {

			Node<T>* node = new Node<T>();
			node->set_data(t);
			node->set_next(top);

			top = node;
		}
	}

	void pop() {

		//Node<T>* node = top->get_next();
		//top = node;

		top = top->get_next();
	}

	bool empty() {

		if (top == NULL) {

			return true;
		}
		return false;
	}

	int size() {

		int count = 0;
		Node<T>* node = top;
		while (node != NULL) {

			count++;
			node = node->get_next();
		}

		return count;
	}

	void traverse() {

		Node<T>* node = top;
		while (node != NULL) {

			cout <<(char)( node->get_data()) << endl;

			node = node->get_next();
		}
	}

};

