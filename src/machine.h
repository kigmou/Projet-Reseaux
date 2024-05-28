#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum MachineType{
    STATION=1,
    SWITCH=2
} machineType;

typedef struct machine
{
    enum MachineType type;
    size_t numMachine;
    void* ptr;
}machine;

