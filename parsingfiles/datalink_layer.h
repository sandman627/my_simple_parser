//2nd layer: Ethernet
#include "bytecheck.h"

typedef struct Ethernet_header // 14 bytes
{
    uint8_t dst_mac[6];
    uint8_t src_mac[6];
    uint8_t type[2];
}ethrnt_hdr;


void parse_Datalink(FILE* fp, uint8_t datalink_type, uint8_t network_type[2]);
void parse_ethernet(FILE* fp);
void print_ethernet(ethrnt_hdr eheader);