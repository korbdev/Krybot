/*
 * Sonar.cpp
 *
 *  Created on: 09.06.2015
 *      Author: rkorb
 */

#include <Sensors/Sonar.h>
#include <vector>
#include <iostream>

atomic<Sonar*> Sonar::pInstance(0);

Sonar* Sonar::getInstance(){
	if(!pInstance){
		std::unique_lock<std::mutex>(creationLock);
		if(!pInstance){
			pInstance = new Sonar();
		}
	}
	return pInstance;
}

Sonar::Sonar():Module(){
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
		std::cout << "REGISTERED " << msg.getMessage() << std::endl;
		break;
	case UNREGISTER:
		break;
	case MEASURE:
		setSensorData(msg);
		break;
	default:
		break;
	}
}

void Sonar::registerSensor(){
	Message m("{\"type\":1}");
	connection->write(m);
}

void Sonar::setSensorData(Message msg){
	int distance = msg.getIntegerValue("HCSR1", 1);
	sensors["HCSR1"]->setDistance(distance);
}

int Sonar::readSensor(){
	return sensors["HCSR1"]->getDistance();
}

