#include <iostream>
using namespace std;

class Node
{	
public:
	int data;
	Node* next;
	Node(int data);
};

class List
{
	Node* head;
public:
	List();
	void addNode(int data);
	bool isempty();
	Node* front();
	Node* top();
	// void del();
	void display();
};



int main()
{
	List l1;
	l1.addNode(5);
	l1.addNode(8);
	l1.addNode(11);
	l1.addNode(135);
	Node* a = l1.front();
	// l1.display();
	cout << a->data<<endl;
	a = l1.top();
	cout << a->data<<endl;
	l1.display();

	return 0;
}


Node::Node(int data){
	this->data = data;
	this->next = NULL;
}

List::List(){
	head=NULL;
}

void List::addNode(int data){
	if(head==NULL)
		head=new Node(data);
	else{
		Node* temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = new Node(data);
	}
}

bool List::isempty(){
	return (head==NULL);
}

Node* List::front(){
	if(!isempty())
		return head;
	else
		cout<<"empty list"<<endl;
}

Node* List::top(){
	if(!isempty()){
		Node* temp = head;
		while(temp->next!=NULL)
			temp = temp->next;
		return temp;
	}
	else
		cout<<"empty list"<<endl;
}

// Node* List::pop(){
// 	if(!isempty()){
// 		Node* current = head;
// 		Node* prev = NULL;
// 		while(current->next!=NULL){
// 			prev = current;
// 			current = current->next;
// 		}
// 		prev->next = current->next;
// 		Node* toreturn = new Node(current->data);
// 		delete current;
// 		return toreturn;
// 	}
// 	else{
// 		cout<<"empty list"<<endl;
// 	}
// }

void List::display(){
	if(!isempty()){
		Node* temp = head;
		while(temp != NULL){
			cout<< temp->data <<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	else{
		cout<<"empty list"<<endl;
	}
}
