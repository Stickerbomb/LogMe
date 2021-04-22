//
// Created by Yehor on 12.04.2021.
//

#include "logger.h"

namespace logme {

    ILogger &ILogger::operator<<(ILogger::endlType endl) {
        getStream() << endl;
        return *this;
    }

    std::string ILogger::getLevelName(LogLevel level) {
        switch (level) {
            case LogLevel::Info:
                return "Info";
            case LogLevel::Debug:
                return "Debug";
            case LogLevel::Warn:
                return "Warn";
            case LogLevel::Error:
                return "Error";
        }
        return "Verbose";
    }

    ConsoleLogger::ConsoleLogger(LogLevel level) :
            ILogger(getLevelName(level), level),
            stream_(){

    }
}