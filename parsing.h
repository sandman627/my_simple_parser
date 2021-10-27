#include <stdio.h>
#include <stdint.h>
#include "parsingfiles/datalink_layer.h"
#include "parsingfiles/network_layer.h"
#include "parsingfiles/transport_layer.h"

FILE* currentpointer;
FILE* nextpointer;

typedef struct Buffer // 16 bytes
{
    uint8_t line[16];
}buffer;

void hexprint(FILE* fp);
void Parsing(FILE* fp);