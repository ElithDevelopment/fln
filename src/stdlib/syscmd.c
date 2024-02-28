#include "syscmd.h"
#include <stdlib.h>

int syscmd(char *cmd) { return system(cmd); }
