/*
 * HttpClient.cpp
 *
 *  Created on: 06.07.2015
 *      Author: rkorb
 */

#include <Communication/HttpClient.h>
#include <curl/curl.h>
#include <Communication/Message.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>

bool HttpClient::initializeConnection(){
	handle = curl_easy_init();
	if(handle){
		return true;
	}
	else{
		return false;
	}
}

bool HttpClient::closeConnection(){
	curl_easy_cleanup(handle);
	return true;
}

Message HttpClient::read(){
	CURLcode res;
	CurlMessage msg;

	msg.buffer = (char*) malloc(1);
	msg.size = 0;

	curl_easy_setopt(handle, CURLOPT_URL, "127.0.0.1:5000");
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, HttpClient::write_data);
	curl_easy_setopt(handle, CURLOPT_WRITEDATA, (void*) &msg);
	res = curl_easy_perform(handle);
	std::string message = msg.buffer;
	Message recv(message);

	free(msg.buffer);
	return recv;
}

bool HttpClient::write(Message message){
	return true;
}

size_t HttpClient::write_data(void *buffer, size_t size, size_t nmemb, void *userp){
	size_t real = size*nmemb;

	CurlMessage* msg = (CurlMessage*) userp;
	msg->buffer = (char*) realloc(msg->buffer, msg->size + real + 1);
	msg->size += real;
	memcpy(msg->buffer, buffer, real);

	msg->buffer[msg->size] = 0;
	return real;
}
