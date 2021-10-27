//4th layer: TCP, UDP, SCTP
#include "transport_layer.h"


void parse_Transport(FILE* fp, uint8_t protocolID, uint8_t* app_type){

    switch (protocolID)
    {
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

}

void parse_UDP(FILE* fp){

}