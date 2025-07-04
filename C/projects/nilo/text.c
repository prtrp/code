#include <unistd.h>

int main() {
    write(STDOUT_FILENO, "hello world\n", 12);
    return 0;
}
