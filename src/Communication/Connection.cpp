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
	//t = thread(&Connection::operator (), this);
}

Connection::~Connection(){
	//t.join();
}

void Connection::test(){
	cout << "Hello thread" << endl;
}

void Connection::operator ()(){
	cout << "Start threading operator" << endl;
	while(true){
			Message msg = read();
			queue.push(msg);
			std::this_thread::sleep_for(chrono::milliseconds(1000));
		}
}

