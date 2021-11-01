//3rd layer: IP, ICMP, IGMP
#include "network_layer.h"


void parse_Network(FILE* fp, uint8_t network_type[], uint8_t* transport_type){
    uint16_t type = twobytearray(network_type);
    printf("Ethernet type: 0x%04x\n", type);
    switch (type)
    {
    case 0x0800: // IPv4
    parse_IPv4(fp, transport_type);
        break;
    
    case 0x86dd: // IPv6
    parse_IPv6(fp);
        break;
    
    case 0x0806: // ARP
    parse_ARP(fp);
        break;

    default:
    printf("Ethernet type error. No.0x%04x not found!\n", type);
        break;
    }  
}

void parse_IPv4(FILE* fp, uint8_t* transport_type){
    IPv4_hdr chunk;
    fread(&chunk, sizeof(chunk), 1, fp);
    *transport_type = chunk.protocol;
    print_IPv4(chunk);
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


void print_IPv4(IPv4_hdr chunk){
    printf("\nIPv4 HEADER\n");
    printf("VER: %d\n", chunk.verhlen / 16);
    printf("HLEN: %d\n", chunk.verhlen % 16);

    printf("Total length: %d\n", twobytearray(chunk.TotalLen));
    printf("Identification: %04x\n", twobytearray(chunk.identification));

    printf("Time to Live: %d\n", chunk.TTL);
    printf("Protocol: %d\n", chunk.protocol);

    printf("Source IP Address: ");
    for(int i = 0; i< 4; i++){
        printf("%d",chunk.src_IP[i]);
        if(i != 3)
            printf(".");
        else
            printf("\n");
    }
    printf("Destination IP Address: ");
    for(int j = 0; j< 4; j++){
        printf("%d",chunk.dst_IP[j]);
        if(j != 3)
            printf(".");
        else
            printf("\n");
    }
}

void print_IPv6(IPv6_hdr chunk){
    printf("\nIPv6 HEADER\n");

}