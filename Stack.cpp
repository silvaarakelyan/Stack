# Stack
#include<iostream>
#include <stdlib.h> 
using namespace std;

template <class T>
class Stack{
public:
	Stack();
	void push(T element);
	void  pop();
	bool isEmpty();
	void print();
	T get_top();
	int get_size();
	~Stack();

private:
	int m_size;
	int m_capacity;
	T*  m_array;
	void resize();
};

template <class T>
Stack<T>::Stack(){
	m_capacity = 4;
	m_size = 0;
	m_array = new T[m_capacity];

}

template <class T>
void Stack<T>::push(T element){

	if ((m_size + 1)>m_capacity)
	{
		resize();
	}

	m_size++;
	m_array[m_size - 1] = element;
}

template <class T>
void Stack<T>::resize(){
	m_capacity = 2 * m_capacity;

	T *temp = new T[m_capacity];
	//here we copy  new array 
	for (int i = 0; i<m_size; i++){
		temp[i] = m_array[i];
	}

	delete m_array;
	m_array = temp;

}

template <class T>
bool Stack<T>::isEmpty(){
	if (m_size == 0)
	{
		return true;
	}

	else return false;
}



template <class T>
void Stack<T>::pop(){
	bool x = isEmpty();

	if (x == true)
	{
		cout << "Stack is empty" << endl;

	}
	else

		cout << m_array[m_size - 1] << " poped from array" << endl;
	m_size--;

}

template <class T>
T Stack<T>::get_top(){
	cout << "Top element :";
	int x = isEmpty();

	if (x == true)
	{
		cout << "Stack is empty" << endl;

	}

	else if (x == false)
	{
		return m_array[m_size - 1];
	}

	return 0;

}

template <class T>
void Stack<T>::print(){
	int x = isEmpty();
	cout << "The stack is: ";
	if (x == true)
	{
		cout << "Stack is empty" << endl;
		return;
	}

	else
	{

		for (int i = 0; i<m_size; i++)
		{
			cout << m_array[i] << " ";
		}

	}
	cout << endl;
}

template <class T>
int Stack<T>::get_size()
{
	cout << "The size of stack is :";
	return m_size;
}


template <class T>
Stack<T>::~Stack()
{
	delete m_array;
}


int main(){
	Stack<int> s;
	s.print();
	s.push(5);
	s.print();
	s.push(10);
	s.print();
	s.push(15);
	s.print();
	s.push(25);
	s.push(35);
	s.print();
	s.pop();
	cout << s.get_top() << endl;
	s.print();
	s.pop();
	s.pop();
	s.print();
	s.pop();
	s.print();
	s.pop();
	s.print();
	cout << s.get_top() << endl;
	cout << s.get_size() << endl;
	cout << endl;
	//Implemention for double type
	Stack<double> d;
	d.print();
	d.push(1.5);
	d.print();
	d.push(15.2);
	d.print();
	d.push(15);
	d.print();
	d.push(25.2);
	d.push(35.2);
	d.print();
	d.pop();
	cout << s.get_top() << endl;
	d.print();
	d.pop();
	d.pop();
	d.print();
	d.pop();
	d.print();
	d.pop();
	d.print();
	cout << d.get_top() << endl;
	cout << d.get_size();

system("pause");


}