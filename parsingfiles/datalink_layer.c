//2nd layer: Ethernet
#include "datalink_layer.h"


void parse_Datalink(FILE* fp, uint8_t datalink_type, uint8_t network_type[]){
    ethrnt_hdr eheader;
    fread(&eheader, sizeof(eheader), 1, fp);
    //fseek(fp, -14, 1);
    //print_MacAddress(eheader);


    /*
    uint16_t ethertype =eheader.type[0];
    ethertype <<= 8;
    ethertype += eheader.type[1];


    if(eheader.type[0] > 0x6)  // DIX 2.0
    {
        switch (1)
        {
        case 1:
            parse_ethernet(fp);
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
}


void print_MacAddress(ethrnt_hdr eheader){
    printf("Source Mac Address: ");
    for(int i = 0; i< 6; i++){
        printf("%d",eheader.src_mac);
        if(i != 5)
            printf(":");
        else
            printf("\n");
    }
    
    printf("Destination Mac Address: ");
    for(int j = 0; j< 6; j++){
        printf("%d",eheader.dst_mac);
        if(j != 5)
            printf(":");
        else
            printf("\n");
    }
}