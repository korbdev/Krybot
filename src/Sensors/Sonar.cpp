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

	sensors.insert(pair<string, Hcsr04*>(sensorName, s1));
}

Sonar::~Sonar(){
	for(auto &pair : sensors){
		delete pair.second;
	}
}

void Sonar::processMessage(Message msg){
	int distance = msg.getIntegerValue("HCSR1", 1);
	sensors["HCSR1"]->setDistance(distance);
}

void Sonar::registerSensor(){
	Message m("Test");
	connection->write(m);
}

int Sonar::readSensor(){
	return sensors["HCSR1"]->getDistance();
}

