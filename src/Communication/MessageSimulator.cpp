/*
 * MessageSimulator.cpp
 *
 *  Created on: 26.05.2015
 *      Author: rkorb
 */

#include <Communication/MessageSimulator.h>
#include <iostream>
#include <thread>

bool MessageSimulator::initializeConnection(){
	return true;
}

bool MessageSimulator::closeConnection(){
	return true;
}

bool MessageSimulator::write(Message msg){
	return true;
}

Message MessageSimulator::read(){
	Message msg("test");
	return msg;
}
