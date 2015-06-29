/*
 * Sonar.cpp
 *
 *  Created on: 09.06.2015
 *      Author: rkorb
 */

#include <Sensors/Sonar.h>
#include <vector>
#include <iostream>

Sonar::Sonar(string name, Connection* connection):Module(name, connection){
	std::string sensorName = "HCSR1";
	Hcsr04* s1 = new Hcsr04(sensorName, vector<float>(3,0),vector<float>(3,0));
	s1->setDistance(0); //initialize with 0 to avoid waiting state, when no message is arriving
	sensors.insert(pair<string, Hcsr04*>(sensorName, s1));
}

Sonar::~Sonar(){
	for(auto &pair : sensors){
		delete pair.second;
	}
}

void Sonar::processMessage(Message msg){
	int messageType = msg.getIntegerValue("type", 0);
	std::cout << "PROCESS " << messageType << std::endl;
	switch(messageType){
	case REGISTER:
		std::cout << "REGISTERED" << std::endl;
		break;
	case MEASURE:
		setSensorData(msg);
		break;
	default:
		break;
	}
}

void Sonar::registerSensor(){
	std::cout << "REGISTERED" << std::endl;
	Message m("{\"type\":0}");
	connection->write(m);
}

void Sonar::setSensorData(Message msg){
	int distance = msg.getIntegerValue("HCSR1", 1);
	sensors["HCSR1"]->setDistance(distance);
}

int Sonar::readSensor(){
	return sensors["HCSR1"]->getDistance();
}

