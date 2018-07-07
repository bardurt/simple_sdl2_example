#include "Log.h"
#include <iostream>

Log* Log::logInstance = NULL;

Log::Log()
{
    //ctor
}

Log::~Log()
{
    //dtor
}

Log* Log::instance()
{

    if (!logInstance)
    {
        logInstance = new Log;
    }

    return logInstance;
}

void Log::destroy()
{
    std::cout << "Log: destroying log" << std::endl;
    delete logInstance;
    logInstance = NULL;
}

void Log::info(std::string origin, std::string message)
{
    std::cout << "INFO >> " << origin << ": " << message << std::endl;
}

void Log::error(std::string origin, std::string message)
{
    std::cout << "ERROR >> " << origin << ": " << message << std::endl;
}
