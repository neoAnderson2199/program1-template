#include "List.h"
#include <cstdlib>

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
	s = 0;
}

List::~List(){
	Node* temp = head;
	while(temp != NULL){
		delete temp->data;
		temp = temp->next;
	}
}

void List::insert(int index, Planet *p){
	if(index < 0) return;
	Node* temp = new Node(p);
	if(head == NULL){
		head = temp;
		tail = temp;
		temp = NULL;
	}else if((unsigned)index >= s){
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		temp = NULL;
	}else{
		Node* now = head;		
		for(int i = 0; i < index; i ++){
			now = now->next;
		}
		temp->prev = now->prev;
		now->prev = temp;
		temp->next = now;
		if(head == now) head = temp;
		temp = NULL;
	}
	s++;
}

Planet* List::read(int index){
	if(index < 0) return NULL;
	if((unsigned)index >= s) return NULL;
	Node* now = head;
	for(int i = 0; i < index; i ++){
		now = now->next;
	}
	return now->data;
}

bool List::remove(int index){
	if(index < 0) return false;
	if((unsigned)index >= s) return false;
	Node* now = head;
	for(int i = 0; i < index; i++){
		now = now->next;
	}
	if(now->prev == NULL){
		if(now->next == NULL){
			head = NULL;
			tail = NULL;
		}else{
			head = now->next;
			(now->next)->prev = NULL;
		}
	}else{
		if(now->next == NULL){
			tail = now->prev;
			(now->prev)->next = NULL;
		}
		(now->prev)->next = now->next;
		(now->next)->prev = now->prev;
	}
	delete now->data;
	delete now;
	s--;
	return true;
}

unsigned List::size(){
	return s;
}




	