/*
 * ThreadingQueue.h
 *
 *  Created on: 18.06.2015
 *      Author: rkorb
 */

#ifndef THREADINGQUEUE_H_
#define THREADINGQUEUE_H_

#include <queue>
#include <mutex>
#include <condition_variable>
#include <Communication/Message.h>
#include <thread>

template<class T>
class ThreadingQueue {
private:
	virtual void push(const T& item) = 0;
	virtual T pop() = 0;
protected:
	std::queue<T*> 	queue;
	std::mutex 				monitorMutex;
	std::condition_variable condition;
public:
	virtual ~ThreadingQueue(){}
	void s_push(const T& item);
	T s_pop();
};

template<class T>
void ThreadingQueue<T>::s_push(const T& item){
	std::unique_lock<std::mutex> lock(monitorMutex);
	push(item);
	condition.notify_one();
}

template<class T>
T ThreadingQueue<T>::s_pop(){
	std::unique_lock<std::mutex> lock(monitorMutex);
	while(queue.empty()){
		condition.wait(lock);
	}
	T item = pop();
	condition.notify_one();
	return item;
}

#endif /* THREADINGQUEUE_H_ */
