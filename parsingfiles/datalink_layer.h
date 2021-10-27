//2nd layer: Ethernet
#include <stdint.h>

typedef struct Ethernet_header // 14 bytes
{
    uint8_t dst_mac[6];
    uint8_t src_mac[6];
    uint8_t type[2];
}ethrnt_hdr;


uint8_t* parse_Datalink(FILE* fp, uint8_t phy_type);
void parse_ethernet(FILE* fp);