/*
 * Hcsr04.h
 *
 *  Created on: 10.06.2015
 *      Author: rkorb
 */

#ifndef HCSR04_H_
#define HCSR04_H_

#include <Collections/Status.h>
#include <Modules/Entity.h>
#include <vector>
#include <string>

class Hcsr04 : public Entity {
private:
	Status<int> distance;
	std::string name;
public:
	Hcsr04(std::string name):Entity(std::vector<float>(3,0), std::vector<float>(3,0)), name(name){}
	Hcsr04(std::string name, vector<float> rp, vector<float> dir):Entity(rp, dir), name(name){}
	int getDistance();
	void setDistance(int dist);
};



#endif /* HCSR04_H_ */
