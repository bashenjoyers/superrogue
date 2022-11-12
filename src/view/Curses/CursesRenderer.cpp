#include "CursesRenderer.h"
using namespace Ncurses;

namespace superrogue::view {

CursesRenderer::CursesRenderer(WindowConfig conf) : Renderer() {
    NcursesAPI::NcursesAPIPtr ncurses = NcursesAPI::getInstance();
    win = ncurses->getWindow(conf.height, conf.width, conf.xPos, conf.yPos);
    win->setName("Viewport");
}

CursesMapRenderer::CursesMapRenderer(WindowConfig conf) : CursesRenderer(conf) {}

void CursesMapRenderer::render(RenderInfo info) {
    win->clearViewport();
    std::vector<std::vector<char>> renderMap = conv.convertMap(info.map);

    for (size_t y = 0; y < renderMap[0].size(); y++) {
        for (size_t x = 0; x < renderMap.size(); x++) {
            win->drawElement(renderMap[x][y], x, y);
        }
    }
}

void CursesRenderer::resetWindow(WindowConfig newConf) {
    conf = newConf;
    win->resize(conf.width, conf.height);
    win->moveTo(conf.xPos, conf.yPos);
}

}