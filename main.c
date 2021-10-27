#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>
#include "parsingfiles/pyshical_layer.h"
#include "parsingfiles/datalink_layer.h"
#include "parsingfiles/network_layer.h"
#include "parsingfiles/transport_layer.h"


void Parsing(FILE* fp);

int main()
{
    printf("\nRunning Network Assignment Code\n");
    FILE *fp = fopen("datafiles/packet_hw2.pcap","rb");
    if(fp == NULL){
        printf("\nNo data file!!!!\n");
        exit(1);
    }

    int packet_num = 0;
    printf("Enter the number of packets to read: ");
    scanf("%d", &packet_num);

    int i = 0;
    while (fp != NULL && packet_num != i){
            i++;
            // parsing code
    }
    
    fclose(fp);
    printf("program done!!!\n");
	return 0;
}


void Parsing(FILE* fp){
    FILE* checkpoint = fp;

    uint32_t caplen;
    uint8_t datalink_type; // just in case...
    uint8_t network_type[2]; // protocol number for datalink layer (2 bytes)
    uint8_t transport_type; // protocol number for network layer
    uint8_t app_type; // protocol number for 
    
    parse_Pyshical(fp, &caplen, &datalink_type); //not just next layer type, also return length of frame
    //parse_Datalink(fp, datalink_type, network_type);
    //parse_Network(fp, network_type, &transport_type);
    //parse_Transport(fp, transport_type, &app_type);

    fseek(checkpoint, caplen + 40, 1);
    printf("caplen: %d\n", caplen);
    fp = checkpoint; // after reading all the wanted data, change pointer to next packet
}