/*
 * Connection.h
 *
 *  Created on: 21.05.2015
 *      Author: rkorb
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <Collections/ThreadingQueue.h>
#include <Communication/Message.h>
#include <thread>
#include <mutex>

class MessageDistributor;

class Connection{
private:
	std::thread t;
	bool connected;
	ThreadingQueue<Message>* queue;
protected:
	int interval;
	virtual bool initializeConnection() = 0;
	virtual bool closeConnection() = 0;
public:
	Connection(int interval, ThreadingQueue<Message>* queue);
	virtual ~Connection();
	bool connect();
	bool disconnect();
	virtual Message read() = 0;
	virtual bool write(Message msg) = 0;
	Message get();
	void test();
	virtual void operator()();
};


#endif /* CONNECTION_H_ */
