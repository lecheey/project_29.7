#include <iostream>
#include "node.h"
#include <thread>
#include <future>

void addvalue(FineGrainedQueue& _x, int a, int b){
	_x.insertIntoMiddle(a,b); // в середину
}

int main(){
	FineGrainedQueue x;
	
	for(int i = 0; i < 20; i++){
		x.push_back(11); // случайный список
	}

	// через фьючерсы
	std::future<void> t1 = std::async(std::launch::async, [&](){
		addvalue(x, 55, 10); // в середину
	});
	std::future<void> t2 = std::async(std::launch::async, [&](){
		addvalue(x, 33, 30); // в середину
	});
	std::future<void> t3 = std::async(std::launch::async, [&](){
		addvalue(x, 44, 0); // в середину
	});

	t1.wait();
	t2.wait();
	t3.wait();
	
/*
	// через потоки
	std::thread t1(addvalue, std::ref(x), 55, 10); // в середину
	std::thread t2(addvalue, std::ref(x), 33, 30); // в конец
	std::thread t3(addvalue, std::ref(x), 44, 0); // в начало

	t1.join();
	t2.join();
	t3.join();
*/	

	x.show();

	return 0;
}
