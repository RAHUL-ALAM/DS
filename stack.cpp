#include <iostream>
using namespace std;

class Stack
{
	int max_size;         //lenght of stack;
	int current_size;
	int* array;
public:
	Stack(int l);
	int top();
	int pop();
	void push(int data);
	bool isempty();
	bool isfull();
};


int main()
{
	Stack s1(10);
	s1.push(1);
	s1.push(2);
	s1.push(15);
	cout<<s1.top()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.top()<<endl;
	cout<<s1.isempty()<<"-"<<s1.isfull()<<endl;
	return 0;
}




Stack::Stack(int l){
	this->max_size = l;
	this->current_size = 0;
	this->array = new int[l];
}

bool Stack::isempty(){
	return (current_size==0);
}

bool Stack::isfull(){
	return (current_size==max_size);
}

int Stack::top(){
	if(isempty())
		cout<< "Stack is empty"<<endl;
	else
		return array[current_size-1];
}

void Stack::push(int data){
	if(isfull())
		cout<<"Stack is full"<<endl;
	else
		array[current_size++] = data;
}

int Stack::pop(){
	if(isempty())
		cout<<"Stack is empty"<<endl;
	else
		return array[--current_size]; 
}