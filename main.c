#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include "parsingfiles/pyshical_layer.h"
#include "parsingfiles/datalink_layer.h"
#include "parsingfiles/network_layer.h"
#include "parsingfiles/transport_layer.h"

//gcc main.c parsingfiles/bytecheck.c parsingfiles/pyshical_layer.c parsingfiles/datalink_layer.c parsingfiles/network_layer.c parsingfiles/transport_layer.c -o test

int caplength = 0;  // includes 16 bit pkt header but not file header (ethernet header + frame)
int framesize = 0;  // layer 2 data, size without ethernet header (IP header + packet)
int packetsize = 0;  // layer 3 data, size without IP header (TCP header + segment)
int segmentsize = 0;  // layer 4 data, size without tcp or udp header (segment)
int maxpayload = 0;


uint8_t sourceIP[4], destinationIP[4];
uint8_t sourcePort[2], destinationPort[2];
uint8_t TransProtocol;


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

    parse_Wireshark(fp);

    int i = 0;
    while (fp != NULL && packet_num != i){
            i++;
            printf("\n\n    Frame number: %d\n", i);
            Parsing(fp);
    }
    printf("\nMax Payload: %d\n", maxpayload);
    
    fclose(fp);
    printf("program done!!!\n");
	return 0;
}


void Parsing(FILE* fp){
    int cur_position = ftell(fp);  // save the start point of the frame 
    uint32_t totalpacketlen;  // length of the total length including pkt header
    uint8_t datalink_type; // just in case...
    uint8_t network_type[2]; // protocol number for datalink layer (2 bytes)
    uint8_t transport_type = 0; // protocol number for network layer
    uint8_t app_type; // protocol number for 
    
    printf("###############################################\n");

    parse_Pyshical(fp, &totalpacketlen, &datalink_type); //not just next layer type, also return length of frame
    parse_Datalink(fp, datalink_type, network_type);
    parse_Network(fp, network_type, &transport_type);
    parse_Transport(fp, transport_type, &app_type);

    printf("\nCap Length: %d\n", caplength);
    printf("Frame Size: %d\n", framesize);
    printf("Packet Size: %d\n", packetsize);
    printf("Segment Size: %d\n", segmentsize);

    if(segmentsize > maxpayload)
        maxpayload = segmentsize;

    caplength, framesize, packetsize, segmentsize = 0;

    fseek(fp, cur_position, SEEK_SET);
    fseek(fp, totalpacketlen, 1);// after reading all the wanted data, change pointer to next packet
}