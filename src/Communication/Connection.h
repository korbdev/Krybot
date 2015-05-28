/*
 * Connection.h
 *
 *  Created on: 21.05.2015
 *      Author: rkorb
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <Collections/MessageQueue.h>
#include <Communication/MessageDistributor.h>
#include <Communication/Message.h>
#include <thread>
#include <mutex>

class MessageDistributor;

class Connection{
protected:
	MessageQueue queue;
	bool connected;
	int interval;
	std::thread t;
public:
	Connection(int interval);
	virtual ~Connection();
	virtual bool connect() = 0;
	virtual bool disconnect() = 0;
	virtual Message read() = 0;
	virtual bool write(Message msg) = 0;
	virtual Message get() = 0;
	void test();
	virtual void operator()();
};


#endif /* CONNECTION_H_ */
