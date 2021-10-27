//4th layer: TCP, UDP, SCTP
#include "bytecheck.h"

typedef struct TCP_header // 20 + @ bytes
{
    uint8_t srcPort[2], dstPort[2];
    uint8_t seqNum[4];
    uint8_t ackNum[4];
    uint8_t offsetReseved, tcpFlags, window[2];
    uint8_t checksum[2], urgent[2];
    // 5 optional
}tcp_hdr;

typedef struct UDP_header // 8 bytes
{
    uint8_t srcPort[2], dstPort[2];
    uint8_t length[2], checksum[2];
}udp_hdr;


void parse_Transport(FILE* fp, uint8_t protocolID, uint8_t* app_type);
void parse_TCP(FILE* fp);
void parse_UDP(FILE* fp);