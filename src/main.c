#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "switch.h"

int main()
{
    switch *mySwitch = createSwitch(SWITCH, 4, 10);
    afficheSwitch(mySwitch);
    freeSwitch(mySwitch);
    
    return 0;
}
