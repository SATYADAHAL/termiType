#include "anscii.h"
#include "ttyspeed.h"
#include "word_generator.h"  
#include <csignal>
#include <cstdio>
#include <string.h>

int main() {
  ttySpeed t;
  int time = 5;

  WordGenerator wg;
  std::string random_text = wg.get_text(50);

  t.raw(0);
  t.box(1);
  t.cursor(true);
  t.draw_footer();
  t.time_border();
  printf("\x1b[2;2H");
  printf("Time: %d", time);

  t.printText(random_text, 1, 3);  

  char x[3] = {0};

  
  while (t.countdown) {
    read(0, &x, 3);
    if (x[0] == 0) {
      if (!t.timer_started) {
        printf("\x1b[2;2H");
        printf("Time: %02d", time);
        fflush(stdout);
        t.mv_xy(t.cursor_x(), t.cursor_y());
        continue;
      }
      t.print_time(time);
      continue;
    }
    if (x[0] == 27 && x[1] == 0) {
      t.normal();
      exit(0);
    }
    fflush(stdout);
    t.check(x[0]);
    t.print_time(time);

    if (t.is_finished()) {  
      t.countdown = 0;
      break;
    }

    memset(x, 0, 3);
  }

  t.display_result();

  while (true) {
    read(0, &x, 3);
    if (x[0] == 0)
      continue;
    if (x[0] == 27 || x[0] == 'q') {
      t.normal();
      exit(0);
    }
  }

  return 0;
}
