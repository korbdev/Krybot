/*
 * MessageSimulator.cpp
 *
 *  Created on: 26.05.2015
 *      Author: rkorb
 */

#include <Communication/MessageSimulator.h>
#include <iostream>
#include <thread>

bool MessageSimulator::connect(){
	connected = true;
	t = std::thread(&Connection::operator (), this);
	return true;
}

bool MessageSimulator::disconnect(){
	connected = false;
	t.join();
	return true;
}

bool MessageSimulator::write(Message msg){
	return true;
}

Message MessageSimulator::read(){
	Message msg("test");
	std::cout << msg.getMessage() << std::endl;
	return msg;
}

Message MessageSimulator::get(){
	return queue.pop();
}
