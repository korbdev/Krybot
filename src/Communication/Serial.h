/*
 * Serial.h
 *
 *  Created on: 08.06.2015
 *      Author: rkorb
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include <string>
#include <Communication/Message.h>
#include <Communication/Connection.h>

using namespace std;

class Serial : public Connection {
private:
	int baudrate;
	string path;
	int fd;
protected:
	virtual bool initializeConnection() override;
	virtual bool closeConnection() override;
public:
	Serial(int interval, int baudrate, string path):Connection(interval), baudrate(baudrate), path(path), fd(-1){}
	virtual Message read() override;
	virtual bool write(Message msg) override;
	char readByte();
};



#endif /* SERIAL_H_ */
