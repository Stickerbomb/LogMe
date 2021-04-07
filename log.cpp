//
// Created by Yehor on 06.04.2021.
//

#include "log.h"


log::~log() {
//    if(filewriter.is_open())
//        filewriter.close();
}

log handler(log logger, log_level level = INFO) {
    logstream logstreamer =logstream(logger,level);
    return logger;
}

log getlogger(std::string filename, std::string prefix) {

}

log (*getLogger(std::string filename, std::string prefix))(log_level level){
    log logger = log(filename,prefix);
    return handler;
}



std::string logstream::get_level_string()
{
    std::string temp;
    switch(m_level) {
        case INFO: temp = "INFO;"; break;
        case WARNING: temp = "WARNING;"; break;
        case DEBUG: temp = "DEBUG;"; break;
        case ERROR: temp = "ERROR;"; break;
    }
    return temp;
}

std::string logstream::get_time_string()
{
    std::time_t t = std::time(nullptr);
#ifdef _WIN32
    std::tm time;
    localtime_s(&time, &t);
#else
    std::tm time = *std::localtime(&t);
#endif
    char t_str[20];
    std::strftime(t_str, sizeof(t_str), "%T", &time);

    return ("[" + std::string(t_str) + "]");
}