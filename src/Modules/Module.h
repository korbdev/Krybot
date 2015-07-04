/*
 * Module.h
 *
 *  Created on: 09.06.2015
 *      Author: rkorb
 */

#ifndef MODULE_H_
#define MODULE_H_

#include <string>
#include <Communication/Message.h>
#include <Communication/Connection.h>

using namespace std;

class Module{
protected:
	Connection* connection;
	bool running;
	thread t;
public:
	Module():connection(0),running(false){}
	Module(Module& other) = delete;
	Module& operator=(Module& other) = delete;
	virtual ~Module();
	virtual void processMessage(Message msg) = 0;
	void start(Connection* connection, int interval);
	void stop();
	void operator()(int interval);
	bool isRunning() const;
	string getName() const;
};


#endif /* MODULE_H_ */
