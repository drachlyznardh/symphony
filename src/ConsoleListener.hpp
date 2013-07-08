#ifndef CONSOLELISTENER_HPP
#define	CONSOLELISTENER_HPP
#include <queue>
#include <string>
#include <thread>
#include <mutex>

namespace tbd {
    /**
     * Console Listener: listens and stores any command sent via command line to the system
     * The syntax of the commands is WIP
     */
    class ConsoleListener {
    public:
        /**
         * Constructor: creates the thread that continuosly checks if messages have been received
         */
        ConsoleListener();
        /**
         * Checks if there are any new message
         * @return True if there are messages to read
         */
        bool hasMessage();
        /**
         * Reads and remove the message from the queue
         * @return the message to be returned
         */
        std::string getMessage();
    private:
        std::mutex mymutex;
        std::thread th;
        std::queue<std::string>* messages;
        
    };
}
#endif	/* CONSOLELISTENER_HPP */

