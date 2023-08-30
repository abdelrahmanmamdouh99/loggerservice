

#include "../include/ipclib.h"


#include <mosquitto.h> 
#include <iostream>
#include <stdexcept>

#include <thread>
#include <chrono>
#include <string>
using namespace std;


MQTTReceiver::MQTTReceiver() {
    mosquitto_lib_init();
    mosq = mosquitto_new(nullptr, true, nullptr);

    if (!mosq) {
        throw std::runtime_error("Failed to initialize Mosquitto");
    }

    mosquitto_message_callback_set(mosq, message_callback);
    mosquitto_connect(mosq, "localhost", 1883, 60);
    mosquitto_subscribe(mosq, nullptr, "test/topic", 0);

    int sock = mosquitto_socket(mosq); // Access the socket using the function
    std::cout<<"socket num ::"<<sock<<"\n";

}

MQTTReceiver::~MQTTReceiver() {
    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
}

void MQTTReceiver::listen() {
    mosquitto_loop_forever(mosq, -1, 1);
}

void MQTTReceiver::message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message) {
   if (message->payloadlen) {
        std::cout << message->topic << ": " << (char*)message->payload << std::endl;
    }
}
/*************************************************************/

// Implementation of MQTTSender

MQTTSender::MQTTSender() {
    mosquitto_lib_init();
    mosq = mosquitto_new(nullptr, true, nullptr);

    if (!mosq) {
        throw std::runtime_error("Failed to initialize Mosquitto");
    }

    mosquitto_connect(mosq, "localhost", 1883, 60);
          
    int sock = mosquitto_socket(mosq); // Access the socket using the function
    std::cout<<"socket num ::"<<sock<<"\n";

}

MQTTSender::~MQTTSender() {
    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
}

void MQTTSender::send(const std::string& topic, const std::string& message) {
    mosquitto_publish(mosq, nullptr, topic.c_str(), message.size(), message.c_str(), 0, false);
}
