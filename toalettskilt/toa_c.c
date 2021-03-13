#include <stdio.h>
int minutter = 2;
int nummer = 1

// C
int main() {
  int dametoalett = 1;
  int herretoalett = 0;

  if (minutter > 2) {
    herretoalett = 0;
  }
  else {
    if(nummer == 2) {
      herretoalett = 0;
    }
    else if (nummer == 1) {
      herretoalett = 1;
    }
    else {
      printf("Hva driver du med...");
    }
  }

  printf("%i",herretoalett);

  return 0;
}
