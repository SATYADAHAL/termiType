#ifndef TERMINAL_H
#define TERMINAL_H
#include "anscii.h"
#include <iostream>
#include <sys/ioctl.h> //gets the height and widht of terminal
#include <termios.h>   // terminal all properites
#include <unistd.h>

class Terminal {
private:
  // Get tty Properties from system
  int tty_height();
  int tty_width();

protected:
  /*Height and Width of Terminal*/
  int height__, width__;
  /* current cursor_position*/
  int x, y;
  /*Some ttyProperties */
  bool _cbreak, _raw, _normal, _border, _cursor, _nextBuff;

public:
  struct termios initial_state;
  Terminal();
  ~Terminal();

  /*Change the terminal states*/
  void init();
  int cbreak(int);
  int raw(int);
  void normal();
  void status();
  void cursor(bool);

  // Return Properties of terminal
  int height();
  int widht();

  // Get cursor position
  int cursor_x();
  int cursor_y();
  // Move cursor
   void mv_right(int);
   void mv_left(int);
   void mv_down(int);
   void mv_up(int);
   void mv_xy(int, int);
  void mv_nextline();
   void mv_prevline();

  // Draw Shapes
  void box(int x);
  void box();
  void draw_footer();

  // Clear the terminal
  void clear();
  void clearScrollback();
  void clearScreenUp();
  void clearScreenDown();
  void clearLine();
  void clearLineRight();
  void clearLineLeft();
};

#endif
