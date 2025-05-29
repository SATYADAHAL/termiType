#include "terminal.h"
#include "ttyspeed.h"

int Terminal::tty_width() {
  struct winsize dim;
  ioctl(0, TIOCGWINSZ, &dim);
  return dim.ws_col;
}

int Terminal::tty_height() {
  struct winsize dim;
  ioctl(0, TIOCGWINSZ, &dim);
  return dim.ws_row;
 
}

// show or hide cursor
void Terminal::cursor(bool status) {
  if (status) {
    printf("\033[?25h");
    fflush(stdout);
    return;
  }
  printf("\033[?25l");
  return;
}

// Set terminal to cbreak mode
int Terminal::cbreak(int fd) {
  if (_cbreak) {
    return 0;
  }
  if (_raw) {
    normal();
  }
  struct termios t;
  if (tcgetattr(fd, &t) == -1)
    return -1;
  t.c_lflag &= ~(ICANON); // Process byte by byte instead of line buffer
  t.c_lflag |= ISIG;      // Send signal like (Ctrl+Z) to process
  t.c_iflag &= ~ICRNL;    // Turns off mapping of EnterKey to NewLine
  t.c_oflag &= ~OPOST;
  t.c_cc[VMIN] = 0;
  t.c_cc[VTIME] = 2; // Read function waits only for 200ms
  if (tcsetattr(fd, TCSAFLUSH, &t) == -1)
    return -1;
  _cbreak = true;
  _raw = false;
  _normal = false;
  return 0;
}

// Set terminal to RawMode
int Terminal::raw(int fd) {
  if (_raw) {
    return 0;
  }
  if (_cbreak) {
    normal();
  }
  struct termios t;
  if (tcgetattr(fd, &t) == -1)
    return -1;
  t.c_lflag &= ~(ICANON | ISIG | IEXTEN | ECHO);
  /* Noncanonical mode, disable signals, extended
  input processing, and no echoing */
  t.c_iflag &=
    ~(BRKINT | ICRNL | IGNBRK | IGNCR | INLCR | INPCK | ISTRIP | IXON | PARMRK);
  /* Disable special handling of CR, NL, and BREAK.
  No 8th-bit stripping or parity error handling.
  Disable START/STOP output flow control. */
  t.c_oflag &= ~OPOST;
  t.c_cc[VMIN] = 0;
  t.c_cc[VTIME] = 2; // 200ms
  /* Disable all output processing */
  /* Character-at-a-time input */
  /* with blocking */
  if (tcsetattr(fd, TCSANOW, &t) == -1)
    return -1;
  _raw = true;
  _cbreak = false;
  _normal = false;
  return 0;
}
int Terminal::widht() { return width__; }
int Terminal::height() { return height__; }

// Set terminal to normal
void Terminal::normal() {
  if (_nextBuff) {         // If switched to alternate buffer
    printf("\033[?1049l"); // Move back to normal buffer
    _nextBuff = false;
  }
  if (!_cursor) { // If no cursor hidden
    cursor(true);
    _cursor = true;
  }
  if (!_normal) {
    tcsetattr(STDIN_FILENO, TCSANOW, &initial_state);
    _raw = false;
    _cbreak = false;
    _normal = true;
  }
  return;
}

// Switch to alternate buffer if possible clear the screen move cursor to 0,0
void Terminal::init() {
  printf("\033[?1049h"); // Move to alternate buffer if possible
  _nextBuff = true;
  clearScrollback();
  mv_xy(0, 0);
}
