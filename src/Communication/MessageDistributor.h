/*
 * MessageDistributor.h
 *
 *  Created on: 26.05.2015
 *      Author: rkorb
 */

#ifndef MESSAGEDISTRIBUTOR_H_
#define MESSAGEDISTRIBUTOR_H_

#include <Communication/Connection.h>

class Connection;

class MessageDistributor{
private:
	Connection* connection;
public:
	MessageDistributor(Connection* con);
	void operator()();
};
#endif /* MESSAGEDISTRIBUTOR_H_ */
