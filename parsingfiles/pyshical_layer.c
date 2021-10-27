//1st layer: pyshical address
#include "pyshical_layer.h"


void parse_Pyshical(FILE* fp, uint32_t* caplen, uint8_t* datalink_type){
    datalink_type = 0;

    *caplen = parse_Wireshark(fp);

}

uint32_t parse_Wireshark(FILE* fp){
    f_hdr fheader;
    pkt_hdr pheader;
    
    fread(&fheader, sizeof(fheader), 1, fp);
    fread(&pheader, sizeof(pheader), 1, fp);

    return framelength(pheader);
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