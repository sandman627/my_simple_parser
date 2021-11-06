//4th layer: TCP, UDP, SCTP
#include "transport_layer.h"


extern int packetsize;  // layer 3 data, size without IP header (TCP header + segment)
extern int segmentsize;  // layer 4 data, size without tcp or udp header (segment)


void parse_Transport(FILE* fp, uint8_t protocolID, uint8_t* app_type){

    switch (protocolID)
    {
    case 1:
    parse_ICMP(fp);
        break;

    case 6:
    parse_TCP(fp);
        break;
    
    case 17:
    parse_UDP(fp);
        break;

    default:
        break;
    }
}

void parse_TCP(FILE* fp){
    tcp_hdr tcpheader;
    fread(&tcpheader, sizeof(tcpheader), 1, fp);
    segmentsize = packetsize - (tcpheader.HLENReseved / 16) *4;  // hlen /16 *4
    print_TCP(tcpheader);
}

void parse_UDP(FILE* fp){
    udp_hdr udpheader;
    fread(&udpheader, sizeof(udpheader), 1, fp);
    segmentsize = packetsize - 8;  // hlen /16 *4
    print_UDP(udpheader);
}

void parse_ICMP(FILE* fp){  // ICMP is in fact a network protocol, but for convenience... 
    icmp_hdr icmpheader;
    fread(&icmpheader, sizeof(icmpheader), 1, fp);
    print_ICMP(icmpheader);
}


void print_TCP(tcp_hdr chunk){
    printf("\nTCP HEADER\n");
    printf("Source Port: %d\n", twobytearray(chunk.srcPort));
    printf("Destination Port: %d\n", twobytearray(chunk.dstPort));
    printf("Sequence Number: %d\n", fourbytearray(chunk.seqNum));
    printf("Acknowledge Number: %d\n", fourbytearray(chunk.ackNum));

    printf("Header Length: %d bytes\n", chunk.HLENReseved / 4);
    printf("Reserved: %d\n", (chunk.HLENReseved % 16)<<4 + chunk.tcpFlags/64);

    uint32_t flags = chunk.tcpFlags % 64;
    printf("Flags URG: %s\n", 0b100000 & flags ? "true" : "false");
    printf("Flags ACK: %s\n", 0b10000 & flags ? "true" : "false");
    printf("Flags PSH: %s\n", 0b1000 & flags ? "true" : "false");
    printf("Flags RST: %s\n", 0b100 & flags ? "true" : "false");
    printf("Flags SYN: %s\n", 0b10 & flags ? "true" : "false");
    printf("Flags FIN: %s\n", 0b1 & flags ? "true" : "false");
    printf("Window Size: %d\n", twobytearray(chunk.window));

    printf("Checksum: %04x\n", twobytearray(chunk.checksum));
    printf("Urgent: %04x\n", twobytearray(chunk.urgent));

    printf("TCP Payload, Segment Size: %d\n", packetsize - chunk.HLENReseved / 16);
}

void print_UDP(udp_hdr chunk){
    printf("\nUDP HEADER\n");
    printf("Source Port: %d\n", twobytearray(chunk.srcPort));
    printf("Destination Port: %d\n", twobytearray(chunk.dstPort));

    printf("Length: %d\n", twobytearray(chunk.length));
    printf("Checksum: %04x\n", twobytearray(chunk.checksum));

    printf("UDP Payload Size: %d\n", twobytearray(chunk.length) - 8);
}

void print_ICMP(icmp_hdr chunk){
    printf("\nICMP HEADER\n");
    printf("Type: %d\n", chunk.type);
    printf("Code: %d\n", chunk.code);
    printf("Checksum: %x\n", twobytearray(chunk.checksum));

    printf("Data: %08x\n", fourbytearray(chunk.data));
}