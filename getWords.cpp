#include "getWords.h"
int lineCount(FILE *fp) {
  if (fp == NULL) {
    return -1;
  }
  int line = 0;
  char c;
  while ((c = getc(fp)) != EOF) {
    if (c == '\n') {
      line++;
    }
  }
  fseek(fp, 0, SEEK_SET);
  return line;
}

int generateRandomNumber(int max) { return rand() % max; }

void assignRandom(int *arr, int line, int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = generateRandomNumber(line - 1);
    //    printf("%d%c", arr[i], (i == 99) ? '\n' : ' ');
  }
}
char A[] = "./words/allWords";
void getWords(char words[][20], int n) {
  FILE *fp = fopen(A, "r");
  if (fp == NULL) {
    printf("Couldnot Open the file\n");
    return;
  }
  int line = lineCount(fp);
  int random[n];
  assignRandom(random, line, n);
  char c;
  int current_line = 0;
  int j = 0;
  for (int i = 0; i < n;) {
    if (!(random[i] == current_line)) {
      fgets(words[i], 15, fp);
      current_line++;
    } else {
      j = 0;
      fgets(words[i], 20, fp);
      while (true) {
        c = words[i][j];
        if (c == '\n' || c == '\r' || c == ' ')
          break;
        j++;
      }
      words[i][j] = '\0';
      ++i;
      fseek(fp, 0, SEEK_SET);
      current_line = 0;
    }
  }
}

int main() {
  srand(time(NULL)); // seed the random number generator
  int number_of_words = 200;
  char words[number_of_words][20];
  getWords(words, number_of_words);
  for (int i = 0; i < number_of_words; ++i) {
    printf("%s\n", words[i]);
  }
  return 0;
}
