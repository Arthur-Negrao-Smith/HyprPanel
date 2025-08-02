#include "window.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_timer.h>

PanelWindow::PanelWindow(std::string window_tittle, int width, int height,
                         int fps)
    : window_tittle(window_tittle), width(width), height(height) {
  this->delay = this->calculate_delay(fps);
}

bool PanelWindow::create_window() {
  this->window = SDL_CreateWindow(this->window_tittle.c_str(), this->width,
                                  this->height, PANEL_WINDOW_FLAGS);

  if (this->window)
    return true;

  return false;
}

bool PanelWindow::create_renderer() {
  this->renderer = SDL_CreateRenderer(this->window, nullptr);
  if (this->renderer)
    return true;

  return false;
}

void PanelWindow::change_height(int height) { this->height = height; }

void PanelWindow::change_width(int width) { this->width = width; }

int PanelWindow::get_height() { return this->height; }

int PanelWindow::get_width() { return this->width; }

int PanelWindow::calculate_delay(int fps) { return (int)((1 / fps) * 1000); }

void PanelWindow::clock() { SDL_Delay(this->delay); }

void PanelWindow::destroy() {
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
}
