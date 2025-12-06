#include<iostream>
using namespace std;
template<typename T>
class Node
{ public:
	T val;
	Node<T>* next_ptr;
public:
	Node(T v,Node<T>*n= nullptr)
	{
		val = v;
		next_ptr = n;
	}
public:
	T retreive()
	{
		return val;
	}
public:
	Node<T>* getnext()
	{
		return next_ptr;
	}
public:
	void setval( T v)
	{
		val = v;
	}
public:
	void setnext(Node<T>*n)
	{
		next_ptr = n;
	}

	
};
template<typename T> 
class List {
public:
	Node<T>* list_head;
public:
	List()
	{
		list_head = nullptr;

	}
public:
	~List() {
		Node<T>* current = list_head;
		while (current != nullptr) {
			Node<T>* next = current->next_ptr;
			delete current;
			current = next;
		}
	}
public:
	bool empty()
	{
		return list_head == nullptr;
	}
public:
	Node<T>* head()
	{
		return list_head;
	}
public:
	int size()
	{
		int sz = 0;
		Node<T>* temp = list_head;
		while (temp != nullptr)
		{
			sz++;
			temp = temp->next_ptr;
		}
		return sz;

	}
public:
	int count(T val)
	{
		int cnt = 0;
		Node<T>* temp = list_head;
		while (temp != nullptr)
		{
			if (temp->retreive() == val)
			{
				cnt++;

			}
			temp = temp->next_ptr;
		}
		return cnt;
	}
public:
	void push_front(T val)
	{
		list_head = new Node<T>(val, list_head);
	}
public:
	void push_back(T val)
	{
		if (empty())
		{
			push_front(val);
			return;
		}
		Node<T>* temp = list_head;
		while (temp->next_ptr != nullptr)
		{
			temp = temp->next_ptr;
		}
		Node<T>* newnode = new Node<T>(val, nullptr);
		temp->next_ptr = newnode;
	}
public:
	T pop_front()
	{
		if (empty())
		{
			throw runtime_error("Cant pop list is empty");
		}
		Node<T>* temp = list_head;
		T v = temp->retreive();
		list_head = list_head->next_ptr;
		delete temp;
		return v;

	}
public:
	T pop_back()
	{
		if (empty())
		{

			throw runtime_error("Cant pop list empty");
		}
		else if (list_head->next_ptr == nullptr)
		{
			return pop_front();
		}
		Node<T>* prev = nullptr;
		Node<T>* temp = list_head;
		while (temp->next_ptr != nullptr)
		{
			prev = temp;
			temp = temp->next_ptr;
		}
		T v = temp->retreive();
		prev->next_ptr = nullptr;


		delete temp;
		return v;

	}
	int search(T val)

	{int idx = 0;
     Node<T>* temp = list_head;
     while (temp != nullptr)
{     if (temp->retreive() == val)
      {
				return idx;

			}
			idx++;
			temp = temp->next_ptr;

		}
		return -1;
	}




	void erase(T val)

	{
		if (empty())

		{

			throw runtime_error("Can't erase the value list is empty");}

		while (list_head != nullptr && list_head->retreive() == val)
		{

			pop_front();

		}

		if (list_head == nullptr) {

			return;

		}
		Node<T>* prev = list_head;
		Node<T>* temp = list_head->next_ptr;
		while (temp != nullptr)
		{
			if (temp->retreive() == val)

			{

				prev->next_ptr = temp->next_ptr;

				delete temp;

				temp = prev->next_ptr;

			}

			else

			{prev = temp;
temp = temp->next_ptr;

			}

		}

	}
	void insert(T val, int pos)
	{
		if (pos < 0) {
			throw out_of_range("Position cannot be negative");
		}
		if (pos == 0) {
			push_front(val);
			return;
		}
		Node<T>* temp = list_head;
		for (int i = 0; i < pos - 1; i++)
		{
			temp = temp->next_ptr;
		}
		Node<T>* next = temp->next_ptr;
		temp->next_ptr = new Node<T>(val, next);

	}

	void print()
	{
		Node<T>* temp = list_head;
		while(temp!=nullptr)
		{
			cout << temp->retreive() << " ";
			temp = temp->next_ptr;
		}
		cout << endl;
	}
	
};
int main()
{
	List<int> l;
	l.push_front(10);
	l.push_front(5);
	l.push_back(20);
	l.insert(15, 2);
	cout << "Printing list after pushing elements:";
		l.print();
		int el=l.pop_back();
		cout << "List after popping back"<<el<<":";
		l.print();
		l.push_front(50);
		l.push_front(50);
		cout << "The number of times 50 occurs is :" <<l.count(50);
		cout << endl;
		cout << "List after adding new elements in beginning :";
		l.print();
		l.erase(50);
		cout << "List after erasing 50 :";
		l.print();
		cout << "Size of list is :" << l.size();
		cout << endl;



}