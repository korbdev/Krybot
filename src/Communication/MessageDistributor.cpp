/*
 * MessageDistributor.cpp
 *
 *  Created on: 26.05.2015
 *      Author: rkorb
 */


#include <Communication/MessageDistributor.h>
#include <iostream>

using namespace std;

MessageDistributor::MessageDistributor(Connection* con){
	cout << "MD ctor" << con->read().getMessage() << endl;
	connection = con;
	cout << "MD ctor 2" << con->read().getMessage() << endl;
}

void MessageDistributor::operator ()(){
	cout << "Start threading operator" << endl;
	while(true){
			Message msg = connection->read();
			cout << msg.getMessage() << typeid(connection).name()<< endl;
			//con->queue.push(msg);
			std::this_thread::sleep_for(chrono::milliseconds(1000));
		}
}

