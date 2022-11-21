#pragma once

#include "../Converters/CharDataConverter.h"
#include "../Renderer.h"

#include "Common/Ncurses/CursesAPI.h"

#include <optional>

namespace View {
// TODO howto handle resize

class CursesSubRenderer : public Renderer {
public:
    CursesSubRenderer(WindowConfig conf);
  virtual void resetWindow(WindowConfig newConf);

protected:
  CharConverter conv;
  Ncurses::NcursesWindow::NcursesWIndowPtr win;
};

class CursesMapRenderer : public CursesSubRenderer {
public:
  CursesMapRenderer(WindowConfig conf);

  virtual void render(RenderInfo info) override;
};

class CursesInventoryRenderer : public CursesSubRenderer {
public:
  CursesInventoryRenderer(WindowConfig conf);

  virtual void render(RenderInfo info) override;
  virtual void resetWindow(WindowConfig newConf) override;

private:
  void renderPotion(GameModel::Potion p, size_t row, bool selected);
  void renderEmptyPotion(size_t row, bool selected);
  void renderItem(std::optional<GameModel::Item> item, GameModel::ItemType type,
                  bool selected);
  size_t getItemRowOffset(GameModel::ItemType type);

  Ncurses::NcursesWindow::NcursesWIndowPtr equipmentWin;
  Ncurses::NcursesWindow::NcursesWIndowPtr potionsWin;

  void spawnEquipmentWindow();
  void spawnPotionsWindow();

  //TODO get from outer world
  const size_t maxPotions = 4;
  const size_t maxEquipment = 5;
};

class CursesMainMenuRenderer : public CursesSubRenderer {
public:
  CursesMainMenuRenderer(WindowConfig conf);

  virtual void render(RenderInfo info) override;
};

class CursesHeroInfoRenderer: public CursesSubRenderer {
public:
    CursesHeroInfoRenderer(WindowConfig conf);

    virtual void render(RenderInfo info) override;
private:
    void renderCharacteristics(GameModel::Characteristics characteristics);

    Ncurses::NcursesWindow::NcursesWIndowPtr characteristicsWin;
    void spawnCharacteristicsWindow();


    const size_t characteristicsCount = 5;
};

} // namespace View
