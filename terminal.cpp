#include "terminal.h"

// Default Constructor
Terminal::Terminal() {
  x = y = 0;
  _cbreak = _raw = _border = false;
  _normal = true;
  _cursor = true;
  height__ = tty_height();
  width__ = tty_width();
  init();
  tcgetattr(0, &initial_state);
}

// Destructor
Terminal::~Terminal() { normal(); }

// Return terminal Properties
void Terminal::status() {
  std::cout << "Normal: " << _normal << std::endl;
  std::cout << "Cbreak: " << _cbreak << std::endl;
  std::cout << "Raw: " << _raw << std::endl;
  std::cout << "Widht: " << width__ << std::endl;
  std::cout << "Height: " << height__ << std::endl;
}

int Terminal::cursor_x() { return x; }
int Terminal::cursor_y() { return y; }
