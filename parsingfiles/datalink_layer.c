//2nd layer: Ethernet
#include <stdio.h>
#include <stdint.h>
#include "datalink_layer.h"


uint8_t* parse_Datalink(FILE* fp, uint8_t phy_type){
    uint8_t network_type[2];

    switch (1)
    {
    case 1:
        parse_ethernet(fp);
        break;
    
    default:
        break;
    }

    return network_type;
}

void parse_ethernet(FILE* fp){
    ethrnt_hdr eheader;
    fread(&eheader, sizeof(eheader), 1, fp);

    
    
}