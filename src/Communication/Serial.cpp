/*
 * Serial.cpp
 *
 *  Created on: 08.06.2015
 *      Author: rkorb
 */

#include <Communication/Serial.h>
#include <termios.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unistd.h>

bool Serial::initializeConnection(){
	struct termios serial;

	fd = open(path.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);

	if(fd == -1){
		std::cout << "could not open file" << std::endl;
		return false;
	}

	if (tcgetattr(fd, &serial) < 0){
		std::cout << "could not get settings" << std::endl;
		return false;
	}

	serial.c_iflag = 0;
	serial.c_oflag = 0;
	serial.c_lflag = 0;
	serial.c_cflag = 0;
	serial.c_cc[VMIN] = 0;
	serial.c_cc[VTIME] = 0;

	serial.c_cflag = B9600 | CS8| CREAD | CSTOPB;
	tcsetattr(fd, TCSANOW, &serial);
	return true;
}

bool Serial::closeConnection(){
	close(fd);
	return true;
}

bool Serial::write(Message msg){
	string message = msg.getMessage();

	std::cout << "write " << msg.getMessage() << std::endl;
	unsigned int wcount = 0;
	while(wcount < message.length()){
		wcount = ::write(fd, &message, message.length());
	}
	std::cout << "written " << wcount << std::endl;
	return false;
}

Message Serial::read(){
	string message = "";
	if(char byte = readByte() == 0x02){
		bool completed = false;
		while(!completed){
			byte = readByte();
			if(byte == 0x03){
				completed = true;
			}
			else{
				message += byte;
			}
		}
	}
	Message m(message);
	std::cout << "read " << m.getMessage() << std::endl;
	return m;
}

char Serial::readByte(){
	char byte;
	if(::read(fd, &byte, 1) < 0){
		std::cout << "could not read byte" << std::endl;
		return 0x01;
	}
	else return byte;
}

