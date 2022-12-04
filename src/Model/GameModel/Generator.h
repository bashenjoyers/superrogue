#pragma once

#include <random>

namespace GameModel::Generation {
class Generator {
public:
    virtual ~Generator() = default;
protected:
    std::random_device randomDevice;
};
}