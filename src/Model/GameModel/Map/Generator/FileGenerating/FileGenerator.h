#pragma once

#include <string>
#include <vector>
#include <sstream>
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/Map/Generator/FileGenerating/MapEntityProvider.h"
#include "Model/GameModel/Map/Generator/FileGenerating/FileReader.h"
#include "Common/environmentVariables/EnvironmentVariablesProvider.h"
#include "Model/GameModel/Map/Generator/MapGenerator.h"

namespace GameModel::Map {

    class FileGenerator : public MapGenerator {
    public:
        FileGenerator();
        std::vector<std::vector<GameModel::Abstract::MapEntity>> generate();
    private:
        std::vector<std::vector<Abstract::MapEntity>> convertFileContentToMap(const std::vector<std::string>& fileContent);

        MapEntityProvider mapEntityProvider;
        FileReader fileReader;

        const std::string SUPERROGUE_CONTENT = "SUPERROGUE_CONTENT";
        const std::string level1Map = "level1.txt";
    };
}
