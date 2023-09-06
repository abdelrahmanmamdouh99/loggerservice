#include "../include/logger.h"
#include "../include/ipclib.h"
#include <thread>
#include <iostream>


#include <fstream>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/utility/setup.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;

int main() {
    // Open the file for appending
    std::ofstream outFile("example.txt", std::ios::app);

    // Append data to the file
    outFile << "This is some appended text." << std::endl;

   LOG_TRACE<<"helloooo";
  
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