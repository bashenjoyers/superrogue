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
    Ncurses::NcursesWindow::NcursesWIndowPtr win;
    const size_t windowOffset = 1; 
};

class CursesMapRenderer : public CursesRenderer {
public:
    CursesMapRenderer(WindowConfig conf);

    virtual void render(RenderInfo info) override;
    virtual void resetWindow(WindowConfig newConf) override;
};


}