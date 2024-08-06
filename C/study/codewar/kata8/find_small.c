#include <stddef.h>

int find_smallest_int(const int array[/* len */], size_t len)
{
  int buff_int = array[0]; 
  for(size_t i = 1; i < len; i++)
    buff_int > array[i] ? buff_int = array[i] : 1;
  return 0;
}
