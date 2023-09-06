

#include "../include/ipclib.h"
#include <memory>

#include <mosquitto.h> 
#include <iostream>
#include <stdexcept>
#include <logger.h>

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




    std::string mess =(char*)message->payload;
    
    /*********************************************/
// Find the position of the colon
    size_t colonPos = mess.find(':');

    if (colonPos != std::string::npos) {
        // Extract the substring after the colon
        std::string value = mess.substr(colonPos + 1);

        // Trim leading and trailing spaces (optional)
        size_t firstNonSpace = value.find_first_not_of(" \t");
        size_t lastNonSpace = value.find_last_not_of(" \t");

        if (firstNonSpace != std::string::npos && lastNonSpace != std::string::npos) {
            value = value.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
        }

    /*********************************************/
        if (mess.compare(0, 6, "LOG_TR") == 0) {
            // Handle "save" command
            std::cout << "LOG_TR\n" << std::endl;
            LOG_TRACE<<value;
            
        } else if (mess.compare(0, 5, "LOG_IN") == 0) {
            // Handle "close" command
            
        } else if (mess.compare(0, 5, "LOG_WA") == 0) {
            // Handle "close" command
            
        } else if (mess.compare(0, 5, "LOG_ER") == 0) {
            // Handle "close" command
            
        }else if (mess.compare(0, 5, "LOG_FA") == 0) {
            // Handle "close" command
            
        }else {
            // Default case
            std::cout <<mess.compare(0, 5, "LOG_TR") << std::endl;
        }
    }
   }
}

#if 0
std::string MQTTReceiver::getReceivedMessage() {
    return receivedMessage;
}
#endif
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
#if 0
auto createInstant (bool create){
    // Create an MQTTSender instance to send messages
    if (create) {
        return std::make_unique<MQTTSender>();
    } else {
        return nullptr;
    } 
}
#include <any>

std::any createObject(bool create) {
    if (create) {
        return 0;
    } else {
        return nullptr;
    }
}
#endif
