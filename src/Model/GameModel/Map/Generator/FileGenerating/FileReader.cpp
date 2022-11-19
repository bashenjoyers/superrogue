#include "FileReader.h"
#include <fstream>

std::vector<std::string> GameModel::Map::FileReader::readFile(const std::string& path) {
    std::vector<std::string> result = std::vector<std::string>();
    std::ifstream file(path);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            result.push_back(line);
        }
        file.close();
    }
    return result;
}
