#pragma once

typedef enum MachineType{
    STATION=1,
    SWITCH=2
} machineType;

typedef struct machine
{
    enum MachineType type;
    int numMachine;
    void* ptr;
}machine;

