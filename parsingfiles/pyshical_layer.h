//1st layer: pyshical address
#include "bytecheck.h"

typedef struct packet_header // 16 bytes
{
    uint8_t timeval_sec[4];
    uint8_t timeval_usec[4];
    uint8_t caplen[4];
    uint8_t len[4];   
}pkt_hdr;


void parse_Pyshical(FILE* fp, uint32_t* caplen, uint8_t* datalink_type);
void parse_IEEE802(FILE* fp, uint32_t* caplen);
void parse_PHYIEEE(FILE* fp);
uint32_t getframelength(pkt_hdr chunck);