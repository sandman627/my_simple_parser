//1st layer: pyshical address
#include "pyshical_layer.h"


extern int caplength;  // includes 16 bit pkt header but not file header (ethernet header + frame)


void parse_Wireshark(FILE* fp){
    f_hdr fheader;
    fread(&fheader, sizeof(fheader), 1, fp);
}

void parse_Pyshical(FILE* fp, uint32_t* ptotalpacketlength, uint8_t* datalink_type){
    *datalink_type = 0;
    parse_IEEE802(fp, ptotalpacketlength);
}

void parse_IEEE802(FILE* fp, uint32_t* ptotalpacketlength){
    pkt_hdr pheader;
    fread(&pheader, sizeof(pheader), 1, fp);

    caplength = fourbytearray(pheader.caplen);
    *ptotalpacketlength = fourbytearray(pheader.caplen) + sizeof(pkt_hdr);

    printf("Caplen: %d\n", fourbytearray(pheader.caplen));
    printf("Length: %d\n", fourbytearray(pheader.len));
    print_time(pheader);
}

void print_time(pkt_hdr pheader){
    uint32_t sec = fourbytearray(pheader.timeval_sec);
    uint32_t usec = fourbytearray(pheader.timeval_usec);

    time_t t_sec = sec;
    printf("Time: %s",ctime(&t_sec));

    /*
    Code for usec
    */
}