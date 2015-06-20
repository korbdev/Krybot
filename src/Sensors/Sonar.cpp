/*
 * Sonar.cpp
 *
 *  Created on: 09.06.2015
 *      Author: rkorb
 */

#include <Sensors/Sonar.h>
#include <iostream>

void Sonar::processMessage(Message msg){
	int distance = msg.getIntegerValue("HCSR01", 1);
	sensor->setDistance(distance);
}

int Sonar::readSensor(){
	return sensor->getDistance();
}
