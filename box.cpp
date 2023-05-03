#include "box.h"
#include "anscii.h"
#include "terminal.h"

void Terminal::box(int type) {
  const char *set[6];
  if (type == 0) {      // For normal/default box
    set[0] = _VER_n;    // Vertical line
    set[1] = _TL_n;     // Top left corner
    set[2] = _TR_n;     // Top right corner
    set[3] = _HOR_n;    // Horizontal line
    set[4] = _BL_n;     // Bottom Left corner
    set[5] = _BR_n;     // Bottom Right Corner
  }                     //
  else if (type == 1) { // For rounded corners
    set[0] = _VER_n;    // Vertical line
    set[1] = _TL_r;     // Top left corner
    set[2] = _TR_r;     // Top right corner
    set[3] = _HOR_n;    // Horizontal line
    set[4] = _BL_r;     // Bottom Left corner
    set[5] = _BR_r;     // Bottom Right Corner
  }                     //
  else if (type == 2) { // For bold border
    set[0] = _VER_b;    // Vertical line
    set[1] = _TL_b;     // Top left corner
    set[2] = _TR_b;     // Top right corner
    set[3] = _HOR_b;    // Horizontal line
    set[4] = _BL_b;     // Bottom Left corner
    set[5] = _BR_b;     // Bottom Right Corner
  }

  else if (type == 3) { // For double border
    set[0] = _VER_d;    // Vertical line
    set[1] = _TL_d;     // Top left corner
    set[2] = _TR_d;     // Top right corner
    set[3] = _HOR_d;    // Horizontal line
    set[4] = _BL_d;     // Bottom Left corner
    set[5] = _BR_d;     // Bottom Right Corner
  }                     //
  else {                // If any other value is sent, use default box
    set[0] = _VER_n;    // Vertical line
    set[1] = _TL_n;     // Top left corner
    set[2] = _TR_n;     // Top right corner
    set[3] = _HOR_n;    // Horizontal line
    set[4] = _BL_n;     // Bottom Left corner
    set[5] = _BR_n;     // Bottom Right Corner
  }

  printf("\x1b[2J\x1b[3J"); // 2J==>clear visible region 3J==>clear scroll back
  _border = false; // After clearing screen any previous border will be erased
                   // to
  printf("\x1b[1;1H");

  // Top Horizontal line
  for (int j = 1; j <= width__; ++j) {
    if (j != 1 && j != width__) {
      printf("%s", set[3]);
    } else if (j == 1) {
      printf("%s", set[1]);
    } else if (j == width__) {
      printf("%s", set[2]);
    }
  }
  // For vertical lines
  for (int j = 2; j <= height__; ++j) {
    mv_xy(1, j);
    printf("%s", set[0]);
    mv_xy(width__, j);
    printf("%s", set[0]);
  }

  // Bottom Line
  mv_xy(1, height__);
  for (int j = 1; j <= width__; ++j) {
    if (j != 1 && j != width__) {
      printf("%s", set[3]);
    } else if (j == 1) {
      printf("%s", set[4]);
    } else if (j == width__) {
      printf("%s", set[5]);
    }
  }
  fflush(stdout);
  _border = true;
  mv_xy(0, 0);
}

void Terminal::draw_footer() {
  mv_xy(1, height__ - 2);
  for (int j = 1; j < width__ - 1; ++j) {
    printf("╌");
  }
  mv_xy(1, height__ - 1);
  printf("%s", "ESC→ Exit        Ctrl+R→ Restart Test");
  fflush(stdout);
}
