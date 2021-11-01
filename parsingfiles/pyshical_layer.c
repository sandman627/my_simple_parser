//1st layer: pyshical address
#include "pyshical_layer.h"


void parse_Wireshark(FILE* fp){
    f_hdr fheader;
    fread(&fheader, sizeof(fheader), 1, fp);
}

void parse_Pyshical(FILE* fp, uint32_t* caplen, uint8_t* datalink_type){
    *datalink_type = 0;
    parse_IEEE802(fp, caplen);
}


void parse_IEEE802(FILE* fp, uint32_t* caplen){
    pkt_hdr pheader;
    fread(&pheader, sizeof(pheader), 1, fp);

    uint32_t frame_length = 0;
    for(int i = 0; i < 4; i++){
        frame_length <<= 8;
        frame_length += pheader.caplen[3-i];
    }
    *caplen = frame_length;

    print_time(pheader);

}

void parse_PHYIEEE(FILE* fp){

}

uint32_t getframelength(pkt_hdr chunck){
    uint32_t result = 0;
    for(int i = 0; i < 4; i++){
        result <<= 8;
        result += chunck.caplen[3-i];
    }
    return result;
}

void print_time(pkt_hdr pheader){
    uint32_t sec = 0;
    uint32_t usec = 0;
    for(int i = 0; i < 4; i++){
        sec <<= 8;
        usec <<= 8;
        sec += pheader.timeval_sec[3-i];
        usec += pheader.timeval_usec[3-i];
    }

    time_t t_sec = sec;
    printf("%s",ctime(&t_sec));

    /*
    Code for usec
    */
}