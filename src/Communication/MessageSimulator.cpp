/*
 * MessageSimulator.cpp
 *
 *  Created on: 26.05.2015
 *      Author: rkorb
 */

#include <Communication/MessageSimulator.h>
#include <Communication/Connection.h>
#include <iostream>
#include <thread>
#include <string>

using namespace std;

bool MessageSimulator::initializeConnection(){
	cout << "init simulator" << endl;
	return true;
}

bool MessageSimulator::closeConnection(){
	return true;
}

bool MessageSimulator::write(Message msg){
	string message = msg.getMessage();

	for(unsigned int i = 0; i < message.length(); i++){
		cout << typeid(message[i]).name() << endl;
	}
	return true;
}

Message MessageSimulator::read(){
	Message msg("{\"HCSR01\":12345}");
	return msg;
}
