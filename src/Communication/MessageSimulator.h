/*
 * MessageSimulator.h
 *
 *  Created on: 26.05.2015
 *      Author: rkorb
 */

#ifndef MESSAGESIMULATOR_H_
#define MESSAGESIMULATOR_H_

#include <Communication/Connection.h>

class MessageSimulator : public Connection {
private:

public:
	MessageSimulator(int interval):Connection(interval){}
	~MessageSimulator() override {};
	bool initializeConnection();
	bool closeConnection();
	Message read() override;
	bool write(Message msg) override;
};


#endif /* MESSAGESIMULATOR_H_ */
