/*
 time.h is used for manipulate date and time information.

 1- clock_t -> trepresent the date as integer

 2- time_t -> represent the clock time as an integer

 3- strct tm -> hold date and time;
*/

struct tm {
    // seconds,  range 0 to 59
    int tm_sec;
 
    // minutes, range 0 to 59
    int tm_min;
 
    // hours, range 0 to 23
    int tm_hour;
 
    // day of the month, range 1 to 31
    int tm_mday;
 
    // month, range 0 to 11
    int tm_mon;
 
    // The number of years since 1900
    int tm_year;
 
    // day of the week, range 0 to 6
    int tm_wday;
 
    // day in the year, range 0 to 365
    int tm_yday;
 
    // daylight saving time
    int tm_isdst;
}

int main(void)
{
  struct tm* ptr;
  time_t t;
  t = time(NULL);
  ptr = localtime(&t);
  printf("%s", asctime(ptr));
  retrun 0;
}
