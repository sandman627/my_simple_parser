//1st layer: pyshical address
#include <stdio.h>
#include <stdint.h>
#include "pyshical_layer.h"


uint8_t parse_Pyshical(FILE* fp){
    uint8_t datalink_type = 0;

    parse_Wireshark(fp);

    return datalink_type;
}

void parse_Wireshark(FILE* fp){
    FILE* startpoint = fp;
    f_hdr fheader;
    pkt_hdr pheader;
    
    fread(&fheader, sizeof(fheader), 1, fp);
    fread(&pheader, sizeof(pheader), 1, fp);

}


void parse_PHYIEEE(FILE* fp){

}

uint32_t framelength(pkt_hdr chunck){
    uint32_t result = 0;

    for(int i = 0; i < 4; i++){
        result <<= 8;
        result += chunck.caplen[i];
    }
    return result;
}