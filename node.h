#pragma once
#include <mutex>

struct Node{
	int value;
	Node* next;
	std::mutex node_mutex;
	
	Node(int _value) : value(_value), next(nullptr) {
		//std::mutex* node_mutex = new std::mutex;
	}
};

class FineGrainedQueue{
	Node* head;
	std::mutex queue_mutex;

	public:
		FineGrainedQueue() : head(nullptr){
			//std::mutex* queue_mutex = new std::mutex;
		}

		void push_back(int value);
		void insertIntoMiddle(int value, int pos);
		void show();
};
