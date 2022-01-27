#include"Queue.h"

template<typename T>
class Set
{
private:
	Node<T>* head = NULL;
public:

	Node<T>* get_head() { return head; }

	void traverse() {

		Node<T>* itr = head;
		while (itr != NULL) {

			cout << *(itr->get_data()) << endl;
			itr = itr->get_next();
		}
	}

	Node<T>* get_last() {

		Node<T>* itr = head;
		Node<T>* last = head;
		while (itr != NULL) {

			last = itr;
			itr = itr->get_next();
		}

		return last;
	}

	int indexOf(T t) {

		int index = -1;
		Node<T>* itr = head;
		while (itr != NULL) {

			index++;
			if (itr->get_data()->operator==(*t)) {

				return index;
			}

			itr = itr->get_next();
		}

		return -1;
	}

	Node<T>* get_node_by_index(int index) {

		int poz = -1;
		Node<T>* itr = head;
		while (itr != NULL) {

			poz++;
			if (poz == index) {

				return itr;
			}
			itr = itr->get_next();
		}
		return NULL;
	}

	bool isEmpty() {

		if (head == NULL) {

			return true;
		}
		return false;
	}

	int size() {

		int count = 0;
		Node<T>* itr = head;
		while (itr != NULL) {

			count++;
			itr = itr->get_next();
		}
		return count;
	}

	bool contains(T t) {

		Node<T>* itr = head;
		while (itr != NULL) {

			if (itr->get_data()->operator==(*t)) {

				return true;
			}
			itr = itr->get_next();
		}
		return false;
	}

	void add(T t) {

		if (!contains(t)) {

			if (head == NULL) {

				Node<T>* itr = new Node<T>();
				itr->set_data(t);
				itr->set_next(NULL);
				head = itr;
			}
			else {


				Node<T>* iterator = head;
				Node<T>* prev = NULL;

				while (iterator != NULL && iterator->get_data()->operator<(*t)) {

					prev = iterator;
					iterator = iterator->get_next();
				}


				if (prev == NULL) {

					Node<T>* aux = new Node<T>();
					aux->set_data(t);
					aux->set_next(head);
					head = aux;
				}
				else if (iterator != NULL && prev != NULL) {


					Node<T>* aux = new Node<T>();
					aux->set_data(t);
					aux->set_next(prev->get_next());
					prev->set_next(aux);
				}
				else if (iterator == NULL) {

					Node<T>* aux = new Node<T>();
					aux->set_data(t);
					aux->set_next(NULL);
					prev->set_next(aux);
				}
			}
		}
	}

	void remove_first() {

		Node<T>* aux = head;
		this->head = this->head->get_next();
		delete aux;
	}

	void remove(int index) {

		Node<T>* node = get_node_by_index(index);
		Node<T>* priv = get_node_by_index(index - 1);

		priv->set_next(node->get_next());
	}

	void remove(T t) {

		int poz = indexOf(t);
		if (poz == -1) {

			cout << "\nNu exista aceasta persoana";
		}
		else {

			Node<T>* node = get_node_by_index(poz);
			Node<T>* priv = get_node_by_index(poz - 1);

			priv->set_next(node->get_next());
		}
	}
	
	//maximul si minumul

};

