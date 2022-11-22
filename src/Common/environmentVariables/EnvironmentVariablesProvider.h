#pragma once

#include <string>
#include <vector>
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/Map/Generator/FileGenerating/MapEntityProvider.h"
#include "Model/GameModel/Map/Generator/FileGenerating/FileReader.h"

namespace Common {

    /**
     * @brief a class that provides environment variable
     */
    class EnvironmentVariablesProvider {
    public:
        /**
         * @brief provides environment variable
         *
         * @param variable - key of environment variable to get
         *
         * @return std::string - value of environment variable
         */
        static std::string getEnvironmentVariable(const std::string & variable);
    };
}
