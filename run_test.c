#include <stdio.h>
#include <unistd.h>
#include "run.h"

int main() {
     int result;

     run("ls", &result);

     return 0;
}