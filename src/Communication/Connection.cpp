/*
 * Connection.cpp
 *
 *  Created on: 21.05.2015
 *      Author: rkorb
 */
#include <Communication/Connection.h>
#include <iostream>

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
				cout << "CONNECTION READ " << msg.getMessage() << endl;
			}
			std::this_thread::sleep_for(chrono::milliseconds(interval));
		}
}

bool Connection::connect(){
	t = thread(&Connection::operator (), this);
	connected = true;
	return initializeConnection();
}

bool Connection::disconnect(){
	t.join();
	connected = false;
	return closeConnection();
}
