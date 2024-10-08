#pragma once
#include <iostream>
#include <mutex>
#include "node.h"

void FineGrainedQueue::insertIntoMiddle(int value, int pos){
	Node* newNode = new Node(value);
	
	queue_mutex.lock(); // теперь наш head нельзя будет поменять
	Node* current = head;

	// пустой список - новый узел в начало
	if(head == nullptr){
		head = newNode;
		queue_mutex.unlock();
		return;
	}
	
	// вставка в начало списка
	if(pos == 0){
		newNode->next = head;
		head = newNode;
		queue_mutex.unlock();
		return;
	}
	
	// лочим, когда head точно не пустой и не добаляем в начало
	current->node_mutex.lock();	
	queue_mutex.unlock();

	// в цикле идем по списку, пока список не кончится, или пока не дойдем до позиции
	int i = 0;
	while(i < pos -1 && current->next != nullptr){
		current->node_mutex.unlock();
		current = current->next;
		current->node_mutex.lock();
		i++;
	}
    
	// меняем указатель на следующий узел на указатель на новый узел
	Node* next = current->next;
	current->next = newNode;
	current->node_mutex.unlock();
		
	// связываем список обратно, меняем указатель на узел, следующий после нового узла, на указатель на узел, следующий за current
	newNode->next = next;	
}

// вспомогательные методы
void FineGrainedQueue::push_back(int value){  
	Node* node = new Node(value);
		
	if(head == nullptr){
		head = node;
		return;
	}

	Node* last = head;
	while(last->next != nullptr){
		last = last->next;
	}

	last->next = node;
	return;
}

void FineGrainedQueue::show(){
	Node* curr = head;
    while(curr != nullptr){
        std::cout << " " << curr->value;
        curr = curr->next;
    }
    std::cout << std::endl;
}
