/*
 * Entity.h
 *
 *  Created on: 09.06.2015
 *      Author: rkorb
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

using namespace std;

class Entity{
protected:
	vector<float> referencePoint;
	vector<float> direction;
public:
	Entity(vector<float> rp, vector<float> dir):referencePoint(rp), direction(dir){}
};

#endif /* ENTITY_H_ */
