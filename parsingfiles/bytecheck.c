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