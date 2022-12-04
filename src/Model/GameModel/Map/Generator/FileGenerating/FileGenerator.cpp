#include "FileGenerator.h"

GameModel::Generation::Map::FileGenerator::FileGenerator() {
    fileReader = FileReader();
    mapEntityProvider = MapEntityProvider();
}

std::vector<std::vector<GameModel::Abstract::MapEntity>> GameModel::Generation::Map::FileGenerator::generate() {
    std::string pathToMap = Common::EnvironmentVariablesProvider::getEnvironmentVariable(SUPERROGUE_CONTENT);
    std::vector<std::string> fileContent = fileReader.readFile(pathToMap + "/" + level1Map);
    return convertFileContentToMap(fileContent);
}

std::vector<std::vector<GameModel::Abstract::MapEntity>>
GameModel::Generation::Map::FileGenerator::convertFileContentToMap(const std::vector<std::string>& fileContent) {
    std::vector<std::vector<Abstract::MapEntity>> result = std::vector<std::vector<Abstract::MapEntity>>();

    for (const auto& fileLine: fileContent) {
        std::vector<Abstract::MapEntity> mapLine = std::vector<Abstract::MapEntity>();

        for (char fileLineChar: fileLine) {
            Abstract::MapEntity mapEntity = mapEntityProvider.getMapEntityBySymbol(fileLineChar);
            mapLine.push_back(mapEntity);
        }

        result.push_back(mapLine);
    }
    return result;
}
