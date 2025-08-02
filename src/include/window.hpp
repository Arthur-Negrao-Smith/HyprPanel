#ifndef PANEL_WINDOW_H
#define PANEL_WINDOW_H

#include <SDL3/SDL.h>
#include <string>

const long PANEL_WINDOW_FLAGS = SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS;

class PanelWindow {
public:
  PanelWindow(std::string, int, int, int);
  bool create_window();
  bool create_renderer();
  void change_width(int);
  void change_height(int);
  int get_height();
  int get_width();
  void clock();
  void destroy();

private:
  std::string window_tittle;
  int width, height, delay;
  SDL_Window *window;
  SDL_Renderer *renderer;

  int calculate_delay(int);
};
#endif
