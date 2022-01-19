#include"Person.h"

template<typename T>

class Node
{
private:

	T data;
	Node<T>* next;

public:

	T get_data() { return data; }
	Node<T>* get_next() { return next; }

	void set_data(T t) { data = t; }
	void set_next(Node<T>* n) { next = n; }
};

