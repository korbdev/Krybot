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

	fd = open(path.c_str(), O_RDWR | O_NOCTTY);

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
	serial.c_lflag = ICANON;
	serial.c_cflag = B115200 | CRTSCTS | CS8 | CLOCAL | CREAD;

	serial.c_cc[VINTR]    = 0;     /* Ctrl-c */
	serial.c_cc[VQUIT]    = 0;     /* Ctrl-\ */
	serial.c_cc[VERASE]   = 0;     /* del */
	serial.c_cc[VKILL]    = 0;     /* @ */
	serial.c_cc[VEOF]     = 4;     /* Ctrl-d */
	serial.c_cc[VTIME]    = 0;     /* inter-character timer unused */
	serial.c_cc[VMIN]     = 1;     /* blocking read until 1 character arrives */
	serial.c_cc[VSWTC]    = 0;     /* '\0' */
	serial.c_cc[VSTART]   = 0;     /* Ctrl-q */
	serial.c_cc[VSTOP]    = 0;     /* Ctrl-s */
	serial.c_cc[VSUSP]    = 0;     /* Ctrl-z */
	serial.c_cc[VEOL]     = 0;     /* '\0' */
	serial.c_cc[VREPRINT] = 0;     /* Ctrl-r */
	serial.c_cc[VDISCARD] = 0;     /* Ctrl-u */
	serial.c_cc[VWERASE]  = 0;     /* Ctrl-w */
	serial.c_cc[VLNEXT]   = 0;     /* Ctrl-v */
	serial.c_cc[VEOL2]    = 0;     /* '\0' */

	tcflush(fd, TCIFLUSH);
	if(tcsetattr(fd, TCSANOW, &serial) >= 0){
		return true;
	}
	else return false;
}

bool Serial::closeConnection(){
	close(fd);
	return true;
}

bool Serial::write(Message msg){
	string message = msg.getMessage();
	std::cout << "write " << msg.getMessage() << std::endl;
	int wcount = 0;
	while(wcount < (int)message.length()){
		wcount = ::write(fd, message.c_str(), message.length());
	}
	std::cout << "written " << wcount << std::endl;
	return false;
}

Message Serial::read(){
	std::cout << "start read " << std::endl;
	char buffer[512]; //TODO: include constant for buffersize

	int res = ::read(fd, &buffer, sizeof(buffer));
	buffer[res] = 0;
	string message(buffer);
	Message m(message);
	std::cout << "read " << m.getMessage() << res << std::endl;
	return m;
}

char Serial::readByte(){
	char byte;
	if(::read(fd, &byte, 1) < 0){
		std::cout << "could not read byte" << std::endl;
		return 0x01;
	}else {
		return byte;
	}

}

