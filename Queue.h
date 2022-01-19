#include"Stack.h"

//empty //
//size
//front //
//back  //
//push_back //
//pop_front //

template<typename T>
class Queue
{
private:
	Node<T>* front = NULL;
	Node<T>* back = NULL;

public:

	Node<T>* get_front() { return front; }
	Node<T>* get_back() { return back; }

	void push_back(T t) {

		if (front == NULL) {

			Node<T>* node = new Node<T>();
			node->set_data(t);
			node->set_next(NULL);

			front = node;
			back = node;
		}
		else{

			Node<T>* node = new Node<T>();
			node->set_data(t);
			node->set_next(NULL);
			back->set_next(node);
			
			back = node;
		}
	}

	void pop_front() {

		front = front->next;
	}

	bool empty() {

		if (front == NULL) {

			return 1;
		}
		return 0;
	}

	int size() {


		if (front == NULL) {

			return 0;
		}
		else {

			Node<T>* node = back;
			int count = 0;
			while (node != NULL) {

				count++;
				node = node->get_next();
			}

			return count;
		}
	}


	void traverse() {

		Node<T>* node = front;
		while (node != NULL) {

			cout << node->get_data() << " ";
			node = node->get_next();
		}
	}


};

