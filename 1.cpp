#include <iostream>
using namespace std;

class Node
{

public:
	int vertex_no;
	Node* next;
	Node(int vertex_no);
};

class List
{
	Node* head;
public:
	List();
	void push_back_Node(int vertex_no);
	bool isempty();
	Node* top();
	void remove_top();
	Node* front();
	void remove_front();
};

class Graph
{
	int vertices;
public:
	List* listarray;
	Graph(int vertices);
	void addEdge(int v1, int v2);
	void BFS(int vertex_no);
	void DFS(int vertex_no);
	void display();
};



int main()
{
	Graph g(4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 4);

	g.BFS(3);
	cout<<endl;
	g.DFS(3);
	cout<<endl;

	return 0;
}




Node::Node(int vertex_no){
	this->vertex_no = vertex_no;
	this->next = NULL;
}

List::List(){
	this->head = NULL;
}

void List::push_back_Node(int vertex_no){
	if(this->head==NULL)
		this->head = new Node(vertex_no);
	else{
		Node* temp = this->head;
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next = new Node(vertex_no);
	}
}

bool List::isempty(){
	return (this->head==NULL);
}

Node* List::top(){
	if(!isempty()){
		Node* temp = this->head;
		while(temp->next!=NULL)
			temp = temp->next;
	
		return temp;
	}else{
		return NULL;
	}
}

void List::remove_top(){
	Node* current = this->head;
	if(current->next==NULL){
		delete current;
		this->head=NULL;
	}
	else
	{
		Node* prev = NULL;
		while(current->next!=NULL){
			prev = current;
			current = current->next;
		}

		prev->next = NULL;
		delete current;
	}
}

Node* List::front(){
	if(!isempty()){
		return this->head;
	}else{
		return NULL;
	}
}

void List::remove_front(){
	Node* temp = this->head;
	this->head = temp->next;
	delete temp;
}


Graph::Graph(int vertices){
	this->vertices = vertices;
	this->listarray = new List[vertices];

	for (int i = 0; i < vertices; ++i)
	{
		listarray[i].push_back_Node(i+1);
	}
}

void Graph::addEdge(int v1, int v2){
	listarray[v1-1].push_back_Node(v2);
}

void Graph::BFS(int vertex_no){
	bool *visited = new bool[vertex_no];
	for (int i = 0; i < vertex_no; ++i)
	{
		visited[i] = false;
	}

	List queue;
	visited[vertex_no-1] = true;
	queue.push_back_Node(vertex_no);

	while(!queue.isempty()){
		int c = queue.front()->vertex_no;
		cout<<c<<" ";
		queue.remove_front();

		Node* temp = listarray[c-1].front();
		while(temp->next!=NULL){
			if(!visited[temp->next->vertex_no-1]){
				queue.push_back_Node(temp->next->vertex_no);
				visited[temp->next->vertex_no-1]=true;
			}
			temp = temp->next;
		}
	}

}

void Graph::DFS(int vertex_no){
	bool *visited = new bool[vertex_no];
	for (int i = 0; i < vertex_no; ++i)
	{
		visited[i] = false;
	}

	List stack;
	stack.push_back_Node(vertex_no);

	while(!stack.isempty()){
		int c = stack.top()->vertex_no;
		stack.remove_top();

		if(!visited[c-1]){
			cout<<c<<" ";
			visited[c-1]=true;
		}

		Node* temp = listarray[c-1].front();
		while(temp->next != NULL){
			if(!visited[temp->next->vertex_no-1])
				stack.push_back_Node(temp->next->vertex_no);
			temp = temp->next;
		}
	}
}

void Graph::display(){
	for(int i=0; i<this->vertices; i++){
		Node* temp = listarray[i].front();
		while(temp!=NULL){
			cout << temp->vertex_no << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

