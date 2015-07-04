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
#include <atomic>
#include <mutex>
#include <string>
#include <map>

using namespace std;

class Sonar : public Module{
private:
	map<string, Hcsr04*>sensors;
	Sonar();
	static atomic<Sonar*> pInstance;
	mutex creationLock;
	void setSensorData(Message msg);
public:
	enum SonarMessage{
		REGISTER = 1,
		UNREGISTER,
		MEASURE
	};
	static Sonar* getInstance();
	virtual void processMessage(Message msg) override;
	void registerSensor();
	int readSensor();
	~Sonar();

	//delete of copy constructor and assignment operator to prevent multiple sonar objects
	Sonar(Sonar& other) = delete;
	Sonar& operator=(Sonar& other) = delete;
};

#endif /* SONAR_H_ */
