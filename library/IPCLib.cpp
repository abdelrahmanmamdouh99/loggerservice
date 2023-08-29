

#include "../include/ipclib.h"


#include <mosquitto.h> 
#include <iostream>
#include <stdexcept>

#include <thread>
#include <chrono>
#include <string>




#if 0
void message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message) {
    if (message->payloadlen) {
        std::cout << message->topic << ": " << (char*)message->payload << std::endl;
    }
}


class MQTTReceiver {
private:
    struct mosquitto* mosq;

public:
    MQTTReceiver();
    ~MQTTReceiver();
    void listen();

private:
    static void message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message);
};


class MQTTSender {
private:
    struct mosquitto* mosq;

public:
    MQTTSender();
    ~MQTTSender();
    void send(const std::string& topic, const std::string& message);
};
#endif

MQTTReceiver::MQTTReceiver() {
    mosquitto_lib_init();
    mosq = mosquitto_new(nullptr, true, nullptr);

    if (!mosq) {
        throw std::runtime_error("Failed to initialize Mosquitto");
    }

    mosquitto_message_callback_set(mosq, message_callback);
    mosquitto_connect(mosq, "localhost", 1883, 60);
    mosquitto_subscribe(mosq, nullptr, "test/topic", 0);
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
}

MQTTSender::~MQTTSender() {
    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
}

void MQTTSender::send(const std::string& topic, const std::string& message) {
    mosquitto_publish(mosq, nullptr, topic.c_str(), message.size(), message.c_str(), 0, false);
}

/*********************************************************/
#if 0
class MQTTReceiver {

private:
    struct mosquitto* mosq;

public:
    MQTTReceiver() {
        mosquitto_lib_init();
        mosq = mosquitto_new(nullptr, true, nullptr);

        if (!mosq) {
            throw std::runtime_error("Failed to initialize Mosquitto");
        }

        mosquitto_message_callback_set(mosq, message_callback);
        mosquitto_connect(mosq, "localhost", 1883, 60);
        mosquitto_subscribe(mosq, nullptr, "test/topic", 0);
    }

    ~MQTTReceiver() {
        mosquitto_disconnect(mosq);
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
    }

    void listen() {
        mosquitto_loop_forever(mosq, -1, 1);
    }

};


class MQTTSender {
private:
    struct mosquitto* mosq;

public:
    MQTTSender() {
        mosquitto_lib_init();
        mosq = mosquitto_new(nullptr, true, nullptr);

        if (!mosq) {
            throw std::runtime_error("Failed to initialize Mosquitto");
        }

        mosquitto_connect(mosq, "localhost", 1883, 60);
    }

    ~MQTTSender() {
        mosquitto_disconnect(mosq);
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
    }

    void send(const std::string& topic, const std::string& message) {
        mosquitto_publish(mosq, nullptr, topic.c_str(), message.size(), message.c_str(), 0, false);
    }

};
#endif

//the under code is for testing this lib before using logger demaon
#if 0
int main() {
    try {
        // Create an MQTTReceiver instance to listen for messages
        MQTTReceiver receiver;

        // Create an MQTTSender instance to send messages
        MQTTSender sender;

        // Start listening for MQTT messages in a separate thread
        std::thread receiverThread(&MQTTReceiver::listen, &receiver);

        // Send some MQTT messages
        for (int i = 0; i < 5; ++i) {
            sender.send("test/topic", "Hello, MQTT! Message " + std::to_string(i));
            std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait between messages
        }

        // Wait for the receiver thread to finish
        receiverThread.join();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
#endif
