#include "simplelogger.h"
//#include "../include/ipclib.h"
#include <thread>
#include <iostream>

int main() {
    
// Log some messages using your custom logger
    LOG_DEBUG << "This is an informational message.";
    LOG_FATAL << "This is an error message.";

    return 0;
}
