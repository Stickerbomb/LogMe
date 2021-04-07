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
#include <functional>


class log {
public:

    enum class log_level { ERROR, WARNING, INFO, DEBUG};

    log(std::string filename,std::string prefix ) : prefix(prefix) {
        if(!filename.empty())
            writeFileStream.open(filename);
    }

    static logstream log();
    static log getLogger(log_level level = log_level::INFO);
    log getLogger(const std::string filename);
    log getLogger(const std::string filename, const std::string prefix);
    friend log &operator << (log &logger, const log_level l_type);


    virtual ~log();

private:
    std::string prefix;
    std::ofstream writeFileStream;

};


#endif //LOGME_LOG_H
