/*
 * MessageSimulator.h
 *
 *  Created on: 26.05.2015
 *      Author: rkorb
 */

#ifndef MESSAGESIMULATOR_H_
#define MESSAGESIMULATOR_H_

#include <Communication/Connection.h>
#include <Communication/MessageDistributor.h>

class MessageSimulator : public Connection {
public:
	MessageSimulator(int interval):Connection(interval){}
	~MessageSimulator() override {};
	bool connect() override;
	bool disconnect() override;
	Message read() override;
	bool write(Message msg) override;
	Message get() override;
};


#endif /* MESSAGESIMULATOR_H_ */
