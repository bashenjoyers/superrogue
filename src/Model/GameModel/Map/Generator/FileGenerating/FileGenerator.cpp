#include "FileGenerator.h"

GameModel::Map::FileGenerator::FileGenerator() {
    fileReader = std::make_shared<FileReader>();
    mapEntityProvider = std::make_shared<MapEntityProvider>();
    environmentVariablesProvider = std::make_shared<Common::EnvironmentVariablesProvider>();
}

std::vector<std::vector<GameModel::Abstract::MapEntity>> GameModel::Map::FileGenerator::generate() {
    std::string pathToMap = environmentVariablesProvider->getEnvironmentVariable(mapEnvVariableKey);
    std::vector<std::string> fileContent = fileReader->readFile(pathToMap);
    return convertFileContentToMap(fileContent);
}

std::vector<std::vector<GameModel::Abstract::MapEntity>>
GameModel::Map::FileGenerator::convertFileContentToMap(const std::vector<std::string>& fileContent) {
    std::vector<std::vector<Abstract::MapEntity>> result = std::vector<std::vector<Abstract::MapEntity>>();

    for (const auto& fileLine: fileContent) {
        std::vector<Abstract::MapEntity> mapLine = std::vector<Abstract::MapEntity>();

        for (char fileLineChar: fileLine) {
            Abstract::MapEntity mapEntity = mapEntityProvider->getMapEntityBySymbol(fileLineChar);
            mapLine.push_back(mapEntity);
        }

        result.push_back(mapLine);
    }
    return result;
}
