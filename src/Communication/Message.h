/*
 * Message.h
 *
 *  Created on: 21.05.2015
 *      Author: rkorb
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
#include <json/json.h>

class Message{
private:
	std::string 	msg;
	Json::Value		root;
	Json::Reader	reader;
	long 			timestamp;

public:
	Message(std::string msg);
	bool			isEmpty();
	std::string 	getMessage() const;
	std::string 	getStringValue(std::string key, std::string defaultValue);
	int 			getIntegerValue(std::string key, int defaultValue);
	double			getDoubleValue(std::string key, double defaultValue);
	bool			getBoolValue(std::string key, bool defaultValue);
};



#endif /* MESSAGE_H_ */
