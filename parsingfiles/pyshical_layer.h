//1st layer: pyshical address
#include "bytecheck.h"
#include <time.h>


typedef struct file_header // 24 bytes
{
    uint8_t magic[4];
    uint8_t major[2], minor[2];
    uint8_t timezone[4];
    uint8_t timestamp[4];
    uint8_t snaplen[4];
    uint8_t FCS_and_linktype[4];
}f_hdr;


typedef struct packet_header // 16 bytes
{
    uint8_t timeval_sec[4];
    uint8_t timeval_usec[4];
    uint8_t caplen[4];
    uint8_t len[4];   
}pkt_hdr;



void parse_Wireshark(FILE* fp);

void parse_Pyshical(FILE* fp, uint32_t* caplen, uint8_t* datalink_type);
void parse_IEEE802(FILE* fp, uint32_t* caplen);
void parse_PHYIEEE(FILE* fp);
uint32_t getframelength(pkt_hdr chunck);
void print_time(pkt_hdr pheader);