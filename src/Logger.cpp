/* 
 * File:   Logger.cpp
 * Author: alessio
 * 
 */

#include "Logger.hpp"
#include <iostream>
tbd::Logger::Logger() {
    file.open("log.txt");
    min=LOG;
}

void tbd::Logger::logString(const std::string& s){
    logString(LOG,s);
    
}
void tbd::Logger::logString(logLevel ll, const std::string& s){
    static Logger logger;
    if(ll>=logger.min){
        std::cout<<s<<std::endl;
        logger.file<<s<<std::endl;
    }
}