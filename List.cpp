#include "List.h"

Node::Node(){
	data = NULL;
	prev = NULL;
	next = NULL;
};

Node::Node(Planet* element){
	data = element;
	prev = NULL;
	next = NULL;
}

List::List(){
	head = NULL;
	tail = NULL;
	int size = 0;
}

List::~List(){
	Node* temp = head;
	while(temp != NULL){
		temp = temp->next;
		delete temp;
	}
}

void List::insert(int index, Planet *p){
	Node* temp = new Node(p);
	if(head == NULL){
		head = temp;
		tail = temp;
		temp = NULL;
	}
	if(index < 0 && index >= size){
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		temp = NULL;
		size ++;
	}else{
		if(Node = NULL) 
		Node*temp = head;		
		for(int i = 0; i <= index; i ++){
			
		
		
