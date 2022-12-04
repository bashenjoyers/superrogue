#pragma once

#include <string>
#include <vector>
#include "Model/GameModel/abstract.h"

namespace GameModel::Generation::Map {

    class FileReader {
    public:
        std::vector<std::string> readFile(const std::string& path);
    };
}
