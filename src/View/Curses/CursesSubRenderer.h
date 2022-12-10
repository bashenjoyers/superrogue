#pragma once

#include "../Converters/CharDataConverter.h"
#include "../Renderer.h"

#include "Common/Ncurses/CursesAPI.h"
#include "../RenderData.h"

#include <optional>

namespace View {
// TODO howto handle resize

/**
 * @brief Curses sub renderer -- some parts of screen (e.g. inventory and map)
 * 
 */
class CursesSubRenderer : public Renderer {
public:
  /**
   * @brief Construct a new Curses Sub Renderer object
   * 
   * @param conf -- window configuration
   */
  CursesSubRenderer(WindowConfig conf);

  /**
   * @brief reset window settings (for resize)
   * 
   * @param newConf 
   */
  virtual void resetWindow(WindowConfig newConf);

protected:
  CharConverter conv;
  Ncurses::NcursesWindow::NcursesWIndowPtr win;
};

/**
 * @brief Map subrenderer
 * 
 */
class CursesMapRenderer : public CursesSubRenderer {
public:
  /**
   * @brief Construct a new Curses Map Renderer object
   * 
   * @param conf -- window configuration
   */
  CursesMapRenderer(WindowConfig conf);

  /**
   * @brief render map
   * 
   * @param info -- current game state
   */
  virtual void render(RenderData data) override;
};

/**
 * @brief Inventory subrenderer
 * 
 */
class CursesInventoryRenderer : public CursesSubRenderer {
public:
  /**
   * @brief Construct a new Curses Inventory Renderer object
   * 
   * @param conf -- window configuration
   */
  CursesInventoryRenderer(WindowConfig conf);

  /**
   * @brief render inventory
   * 
   * @param info -- current game state
   */
  virtual void render(RenderData data) override;

  /**
   * @brief reset window settings (need to affect subwindows)
   * 
   * @param newConf -- new window settings
   */
  virtual void resetWindow(WindowConfig newConf) override;

private:
  void renderPotion(RenderItem p, size_t row, bool selected);
  void renderEmptyPotion(size_t row, bool selected);
  void renderItem(std::optional<RenderItem> item, RenderEquipmentType type,
                  bool selected);
  size_t typeToPos(RenderEquipmentType type);

  Ncurses::NcursesWindow::NcursesWIndowPtr equipmentWin;
  Ncurses::NcursesWindow::NcursesWIndowPtr potionsWin;

  void spawnEquipmentWindow();
  void spawnPotionsWindow();

  //TODO get from outer world
  const size_t maxPotions = 4;
  const size_t maxEquipment = 5;
};

/**
 * @brief Main menu subrenderer (not implemented yet)
 * 
 */
class CursesMainMenuRenderer : public CursesSubRenderer {
public:
  CursesMainMenuRenderer(WindowConfig conf);

  virtual void render(RenderData data) override;
};

/**
 * @brief Hero information subrenderer
 * 
 */
class CursesHeroInfoRenderer: public CursesSubRenderer {
public:
    /**
     * @brief Construct a new Curses Hero Info Renderer object
     * 
     * @param conf -- window configuration
     */
    CursesHeroInfoRenderer(WindowConfig conf);

    /**
     * @brief render hero information
     * 
     * @param info -- current game state
     */
    virtual void render(RenderData data) override;

      /**
     * @brief reset window settings (need to affect subwindows)
     * 
     * @param newConf -- new window settings
     */
    virtual void resetWindow(WindowConfig newConf) override;
private:
    void renderCharacteristics(RenderPersonInfo characteristics);

    Ncurses::NcursesWindow::NcursesWIndowPtr characteristicsWin;
    void spawnCharacteristicsWindow();


    const size_t characteristicsCount = 5;
};

} // namespace View
