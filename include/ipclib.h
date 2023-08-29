#ifndef ipclib_h_
#define ipclib_h_


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