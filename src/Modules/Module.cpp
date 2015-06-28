/*
 * Module.cpp
 *
 *  Created on: 09.06.2015
 *      Author: rkorb
 */

#include <thread>
#include <iostream>
#include <Modules/Module.h>

#include <glog/logging.h>

Module::~Module(){

}

void Module::start(int interval){
	running = true;
	bool result = connection->connect();
	t = thread(&Module::operator(), this, interval);
	std::cout << "started " << result << std::endl;
}

void Module::stop(){
	running = false;
	connection->disconnect();
	t.join();
}

void Module::operator ()(int interval){
	while(isRunning()){
		processMessage(connection->get());
		std::this_thread::sleep_for(chrono::milliseconds(interval));
	}
}

bool Module::isRunning() const{
	return running;
}

string Module::getName() const{
	return name;
}
