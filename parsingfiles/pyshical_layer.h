//1st layer: pyshical address
#include <stdint.h>

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


uint8_t parse_Pyshical(FILE* fp);
void parse_Wireshark(FILE* fp);
void parse_PHYIEEE(FILE* fp);
uint32_t framelength(pkt_hdr chunck);