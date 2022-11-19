#include "EnvironmentVariablesProvider.h"

std::string& Common::EnvironmentVariablesProvider::getEnvironmentVariable(const std::string &variable) {
    const char* value = std::getenv(variable.c_str());

    std::string result;
    if (value == nullptr) {
        result = "";
    } else {
        result = value;
    }
    return result;
}
