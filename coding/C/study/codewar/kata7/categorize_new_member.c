#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

enum membership {
  OPEN = 1,
  SENIOR = 0
};

int main() {
  int members[][2] = {
    {77, 22},
    {20, -1},
    {34, 7},
    {67, 2},
    {78, 24}
  };
}

void open_or_senior (size_t n, const int members[n][2], enum membership membership[n]) {

}
