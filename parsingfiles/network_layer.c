//3rd layer: IP, ICMP, IGMP
#include "network_layer.h"


void parse_Network(FILE* fp, uint8_t network_type[], uint8_t* transport_type){
    uint16_t type = network_type[0];
    type <<= 8;
    type += network_type[1];

    switch (type)
    {
    case 0x0800: // IPv4
    parse_IPv4(fp);
        break;
    
    case 0x86dd: // IPv6
    parse_IPv6(fp);
        break;
    
    case 0x0806: // ARP
    parse_ARP(fp);
        break;

    default:
    printf("Ethernet type error. No match found!\n");
    exit(1);
        break;
    }  
}

void parse_IPv4(FILE* fp){

}

void parse_IPv6(FILE* fp){
    IPv6_hdr chunk;
    fread(&chunk, sizeof(chunk), 1, fp);

    int8_t headernum= chunk.nextheader;
    switch((uint8_t)headernum){// do not use break since there maybe more than one extension header
        case 0: // hop by hop
        case 43: // routing header
        case 44: // fragment header
        case 51: // authentication 
        case 50: // encapsulating
        case 60: // destination opteions header
        case 135: // upper-layer header
        case 139: // host identity
        case 140: // shim6
        case 253: // use for experimentation and testing
        case 254: // use for experimentation and testing
        default :
            printf("Now we are at TCP");
    }
}

void parse_ARP(FILE* fp){

}

/*
void print_hex_IPv4(IPv4_hdr chunk){
    printf("\nIPv4 HEADER\n");
    printf("%02x", chunk.verhlen);
    printf("%02x", chunk.DS);
    printf("%04x\n", chunk.TotalLen);

    printf("%04x", chunk.identification);
    printf("%04x\n", chunk.flag_and_offset);

    printf("%02x", chunk.TTL);
    printf("%02x", chunk.protocol);
    printf("%04x\n", chunk.checksum);
    
    printf("%08x\n", chunk.src_IP);
    printf("%08x\n", chunk.dst_IP);
}

void parse_IPv4(IPv4_hdr chunk){
    printf("%02x", chunk.verhlen);
    printf("%02x", chunk.DS);
    printf("%04x\n", chunk.TotalLen);

    printf("%04x", chunk.identification);
    printf("%04x\n", chunk.flag_and_offset);

    printf("%02x", chunk.TTL);
    printf("%02x", chunk.protocol);
    printf("%04x\n", chunk.checksum);
    
    printf("%08x\n", chunk.src_IP);
    printf("%08x\n", chunk.dst_IP);
}


void print_hex_IPv6(IPv6_hdr chunk){
    printf("\nIPv6 HEADER\n");

}

*/