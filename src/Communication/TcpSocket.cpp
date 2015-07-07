/*
 * TcpSocket.cpp
 *
 *  Created on: 04.07.2015
 *      Author: rkorb
 */

#include <Communication/TcpSocket.h>
#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

bool TcpSocket::initializeConnection(){
	struct sockaddr_in servaddr;
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd < 0){
		std::cout << "Error Creating Socket" << std::endl;
		return false;
	}

	servaddr.sin_addr.s_addr = inet_addr(ip.c_str());
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons((unsigned short) port);

	if(::connect(fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
		std::cout << "Error connecting to socket" << std::endl;
	}
	return true;
}

bool TcpSocket::closeConnection(){
	close(fd);
	return true;
}

Message TcpSocket::read(){
	char buffer[512];
	int res = ::read(fd, &buffer, sizeof(buffer));
	buffer[res] = 0;
	std::string message(buffer);
	Message m(message);
	std::cout << "read " << m.getMessage() << res << std::endl;
	return m;
}

bool TcpSocket::write(Message msg){
	std::string message = msg.getMessage();
	int res = ::write(fd, message.c_str(), message.length());
	if(res != (int)message.length()){
		std::cout << "error on writing, " << res << " byte written" << std::endl;
		return false;
	}
	else return true;
}
