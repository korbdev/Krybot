/*
 * Message.cpp
 *
 *  Created on: 21.05.2015
 *      Author: rkorb
 */
#include <Communication/Message.h>

Message::Message(std::string message){
	msg = message;
	root = Json::Value();
	reader = Json::Reader();
	reader.parse(msg, root);
	timestamp = 0;
}

bool Message::isEmpty(){
	return (msg == "");
}

std::string Message::getMessage() const{
	return msg;
}

std::string Message::getStringValue(std::string key, std::string defaultValue){
	return root.get(key, defaultValue).asString();
}

int Message::getIntegerValue(std::string key, int defaultValue){
	return root.get(key, defaultValue).asInt();
}

double Message::getDoubleValue(std::string key, double defaultValue){
	return root.get(key, defaultValue).asDouble();
}

bool Message::getBoolValue(std::string key, bool defaultValue){
	return root.get(key, defaultValue).asBool();
}
