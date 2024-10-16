#include <stdio.h>

int past(int hours, int minutes, int seconds) {
  return (hours * 3600 + minutes * 60 + seconds) * 1000;
}

int main() {
  int hours = 0, minutes = 2, seconds = 50;
  printf("since %dh %dm %ds, passed %d", hours, minutes, seconds, past(hours, minutes, seconds));
  return 0;
}
