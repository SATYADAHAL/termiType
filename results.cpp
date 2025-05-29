#include "ttyspeed.h"

void ttySpeed::display_result() {
  float correct = 0;
  float errors = 0;
  float total_typed = 0;
  for (int i = 0; i < str_len; ++i) {
    if (*(arr + i) == 1)
      correct++;
    else if (*(arr + i) == 2)
      errors++;
    if (*(arr + i) == 0) {
      break;
    }
    total_typed++;
  }
  clear();
  _border = false;
  box(1);
  mv_right(1);
  std::cout << "Speed(words/min): " << (correct / timer) * 12;
  mv_nextline();
  mv_right(2);
  printf("Incorrect : %6d", (int)errors);
  mv_nextline();
  mv_right(2);
  printf("Total Typed: %6d", (int)total_typed);
  mv_nextline();
  mv_right(2);
  printf("Accuracy: %6d%%",
         (total_typed == 0) ? 0 : (int)((correct / total_typed) * 100));
  mv_nextline();
  mv_right(2);
  printf("Correct : %6d", (int)correct);
  mv_nextline();
  mv_right(2);
  printf("%sRawSpeed: %d%s", theme.dimtext,
         (int)((total_typed / timer) * 12),
         theme.reset);
  mv_nextline();
  mv_right(2);
  fflush(stdout);

  printf(
    "Confidence: %6d%%",
    (backspace_count == 0)
      ? 100
      : (int)(100 -
      (((backspace_count) / (total_typed + backspace_count)) * 100)));
  fflush(stdout);
  for (int i = 0; i < 3; ++i)
    mv_nextline();
  mv_right(2);
  std::cout << theme.dimtext << "Press q or Esc to quit" << theme.reset << std::flush;
}
