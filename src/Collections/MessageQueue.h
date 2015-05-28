/*
 * MessageQueue.h
 *
 *  Created on: 21.05.2015
 *      Author: rkorb
 */

#ifndef MESSAGEQUEUE_H_
#define MESSAGEQUEUE_H_

#include <queue>
#include <mutex>
#include <condition_variable>
#include <Communication/Message.h>
#include <thread>

class MessageQueue {
private:
	std::queue<Message> 	queue;
	std::mutex 				monitorMutex;
	std::condition_variable condition;
public:
	void 					push(const Message& msg);
	Message 				pop();
};


#endif /* MESSAGEQUEUE_H_ */
