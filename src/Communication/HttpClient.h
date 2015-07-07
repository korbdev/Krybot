/*
 * HttpClient.h
 *
 *  Created on: 06.07.2015
 *      Author: rkorb
 */

#ifndef SRC_COMMUNICATION_HTTPCLIENT_H_
#define SRC_COMMUNICATION_HTTPCLIENT_H_

#include <Communication/Connection.h>
#include <curl/curl.h>

class HttpClient : public Connection{
private:
	struct CurlMessage{
		int size;
		char* buffer;
	};
	std::string ip;
	int port;
	CURL* handle;
	static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);
protected:
	virtual bool initializeConnection() override;
	virtual bool closeConnection() override;
public:
	HttpClient(std::string ip, int port, int interval, ThreadingQueue<Message>* queue):Connection(interval, queue), ip(ip), port(port), handle(0){}
	virtual Message read() override;
	virtual bool write(Message msg) override;
};


#endif /* SRC_COMMUNICATION_HTTPCLIENT_H_ */
