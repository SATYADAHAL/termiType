#include "box.h"
#include "ttyspeed.h"

int ttySpeed::current_time() {
  time_t seconds;
  time(&seconds);
  return seconds;
}
void ttySpeed::print_time(int default_time) {
  if (!timer_started) {
    // This is initilization part
    timer_started = true;
    initial_time = current_time();
    countdown = default_time;
    timer = default_time;
  }
  printf("\x1b[2;2H"); // Move cursor to 2,2

  if (timer_started) {
    countdown = default_time - (current_time() - initial_time);
     printf("Time: %s%02d%s", theme.correct, countdown, theme.reset);
     //    int temp = countdown;
    /*    printf("Time: ");
    while (temp) {
      const char *str;
      int temp_ = temp;
      while (temp_ > 9) {
        temp_ = temp_ / 10;
      }
      switch (temp_) {
      case 0:
        str = "🯰";
        break;
      case 1:
        str = "🯱";
        break;
      case 2:
        str = "🯲";
        break;
      case 3:
        str = "🯳";
        break;
      case 4:
        str = "🯴";
        break;
      case 5:
        str = "🯵";
        break;
      case 6:
        str = "🯶";
        break;
      case 7:
        str = "🯷";
        break;
      case 8:
        str = "🯸";
        break;
      case 9:
        str = "🯹";
        break;
      }
      printf("%s%s%s ", theme.correct, str, theme.reset);
      temp = (temp <= 999 && temp >= 100) ? temp % 100
             : (temp <= 99 && temp >= 10) ? temp % 10
                                          : temp / 10;
    }
    */
    fflush(stdout);
  } else {
    printf("%d", default_time);
    fflush(stdout);
  }
  mv_xy(x, y);
}

void ttySpeed::time_border() {
  printf("\033[3;1H");
  for (int i = 1; i <= width__; ++i) {
    if (i == 1) {
      printf("%s", _VER_RIGHT_n);
    } else if (i == width__) {
      printf("%s", _VER_LEFT_n);
    } else {
      printf("%s", _HOR_n);
    }
  }
  fflush(stdout);
  mv_xy(x, y);
  return;
}
