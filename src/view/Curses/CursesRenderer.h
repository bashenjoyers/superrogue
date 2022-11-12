#pragma once

#include "../Renderer.h"
#include "../Converters/CharDataConverter.h"

#include "CursesAPI.h"

namespace superrogue::view {

// TODO howto handle resize

class CursesRenderer : public Renderer {
public:
    CursesRenderer(WindowConfig conf);
    virtual void resetWindow(WindowConfig newConf) override;

protected:
    CharConverter conv;
    Ncurses::NcursesWindow::NcursesWIndowPtr win;
};

class CursesMapRenderer : public CursesRenderer {
public:
    CursesMapRenderer(WindowConfig conf);

    virtual void render(RenderInfo info) override;
};


class CursesInventoryRenderer : public CursesRenderer {

};

class CursesMainMenuRenderer : public CursesRenderer {

};

}

