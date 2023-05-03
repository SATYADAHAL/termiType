#include "terminal.h"

 void Terminal::mv_xy(int x, int y) {
  if (!_border) {
    printf("\x1b[%d;%dH", y, x);
    fflush(stdout);
    this->x = (x <= 1) ? 1 : (x >= width__) ? width__ : x;
    this->y = (y <= 1) ? 1 : (y >= height__) ? height__ : y;
    return;
  }
  this->x = x = (x <= 1) ? 2 : (x >= width__) ? width__ - 1 : x;
  this->y = y = (y <= 1) ? 2 : (y >= height__) ? height__ - 1 : y;
  printf("\x1b[%d;%dH", y, x);
  fflush(stdout);
  return;
}

void Terminal::mv_left(int x) {
  if (x <= 0)
    return;
  printf("\x1b[%dD", x);
  fflush(stdout);
  this->x = (this->x - x >= 1) ? this->x - x : 1;
  return;
}

void Terminal::mv_up(int y) {
  if (y <= 0)
    return;
  printf("\x1b[%dA", y);
  fflush(stdout);
  this->y = (this->y - y >= 1) ? this->y - y : 1;
  return;
}

  void Terminal::mv_right(int x) {
  if (x <= 0)
    return;
  printf("\x1b[%dC", x);
  fflush(stdout);
  this->x = (this->x + x <= width__) ? this->x + x : width__;
  return;
}

void Terminal::mv_down(int y) {
  if (y <= 0)
    return;
  printf("\x1b[%dB", y);
  fflush(stdout);
  this->y = (this->y + y <= height__) ? this->y + y : height__;
  return;
}

// Move to beginning of next line
void Terminal::mv_nextline() {
  if (this->y >= height__)
    return;
  printf("\x1b[E");
  this->y = this->y + 1;
  this->x = 1;
}

// Move to beginning of next line
void Terminal::mv_prevline() {
  if (this->y <= 1)
    return;
  printf("\x1b[F");
  this->y = this->y - 1;
  this->x = 1;
}
