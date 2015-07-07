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
#include <Communication/HttpClient.h>
#include <Collections/MessageQueue.h>
#include <Collections/Status.h>
#include <Sensors/Sonar.h>
#include <thread>
#include <glog/logging.h>
#include <ctime>

using namespace std;
//void f(MessageQueue* queue);
//void g(MessageQueue* queue);



int main(){
	timeval a;
	timeval b;
	gettimeofday(&a, 0);
	gettimeofday(&b, 0);
	google::InitGoogleLogging("krybot.logger");
	std::cout << "Krybot starting..." << std::endl;

	LOG(INFO) << "Krybot starting";

	Status<Message> status1;
	Status<Message> status2;
	Status<Message> status3;
	Status<Message> status4;

	MessageSimulator m(1000, &status1);
	Serial n(1000, 9600, "/dev/ttyACM0", &status2);
	TcpSocket tcp("127.0.0.1", 5000, 200, &status3);
	HttpClient http("127.0.0.1", 5000, 20, &status4);

	Sonar* s = Sonar::getInstance();

	s->start(&http, 5000);

	while(true){
		gettimeofday(&a, 0);

		//s->registerSensor();
		this_thread::sleep_for(chrono::seconds(2));
		gettimeofday(&b, 0);
		std::cout << "distance " << s->readSensor() << " "  << (b.tv_sec - a.tv_sec)<< std::endl;
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
