//2nd layer: Ethernet
#include "datalink_layer.h"


void parse_Datalink(FILE* fp, uint8_t datalink_type, uint8_t network_type[]){

    switch (1)
    {
    case 1:
        parse_ethernet(fp);
        break;
    
    default:
        break;
    }
}

void parse_ethernet(FILE* fp){
    ethrnt_hdr eheader;
    fread(&eheader, sizeof(eheader), 1, fp);
    

}