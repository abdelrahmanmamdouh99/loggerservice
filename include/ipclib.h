#ifndef ipclib_h_
#define ipclib_h_

#include <string>

class MQTTReceiver {
private:
    struct mosquitto* mosq;

public:
    MQTTReceiver();
    ~MQTTReceiver();
    void listen();
//    std::string getReceivedMessage();
private:
    static void message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message);
    std::string receivedMessage;  // Store received message
};


class MQTTSender {
private:
    struct mosquitto* mosq;

public:
    MQTTSender();
    ~MQTTSender();
    void send(const std::string& topic, const std::string& message);
};



#include <any>

std::any createObject(bool create);

#endif