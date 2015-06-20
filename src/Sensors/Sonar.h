/*
 * Sonar.h
 *
 *  Created on: 09.06.2015
 *      Author: rkorb
 */

#ifndef SONAR_H_
#define SONAR_H_

#include <Modules/Module.h>
#include <Sensors/Hcsr04.h>
#include <string>
#include <vector>

using namespace std;

class Sonar : public Module{
private:
	Hcsr04* sensor;
public:
	Sonar(string name, Connection* connection):Module(name, connection){sensor = new Hcsr04("HCSR01", std::vector<float>(3,0), std::vector<float>(3,0));}
	virtual void processMessage(Message msg) override;
	int readSensor();
	~Sonar(){delete sensor;}
};

#endif /* SONAR_H_ */
