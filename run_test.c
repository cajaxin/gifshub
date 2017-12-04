#include <stdio.h>
#include <unistd.h>
#include "run.h"

int main() {
     int result;

     run("./run", &result);

     return 0;
}