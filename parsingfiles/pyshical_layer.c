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

    uint32_t captured_length = fourbytearray(pheader.caplen);
    *caplen = captured_length + sizeof(pkt_hdr);

    printf("Caplen: %d\n", captured_length);
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