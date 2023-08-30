#include "../include/logger.h"
#include "../include/ipclib.h"
#include <thread>
#include <iostream>

int main() {

    try {
        std::cout<<"i am the receiver";
        // Create an MQTTReceiver instance to listen for messages
        MQTTReceiver receiver;
        
        receiver.listen();
        

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}