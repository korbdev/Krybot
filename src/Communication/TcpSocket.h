/*
 * TcpSocket.h
 *
 *  Created on: 04.07.2015
 *      Author: rkorb
 */

#ifndef SRC_COMMUNICATION_TCPSOCKET_H_
#define SRC_COMMUNICATION_TCPSOCKET_H_

#include <Communication/Connection.h>
#include <Communication/Message.h>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class TcpSocket : public Connection {
private:
	std::string ip;
	int port;
	int fd;
protected:
	virtual bool initializeConnection() override;
	virtual bool closeConnection() override;
public:
	TcpSocket(std::string ip, int port, int interval, ThreadingQueue<Message>* queue):Connection(interval, queue), ip(ip), port(port), fd(-1){}
	virtual Message read() override;
	virtual bool write(Message msg) override;
};


#endif /* SRC_COMMUNICATION_TCPSOCKET_H_ */
