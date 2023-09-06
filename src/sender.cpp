#include "../include/logger.h"
#include "../include/ipclib.h"
#include <thread>
#include <iostream>
#include <memory>
#include <any>

int main() {

    try {
        
        MQTTSender sender;
        sender.send("test/topic", "LOG_TRACE:this is good");
        sleep(2);       
        
    }

    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}