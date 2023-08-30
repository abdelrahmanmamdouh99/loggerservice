#include "../include/logger.h"
#include "../include/ipclib.h"
#include <thread>
#include <iostream>

int main() {

    try {
     
        std::cout<<"I am the sender \n";

        // Create an MQTTSender instance to send messages
        MQTTSender sender;
       
     
        sender.send("test/topic", "Hello, MQTT! Message ");
        sleep(2);   
        

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}