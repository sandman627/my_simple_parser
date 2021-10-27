//4th layer: TCP, UDP, SCTP
#include <stdio.h>
#include <stdint.h>
#include "transport_layer.h"


uint8_t parse_Transport(FILE* fp, uint8_t protocolID){


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