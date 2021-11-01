//4th layer: TCP, UDP, SCTP
#include "transport_layer.h"


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
    print_TCP(tcpheader);
}

void parse_UDP(FILE* fp){
    udp_hdr udpheader;
    fread(&udpheader, sizeof(udpheader), 1, fp);
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

    printf("Header Length: %d\n", chunk.HLENReseved / 16);
    printf("Reserved: %d\n", (chunk.HLENReseved % 16)<<4 + chunk.tcpFlags/64);
    printf("Flags(URG, ACK, PSH, RST, SYN, FIN): %x\n", 0x3f & chunk.tcpFlags);
    printf("Window Size: %d\n", twobytearray(chunk.window));

    printf("Checksum: %04x\n", twobytearray(chunk.checksum));
    printf("Urgent: %04x\n", twobytearray(chunk.urgent));
}

void print_UDP(udp_hdr chunk){
    printf("\nUDP HEADER\n");
    printf("Source Port: %d\n", twobytearray(chunk.srcPort));
    printf("Destination Port: %d\n", twobytearray(chunk.dstPort));

    printf("Length: %d\n", twobytearray(chunk.length));
    printf("Checksum: %04x\n", twobytearray(chunk.checksum));
}

void print_ICMP(icmp_hdr chunk){
    printf("\nICMP HEADER\n");
    printf("Type: %d\n", chunk.type);
    printf("Code: %d\n", chunk.code);
    printf("Checksum: %x\n", twobytearray(chunk.checksum));

    printf("Data: %08x\n", fourbytearray(chunk.data));
}