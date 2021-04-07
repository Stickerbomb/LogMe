//
// Created by Yehor on 06.04.2021.
//
#ifndef LOGME_LOG_H
#define LOGME_LOG_H

#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <thread>
#include <sstream>
class logstream;

enum class log_level { ERROR, WARNING, INFO, DEBUG};

#define ERROR log_level::ERROR
#define WARNING log_level::WARNING
#define INFO log_level::INFO
#define DEBUG log_level::DEBUG

class log {
    std::string prefix;
    std::string filename;
public:
    log(std::string prefix, std::string filename ) : prefix(prefix), filename(filename);
    log getLogger(const std::string filename, const std::string prefix);
    friend log& operator << (log& logger, const std::string message);
    virtual ~log();

};
static log handler(log logger, log_level level);
log (*getLogger(std::string filename = "", std::string prefix = ""))( log_level);

class logstream  {
    log &m_logger;
    log_level m_level;
    std::string get_level_string();
public:

    static std::string get_time_string();

    logstream(log &logger, log_level level) : m_logger(logger), m_level(level) {}

    ~logstream();
};

#endif //LOGME_LOG_H
