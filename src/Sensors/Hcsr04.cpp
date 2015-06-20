/*
 * Hcsr04.cpp
 *
 *  Created on: 10.06.2015
 *      Author: rkorb
 */
#include <Sensors/Hcsr04.h>

int Hcsr04::getDistance(){
	return distance.s_pop();
}

void Hcsr04::setDistance(int dist){
	distance.s_push(dist);
}


