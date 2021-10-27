#include <stdio.h>
#include "parsing.h"


void hexprint(FILE* fp){
    buffer temp;
    fread(&temp, sizeof(temp), 1, fp);
    int a[2], b[3];
    for(int i = 0; i < 16; i++){
        printf("%02x ", temp.line[i]);
        if(i == 7){
            printf("  ");
        }
    }
    printf("\n");
}

void Parsing(FILE* fp){
    FILE* nextfp = NULL;

    uint8_t phytype; // return uint 8
    uint8_t* ethertype = parse_Datalink(fp, phytype); // return protocol number for next layer (2 bytes)
    uint8_t protocolID = parse_Network(fp, ethertype); // return uint 8 
    uint8_t apptype = parse_Transport(fp, protocolID);
    
    parse_Pyshical(fp);
    parse_Datalink(fp, phytype);
    parse_Network(fp, ethertype);
    parse_Transport(fp, protocolID);

    fp = nextfp; // after reading all the wanted data, change pointer to next packet
}