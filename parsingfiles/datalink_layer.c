//2nd layer: Ethernet
#include "datalink_layer.h"


extern int caplength;  // includes 16 bit pkt header but not file header (ethernet header + frame)
extern int framesize;  // layer 2 data, size without ethernet header (IP header + packet)


void parse_Datalink(FILE* fp, uint8_t datalink_type, uint8_t network_type[2]){
    ethrnt_hdr eheader;
    fread(&eheader, sizeof(eheader), 1, fp);
    print_ethernet(eheader);

    network_type[0] = eheader.type[0];
    network_type[1] = eheader.type[1];

    /*
    uint16_t ethertype = twobytearray(eheader.type);

    if(ethertype > 0x600)  // DIX 2.0
    {
        switch (1)
        {
        case 1:
            //parse_ethernet(fp);
            break;
        
        default:
            break;
        }
    }else{//IEEE SNAP or SAP
        
    }
    */
}

void parse_ethernet(FILE* fp){
    ethrnt_hdr eheader;
    fread(&eheader, sizeof(eheader), 1, fp);
    framesize = caplength - 14;
    print_ethernet(eheader);
}


void print_ethernet(ethrnt_hdr eheader){
    printf("Source Mac Address: ");
    for(int i = 0; i< 6; i++){
        printf("%02x",eheader.src_mac[i]);
        if(i != 5)
            printf(":");
        else
            printf("\n");
    }
    
    printf("Destination Mac Address: ");
    for(int j = 0; j< 6; j++){
        printf("%02x",eheader.dst_mac[j]);
        if(j != 5)
            printf(":");
        else
            printf("\n");
    }
}