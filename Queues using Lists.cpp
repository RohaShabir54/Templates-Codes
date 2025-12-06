#include<iostream>
using namespace std;
template <typename T> class Queue;
template<typename T>
class Node
{   private:
	T value;
	Node<T>*next_ptr;
public:
	Node(T val)
	{
		value = val;
		next_ptr = nullptr;
	}
	friend class Queue<T>;
};
template<typename T>
class Queue
{
	Node<T>*head;
	Node<T>*tail;
public:
	Queue()
	{
		head = tail = nullptr;
	}
public:
	bool empty()
	{
		return head == nullptr;
	}
public:
	void push( T val)
	{
		Node<T>*newnode = new Node<T>(val);
		if(empty())
		{
			head = tail = newnode;
		}
		else
		{
			tail->next_ptr = newnode;
			tail = newnode;

		}
	}
public:
	void pop()
	{ if(empty())
	{
		throw runtime_error("Queue is empty");
	}
	Node<T>*temp = head;
	head = head->next_ptr;
	delete temp;
	}
	T front()
	{
		return head->value;
	}
public:
	void print()
	{
		Node<T>* temp = head;
		while(temp!=nullptr)
		{
			cout << temp->value << " ";
			temp = temp->next_ptr;
		}
	}


};
int main() {
	Queue<int>q1;
	q1.push(10);
	q1.push(25);
	q1.push(50);
	cout << "Values is queue :";
	q1.print();
	cout << endl;
	q1.pop();
	cout << "The value at front of queue after popping is :" << q1.front();
	return 0;
}