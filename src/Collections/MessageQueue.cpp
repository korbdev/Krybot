/*
 * MessageQueue.cpp
 *
 *  Created on: 21.05.2015
 *      Author: rkorb
 */

#include <Collections/MessageQueue.h>

void MessageQueue::push(const Message& msg){
	std::unique_lock<std::mutex> lock(monitorMutex);
	Message* m = new Message(msg.getMessage());
	queue.push(m);
	condition.notify_one();
}

Message MessageQueue::pop(){
	std::unique_lock<std::mutex> lock(monitorMutex);
	while(queue.empty()){
		condition.wait(lock);
	}
	Message* pmsg = queue.front();
	Message msg(pmsg->getMessage());
	queue.pop();
	delete pmsg;
	condition.notify_one();
	return msg;
}




