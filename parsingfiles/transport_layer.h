//4th layer: TCP, UDP, SCTP
#include "bytecheck.h"

typedef struct TCP_header // 20 + @ bytes
{
    uint8_t srcPort[2], dstPort[2];
    uint8_t seqNum[4];
    uint8_t ackNum[4];
    uint8_t HLENReseved, tcpFlags, window[2];
    uint8_t checksum[2], urgent[2];
    // 5 optional
}tcp_hdr;


typedef struct TCP_Option__header
{

}tcpop__hdr;


typedef struct UDP_header // 8 bytes
{
    uint8_t srcPort[2], dstPort[2];
    uint8_t length[2], checksum[2];
}udp_hdr;

typedef struct ICMP_header // 8 bytes
{
    uint8_t type, code, checksum[2];
    uint8_t data[4];
}icmp_hdr;


void parse_Transport(FILE* fp, uint8_t protocolID, uint8_t* app_type);
void parse_TCP(FILE* fp);
void parse_UDP(FILE* fp);
void parse_ICMP(FILE* fp);
void print_TCP(tcp_hdr chunk);
void print_UDP(udp_hdr chunk);
void print_ICMP(icmp_hdr chunk);