#include "anscii.h"
#include "ttyspeed.h"
#include <string.h>
#include <string>

int ttySpeed::check(char c) {
  if (c < 32 || c > 122) {
    non_ascii(c);
    return 0;
  }
  // For normal characters
  if (c == text[index]) { // Character matches
    correct();
    return 0;
  } else {
    incorrect();
  }
  return 0;
}

void ttySpeed::correct() {
  if (y == height__)
    return;
  if (x <= width__ - 1) { // Is before the border line
    if (text[index] != ' ')
      printf("%s%c%s", theme.correct, text[index], theme.reset);
    else
      printf("%s·%s", theme.space, theme.reset);
    fflush(stdout);
    *(arr + index) = 1; // 1 correct 0 not touched 2 incorrect
    x++;                // cursor
    index++;
    count++;
    if (x == width__) {
      mv_nextline();
      mv_right(1);
    }
  }
}

void ttySpeed::incorrect() {
  if (y == height__)
    return;
  if (x <= width__ - 1) { // Is before the border line
    if (text[index] != ' ') {
      printf("%s%c%s", theme.incorrect, text[index], theme.reset);
    } else {
      printf("%s%s·%s", __STRIKE_, theme.incorrect, theme.reset);
    }

    *(arr + index) = 2;
    x++;
    fflush(stdout);
    index++;
    count++;

    if (x == width__) {
      mv_nextline();
      mv_right(1);
    }
  }
}

void ttySpeed::non_ascii(char a) {
  switch (a) {
  case 127:
    handle_backspace();
    break;
  case 8:
    ctrl_backspace();
    break;
  }
  return;
}

void ttySpeed::handle_backspace() {
  if (index == 0)
    return;
  /* if (text[index - 1] == ' ')
    return;
  */
  backspace_count++;
  if (x <= ((_border) ? 2 : 1)) {
    if (y == ((_border) ? 2 : 1)) // No place to move Y-axis
      return;
    else {
      mv_xy(width__ - 1, y - 1); // Move to (end-1)col of previous
      if (text[index - 1] != ' ') {
        printf("%s%c%s", theme.text, text[index - 1], theme.reset);
      } else {
        printf("%s·%s", theme.space, theme.reset);
      }
      this->x = this->x + 1;
      mv_left(1);
      index--;
      *(arr + index) = 0;
      fflush(stdout);
      return;
    }
  }
  mv_left(1);
  if (text[index - 1] != ' ') {
    printf("%s%c%s", theme.text, text[index - 1], theme.reset);
  } else {
    printf("%s·%s", theme.space, theme.reset);
  }
  this->x = this->x + 1;
  fflush(stdout);
  index--;
  *(arr + index) = 0;
  mv_left(1);
  return;
}
void ttySpeed::ctrl_backspace() { return; }

void ttySpeed::printText(std::string text, int x, int y) {
  // Set the values of properties
  this->text = text;
  this->str_len = text.length();
  this->arr = new int[str_len];
  memset(this->arr, 0, str_len);

  printf("\033[%d;%dH", y, x); // Move to x,y
  this->y = y;
  this->x = x;
  int width = (_border) ? width__ - 2 : width__;
  int text_len = (int)text.length();
  for (int i = 0; i < text_len; ++i) {
    if (i % width == 0) {
      mv_nextline();
      usleep(26000);
      if (this->y == height__) {
        break;
      }
      mv_right(1);
      //      (text[i] == ' ') ? printf("⎵") : printf("%c", text[i]);·
      (text[i] == ' ') ? printf("%s·%s", theme.dimtext, theme.reset)
                       : printf("%s%c%s", theme.text, text[i], theme.reset);
    } else {
      if (text[i] == '\n') {
        printf("%s↵%s", theme.text, theme.reset);
        mv_nextline();
        if (this->y == height__) {
          break;
        }
        mv_right(1);
      } else {
        if (text[i] == ' ') {
          //          printf("⎵");
          //         printf("·");
          printf("%s·%s", theme.dimtext, theme.reset);
        } else {
          printf("%s%c%s", theme.text, text[i], theme.reset);
        }
      }
    }
  }
  mv_xy(x, y + 1); // Because printing will start from y+1 insted of y;
  fflush(stdout);
}
