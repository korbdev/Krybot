/*
 * Connection.cpp
 *
 *  Created on: 21.05.2015
 *      Author: rkorb
 */
#include <Communication/Connection.h>
#include <iostream>

#include <glog/logging.h>

using namespace std;

Connection::Connection(int interval, ThreadingQueue<Message>* queue){
	this->interval = interval;
	this->queue = queue;
	connected = false;
}

Connection::~Connection(){

}

Message Connection::get(){
	return queue->s_pop();
}

void Connection::operator ()(){
	while(connected){
			Message msg = read();
			if(!msg.isEmpty()){
				queue->s_push(msg);
				//std::cout << msg.getMessage() << endl;
			}
			std::this_thread::sleep_for(chrono::milliseconds(interval));
		}
}

bool Connection::connect(){
	connected = initializeConnection();
	t = thread(&Connection::operator (), this);
	std::cout << "connected " << connected << std::endl;
	return connected;
}

bool Connection::disconnect(){
	t.join();
	connected = false;
	return closeConnection();
}
