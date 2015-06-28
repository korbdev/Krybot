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
#include <map>

using namespace std;

class Sonar : public Module{
private:
	map<string, Hcsr04*>sensors;
public:
	Sonar(string name, Connection* connection);
	virtual void processMessage(Message msg) override;
	void registerSensor();
	int readSensor();
	~Sonar();
};

#endif /* SONAR_H_ */
