/*
 * Status.h
 *
 *  Created on: 19.06.2015
 *      Author: rkorb
 */

#ifndef STATUS_H_
#define STATUS_H_

#include <Collections/ThreadingQueue.h>

template<class T>
class ThreadingQueue;

template<class T>
class Status : public ThreadingQueue<T>{
private:
	virtual void push(const T& msg) override;
	virtual T pop() override;
public:
	virtual ~Status(){}
};

template<class T>
T Status<T>::pop(){
	T* item = ThreadingQueue<T>::queue.front();
	T result(*item);
	ThreadingQueue<T>::queue.pop();
	delete item;
	return result;
}

template<class T>
void Status<T>::push(const T& item){
	T* t = new T(item);

	if(!ThreadingQueue<T>::queue.empty()){
		pop();
	}
	ThreadingQueue<T>::queue.push(t);
}

#endif /* STATUS_H_ */
