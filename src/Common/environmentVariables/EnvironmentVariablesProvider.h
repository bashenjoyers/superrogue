#pragma once

#include <string>
#include <vector>
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/Map/Generator/FileGenerating/MapEntityProvider.h"
#include "Model/GameModel/Map/Generator/FileGenerating/FileReader.h"

namespace GameModel::Map {

    class EnvironmentVariablesProvider {
    public:
        static std::string& getEnvironmentVariable(const std::string & variable);
    };
}