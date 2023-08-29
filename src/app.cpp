#include "../include/logger.h"
#include "../include/ipclib.h"


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