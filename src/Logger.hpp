/* 
 * File:   Logger.hpp
 * Author: alessio
 *
 */

#ifndef LOGGER_HPP
#define	LOGGER_HPP
#include <string>
#include <fstream>
namespace tbd{
/**
* Simple class used to log stuff. Writes to stdout and on "log.txt"
*/
class Logger {    
public:
    /**
     * Enums containing the different levels of logging
     */
    enum logLevel{
        LOG,WARN,CRITICAL
    };
    /**
     * Logs a string with the lowest level of logging
     * @param s String to print
     */
    static void logString(const std::string& s);
    /**
     * Logs a string with a specific level of logging
     * @param ll Level of loggin
     * @param s String to print
     */
    static void logString(logLevel ll,const std::string& s);
private:
    Logger();
    logLevel min;
    std::ofstream file;
};

}
#endif	/* LOGGER_HPP */

