#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// who i did
char *are_you_playing_banjo(const char *name) {
  char str[32];

  if(name[0] == 'r' || name[0] == 'R') {
    char str_conc[] = " plays banjo";
    char *result  = malloc(strlen(name) + strlen(str_conc) + 1);

    strcpy(result, name);
    strcat(result, str_conc);
    return result;
  }
  char str_conc[] = " dose not play banjo";
  char *result  = malloc(strlen(name) + strlen(str_conc) + 1);

  strcpy(result, name);
  strcat(result, str_conc);

  return result;
} 

// a way for do this
char *better_palying_banjo(const char *n) {
  char *r = (char*)calloc(strlen(n)+20, 1);
  strcpy(r, n);
  // thetrary operator
  strcat(r, (n[0] == 'R' || n[0] == 'r' ? " plays banjo" : " does not plays banjo")); 
  return r;
}

// the shorter way for do this
char *better_palying_banjo_2(const char *name) {
  char *res;
  // return plays if the name[0] are true, does not play if is false
  asprintf(&res, "%s %s banjo", name, name[0] == 'r' || name[0] == 'R' ? "plays" : "does not play");
  return res;
}

int main(void) {
  const char name[] = "petru";
  char *result = are_you_playing_banjo(name);
  return 0;
}
