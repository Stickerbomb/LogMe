//
// Created by Yehor on 12.04.2021.
//

#ifndef LOGME_LOGGER_H
#define LOGME_LOGGER_H

#include <string>
#include <fstream>

#include <functional>

namespace logme {

    enum class LogLevel {
        Info = 0,
        Debug,
        Warn,
        Error,
        Verbose
    };

    class ILogger {
    public:
        using endlType = std::ostream &(std::ostream &);

    public:
        template<typename T>
        ILogger &operator<<(const T &data) {
//            if (parent_.level_ >= log_level::LOG_DEBUG) {
//                if (start_of_line_) {
//                    parent_.prefix_message();
//                    start_of_line_ = false;
//                }
//
//                parent_.log_stream_ << data;
//            }
            getStream() << prefix_ << data;
            return *this;
        }

        ILogger &operator<<(endlType endl);

        static std::string getLevelName(LogLevel level);

    protected:
        ILogger(const std::string &prefix, LogLevel level) : prefix_(prefix), level_(level) {}

        virtual std::basic_ostream<char> &getStream() = 0;


    private:
        std::string prefix_;
        LogLevel level_;
    };

    class ConsoleLogger : public ILogger {
    public:
        static std::function<const ConsoleLogger &(LogLevel)> getLoggerFunc;

    public:
        explicit ConsoleLogger(LogLevel level);

    protected:
        std::basic_ostream<char> &getStream() override {
            return stream_;
        }

    private:
        std::ostream stream_;
    };

    class FileLogger : public ILogger {
    public:
        explicit FileLogger();

    protected:
        std::basic_ostream<char> &getStream() override {
            return stream_;
        }

    private:
        std::fstream stream_;
    };
}

std::function<const logme::ConsoleLogger &(logme::LogLevel)> getLogger();

const logme::FileLogger &getLogger(const std::string &filename, const std::string &prefix = "");

#define INFO logme::LogLevel::Info
#define DEBUG logme::LogLevel::Debug
#define WARNING logme::LogLevel::Warn
#define ERROR logme::LogLevel::Error

#endif //LOGME_LOGGER_H
