//3rd layer: IP, ICMP, IGMP
#include "bytecheck.h"

typedef struct IPv4_header // 20 + @ bytes
{
    uint8_t verhlen, DS, TotalLen[2];
    uint8_t identification[2], flag_and_offset[2];
    uint8_t TTL, protocol, checksum[2];
    uint8_t src_IP[4];
    uint8_t dst_IP[4];
    //5 option
}IPv4_hdr;

typedef struct IPv6_header // 40 bytes
{
    uint8_t first4bytes[4]; // version(4 bits), traffic class(8 bits), FlowLabel(20 bits)
    uint8_t payloadlength[2], nextheader, hoplimit;
    uint8_t srcAdd[16]; // 2 ~5
    uint8_t dstAdd[16]; // 6 ~9
}IPv6_hdr;


void parse_Network(FILE* fp, uint8_t network_type[], uint8_t* transport_type);
void parse_IPv4(FILE* fp, uint8_t* transport_type);
void parse_IPv6(FILE* fp);
void parse_ARP(FILE* fp);

void print_IPv4(IPv4_hdr chunk);
void print_IPv6(IPv6_hdr chunk);