#ifndef BYTECHECK
#define BYTECHECK

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


void bytehexprint(FILE* fp, int bytenum);
uint32_t fourbytearray(uint8_t array[4]);
uint16_t twobytearray(uint8_t array[2]);


#endif