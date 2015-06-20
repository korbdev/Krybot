/*
 * main.cpp
 *
 *  Created on: 21.05.2015
 *      Author: rkorb
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <Communication/Message.h>
#include <Communication/MessageSimulator.h>
#include <Communication/Connection.h>
#include <Communication/Serial.h>
#include <Collections/MessageQueue.h>
#include <Collections/Status.h>
#include <Sensors/Sonar.h>
#include <thread>

using namespace std;
//void f(MessageQueue* queue);
//void g(MessageQueue* queue);



int main(){

	std::cout << "Krybot starting..." << std::endl;

	Status<Message> status1;

	MessageSimulator m(20, &status1);
	//Serial n(30, 9600, "/dev/ttyS2", &status2);

	Sonar s("SONAR", &m);

	s.start(300);

	while(true){
		std::cout << "distance " <<s.readSensor() << std::endl;
		this_thread::sleep_for(chrono::seconds(1));
	}

	s.stop();
	std::cout << "EXIT" << std::endl;
	return 0;
}

/*void f(MessageQueue* queue){
	int counter = 0;
	while(true){
		counter++;
		Message msg("{\"id\":"+ std::to_string(counter) +", \"msg\":\"hello\"}");
		queue->push(msg);
		//std::cout << "PUT" << msg.getMessage() << std::endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
}

void g(MessageQueue* queue){
	while(true){
		Message m = queue->pop();
		std::cout << "POP " << m.getIntegerValue("id", 0) << std::endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
}*/
