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
#include <Communication/TcpSocket.h>
#include <Collections/MessageQueue.h>
#include <Collections/Status.h>
#include <Sensors/Sonar.h>
#include <thread>
#include <glog/logging.h>

using namespace std;
//void f(MessageQueue* queue);
//void g(MessageQueue* queue);



int main(){

	google::InitGoogleLogging("krybot.logger");
	std::cout << "Krybot starting..." << std::endl;

	LOG(INFO) << "Krybot starting";

	Status<Message> status1;
	Status<Message> status2;
	Status<Message> status3;

	MessageSimulator m(1000, &status1);
	Serial n(1000, 9600, "/dev/ttyACM0", &status2);
	TcpSocket tcp("127.0.0.1", 5000, 200, &status3);

	Sonar* s = Sonar::getInstance();

	s->start(&tcp, 5000);

	while(true){
		std::cout << " distance " << s->readSensor() << std::endl;
		s->registerSensor();
		this_thread::sleep_for(chrono::seconds(2));
	}

	//s.stop();
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
