#include "terminal.h"

void Terminal::clear() {
  // Clears the entire screen
  // The cursor doesnot moves
  printf("\x1b[2J");
}

void Terminal::clearScrollback() {
  /*
    "\033[3J" - Erases the entire scrollback buffer.
    "\033[H" - Moves the cursor to the top-left corner of the screen.
    "\033[2J" - Clears the entire screen.
 */
  printf("\033[3J\033[H\033[2J");
  mv_xy(0, 0);
  return;
}

void Terminal::clearScreenUp() {
  // Clears from the cursor position to the top of the screen
  // Moves to 0,0 or in case of border 1,1
  printf("\x1b[1J");
  mv_xy(0, 0);
}

void Terminal::clearScreenDown() {
  // Clears from the cursor position to the end of the screen
  // cursor does not move
  printf("\x1b[0J");
  return;
}

void Terminal::clearLine() {
  // Clears the entire current line
  // cursor doesnot move
  printf("\x1b[2K");
  return;
}

void Terminal::clearLineRight() {
  // Clears the line from cursor pos to EOL
  // cursor doesnot move
  printf("\x1b[0K");
  return;
}

void Terminal::clearLineLeft() {
  // Clears from the cursor position to the beginning of the current line
  // cursor doesnot move
  printf("\x1b[1K");
  return;
}
