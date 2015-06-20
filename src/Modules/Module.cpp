/*
 * Module.cpp
 *
 *  Created on: 09.06.2015
 *      Author: rkorb
 */

#include <thread>
#include <iostream>
#include <Modules/Module.h>

Module::~Module(){

}

void Module::start(int interval){
	running = true;
	connection->connect();
	t = thread(&Module::operator(), this, interval);
}

void Module::stop(){
	running = false;
	connection->disconnect();
	t.join();
}

void Module::operator ()(int interval){
	while(isRunning()){
		std::cout << "MODUEL GET MESSAGE" << endl;
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
