#pragma once

#include <string>
#include <vector>
#include <sstream>
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/Map/Generator/FileGenerating/MapEntityProvider.h"
#include "Model/GameModel/Map/Generator/FileGenerating/FileReader.h"
#include "Common/environmentVariables/EnvironmentVariablesProvider.h"

namespace GameModel::Map {

    class FileGenerator {
    public:
        FileGenerator();
        std::vector<std::vector<GameModel::Abstract::MapEntity>> generate();
    private:
        std::vector<std::vector<Abstract::MapEntity>> convertFileContentToMap(const std::vector<std::string>& fileContent);

        std::shared_ptr<MapEntityProvider> mapEntityProvider;
        std::shared_ptr<FileReader> fileReader;
        std::shared_ptr<Common::EnvironmentVariablesProvider> environmentVariablesProvider;

        const std::string mapEnvVariableKey = "superrogue_map_path";
    };
}
