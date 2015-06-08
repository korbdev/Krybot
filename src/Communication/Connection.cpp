/*
 * Connection.cpp
 *
 *  Created on: 21.05.2015
 *      Author: rkorb
 */
#include <Communication/Connection.h>
#include <iostream>

using namespace std;

Connection::Connection(int interval){
	this->interval = interval;
	connected = false;
}

Connection::~Connection(){

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

Message Connection::get(){
	return queue.pop();
}

void Connection::operator ()(){
	cout << "Start threading operator" << endl;
	while(true){
			Message msg = read();
			if(!msg.isEmpty()){
				cout << msg.getStringValue("message", "default") << endl;
				queue.push(msg);
			}
			std::this_thread::sleep_for(chrono::milliseconds(interval));
		}
}

