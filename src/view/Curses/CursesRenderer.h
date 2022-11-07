#pragma once

#include "../Renderer.h"
#include "../Converters/CharDataConverter.h"

#include "CursesAPI.h"

namespace superrogue::view {

class CursesRenderer : public Renderer {
public:
    CursesRenderer(WindowConfig conf);

protected:
    CharConverter conv;
    NCurses::NcursesWindow win;    
};

}