#include "bytecheck.h"


void bytehexprint(FILE* fp, int bytenum){
    uint8_t temp;
    for(int i = 0; i < bytenum; i++){
        fread(&temp, sizeof(temp), 1, fp);
        printf("%02x ", temp);

        if (i % 16 == 15){
            printf("\n");
        }else if (i % 8 == 7){
            printf("  ");
        }
    }
    printf("\n");
    fseek(fp, -bytenum, 1);
}

uint32_t fourbytearray(uint8_t array[4]){
    uint32_t result = 0;
    for(int i = 0; i < 4; i++){
        result <<= 8;
        result += array[3-i];
    }
    return result;
}

uint16_t twobytearray(uint8_t array[2]){
    uint16_t result = array[0];
    result <<= 8;
    result += array[1];
    return result;
}