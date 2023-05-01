#ifndef TTYSPEED_H
#define TTYSPEED_H
#include "terminal.h"
#include "time.h"
#include <time.h>

class ThemeColor {
public:
  const char *text;
  const char *correct;
  const char *incorrect;
  const char *space;
  const char *reset;
  const char *dimtext;
  const char *bold;
  ThemeColor() { 
    bold = __BOLD_;
    text = __BOLD_ __WHITE_;
    space = __GRAY_;
    dimtext = __GRAY_;
    correct = __GREEN_;
    incorrect = __RED_;
    reset = __resetT_;
  }
  void setColor(const char *text, const char *correct, const char *incorrect,
                const char *dimtext) {
    this->text = text;
    this->correct = correct;
    this->incorrect = incorrect;
    this->dimtext = dimtext;
  }
};

class ttySpeed : public Terminal, public ThemeColor {
private:
  int initial_time;
  int index;
  int str_len;
  int count;
  int *arr;
  int backspace_count;

public:
  ThemeColor theme;
  bool timer_started;
  std::string text;
  int countdown;
  int timer;

  void print_time(int);
  int current_time();
  void time_border();


  void printText(std::string, int x, int y);
  int check(char);
  void correct();
  void incorrect();
  void non_ascii(char);
  void handle_backspace();
  void ctrl_backspace();
  void display_result();
  void handle_enter();
  bool is_finished() const {
  return index >= (int)text.size();
}

  ~ttySpeed() {
    if (arr != NULL)
      delete[] arr;
  }
  ttySpeed() : Terminal() {
    initial_time = 0;
    countdown = 1;
    count = 0;
    timer_started = false;
    index = 0;
    backspace_count = 0;
  }
};

#endif
