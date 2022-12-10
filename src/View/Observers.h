#pragma once

#include "RenderData.h"

#include <memory>

class RenderDataObserver {
public:
  virtual void
  handleEvent(RenderData data) = 0;
};

