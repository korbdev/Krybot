/*
 * MessageQueue.cpp
 *
 *  Created on: 21.05.2015
 *      Author: rkorb
 */

#include <Collections/MessageQueue.h>

void MessageQueue::push(const Message& msg){
	std::unique_lock<std::mutex> lock(monitorMutex);
	queue.push(msg);
	condition.notify_one();
}

Message MessageQueue::pop(){
	std::unique_lock<std::mutex> lock(monitorMutex);
	while(queue.empty()){
		condition.wait(lock);
	}
	Message msg = queue.front();
	queue.pop();
	condition.notify_one();
	return msg;
}




