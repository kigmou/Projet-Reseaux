#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "switch.h"

int main()
{
    char *config = "2;01:45:23:a6:f7:ab;8;1024";
    Switch *mySwitch = init_switch(config);
    afficheSwitch(mySwitch);
    freeSwitch(mySwitch);
    return 0;
}
