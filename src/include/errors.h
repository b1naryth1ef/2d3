#pragma once

#include <exception>
#include <stdio.h>
#include <string>
#include <cstdarg>

enum ErrorType {
    GENERIC,
    UNDEFINED_INPUT,
    INVALID_INPUT,
    NOTIMPLEMENTTED
};

class GenericEngineError: public std::exception {
    public:
        GenericEngineError (ErrorType e, const char* format, ...) {
            printf("%s: ", getErrorString(e).c_str());
            va_list argptr;
            va_start(argptr, format);
            vfprintf(stdout, format, argptr);
            va_end(argptr);
            printf("\n\n\n");
        }

        std::string getErrorString(ErrorType e) {
            if (e == GENERIC) {
                return std::string("GenericError");
            } else if (e == UNDEFINED_INPUT) {
                return std::string("UndefinedInputError");
            } else if (e == INVALID_INPUT ) {
                return std::string("InvalidInputError");
            } else if (e == NOTIMPLEMENTTED) {
                return std::string("NotImplementtedError");
            } else {
                return std::string("Error");
            }
        }
};