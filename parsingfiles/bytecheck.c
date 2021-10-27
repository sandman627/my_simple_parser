#include "bytecheck.h"


void bytehexprint(FILE* fp, int bytenum){
    uint8_t temp;
    fread(&temp, sizeof(temp), 1, fp);

    for(int i = 0; i < bytenum; i++){
        printf("%02x ", temp);
        if(i / 8 == 7){
            printf("  ");
        }
        else if (i /16 == 15){
            printf("\n");
        }
    }
}