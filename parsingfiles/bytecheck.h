#ifndef BYTECHECK
#define BYTECHECK

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Connection_Node_buffer // segments of a connection
{
    struct Connection_Node_buffer* nextbuffer;
    struct Connection_Node_buffer* prevbuffer;
    uint8_t seqNum[4], ackNum[4];
    uint32_t payloadsize;    
}conNodeBuffer;

typedef struct Connection_Node // list for connections
{
    struct Connection_Node* prevnode; 
    struct Connection_Node* nextnode;
    int nodenum;
    uint8_t srcIP[4], dstIP[4];
    uint8_t srcPort[2], dstPort[2];
    uint8_t transport_protocol;
    
    uint32_t payloadSum;
    conNodeBuffer* segmentbuffer;
}conNode;

void bytehexprint(FILE* fp, int bytenum);
uint32_t fourbytearray(uint8_t array[4]);
uint32_t reversefourbytearray(uint8_t array[4]);
uint16_t twobytearray(uint8_t array[2]);
int CheckSumFunction(FILE* fp, int bytenum, uint8_t checksum[2]);

#endif