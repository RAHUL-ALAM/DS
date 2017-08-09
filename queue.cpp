#include <iostream>
using namespace std;

class Queue
{
	int size;
	int capacity;
	int rear_i;
	int front_i;
	int* array;
public:
	Queue(int capacity);
	bool isfull();
	bool isempty();
	void enqueue(int data);
	int dequeue();
	int front();
	int rear();
};



int main()
{
	Queue q1(20);
	q1.enqueue(40);q1.enqueue(50);
	cout << q1.rear() <<endl;
	cout << q1.front() <<endl;
	q1.enqueue(60);q1.enqueue(70);q1.enqueue(90);
	cout << q1.rear() <<endl;
	cout << q1.front() <<endl;
	q1.dequeue();
	cout << q1.rear() <<endl;
	cout << q1.front() <<endl;

	return 0;
}


bool Queue::isfull(){
	return (size==capacity);
}

bool Queue::isempty(){
	return (size==0);
}

Queue::Queue(int capacity){
	this->capacity = capacity;
	this->size = 0;
	this->front_i = 0;
	this->rear_i = 0;
	this->array = new int[capacity];
}

void Queue::enqueue(int data){
	if(isfull()){
		cout<< "queue is full";
	}else{
		array[this->rear_i] = data;
		this->rear_i = (this->rear_i+1)%capacity;
		size ++;
	}
}

int Queue::dequeue(){
	if(isempty()){
		cout<< "queue is empty";
	}else{
		int x = array[this->front_i];
		this->front_i = (this->front_i+1)%capacity;
		size--;
	}
}

int Queue::front(){
	return array[front_i];
}

int Queue::rear(){
	return array[rear_i-1];
}