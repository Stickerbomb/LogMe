//
// Created by Yehor on 06.04.2021.
//

#include "log.h"


log::~log() {
    if(writeFileStream.is_open())
        writeFileStream.close();
}

static logstream log(log_level level = log_level::info) {
    static logger m_handler;
    return logstream(m_handler, level);
}

log &operator<<(log &logger, const log::logType l_type) {
    switch (l_type) {
        case log::log_level::ERROR:
            if (logger.writeFileStream.is_open()) {
                logger.writeFileStream << time(0) << "ERROR" << logger.prefix << _threadid;
            } else {
                std::cout << time(0) << "ERROR; " << logger.prefix << _threadid;
            }
            break;

        case log::log_level::WARNING:
            if (logger.writeFileStream.is_open()) {
                logger.writeFileStream << time(0) << "WARNING" << logger.prefix << _threadid;
            } else {
                std::cout << time(0) << " WARNING; " << logger.prefix << _threadid;
            }
            break;
        case log::log_level::DEBUG:
            if (logger.writeFileStream.is_open()) {
                logger.writeFileStream << time(0) << " DEBUG; " << logger.prefix << _threadid;
            } else {
                std::cout << time(0) << " DEBUG; " << logger.prefix << _threadid;
            }
            break;

        default:
            if (logger.writeFileStream.is_open()) {
                logger.writeFileStream << time(0) << " INFO; " << logger.prefix << _threadid;
            } else {
                std::cout << time(0) << " INFO; " << logger.prefix << " "<<  _threadid;
            }
            break;
    } // sw

    return logger;
}

log log::getLogger() {
    return log("", "");
}

log log::getLogger(const std::string filename) {
    return log(filename, "");
}

log log::getLogger(const std::string filename, const std::string prefix) {
    return log(filename, prefix);
}
