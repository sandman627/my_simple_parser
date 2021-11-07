#include "bytecheck.h"


extern uint8_t sourceIP[4], destinationIP[4];
extern uint8_t sourcePort[2], destinationPort[2];
extern uint8_t TransProtocol;

void bytehexprint(FILE* fp, int bytenum){
    uint8_t temp;
    for(int i = 0; i < bytenum; i++){
        fread(&temp, sizeof(temp), 1, fp);
        printf("%02x ", temp);

        if (i % 16 == 15){
            printf("\n");
        }else if (i % 8 == 7){
            printf("  ");
        }
    }
    printf("\n");
    fseek(fp, -bytenum, 1);
}

uint32_t fourbytearray(uint8_t array[4]){
    uint32_t result = 0;
    for(int i = 0; i < 4; i++){
        result <<= 8;
        result += array[3-i];
    }
    return result;
}

uint16_t twobytearray(uint8_t array[2]){
    uint16_t result = array[0];
    result <<= 8;
    result += array[1];
    return result;
}

/*

void appendNode(conNode* prevnode, int dataSize){   // when new tuple5 comes in
    conNode* newNode = malloc(sizeof(conNode));
    newNode->prevnode = prevnode;
    newNode->nextnode = NULL;
    newNode->nodenum = prevnode->nodenum + 1;

    memcpy(newNode->srcIP, sourceIP, 32);
    memcpy(newNode->srcPort, sourcePort, 32);
    memcpy(newNode->dstIP, destinationIP, 32);
    memcpy(newNode->dstPort, destinationPort, 32);
    newNode->transport_protocol = TransProtocol;

    conNode* newBuffer = malloc(sizeof(conNodeBuffer));
    newNode->segmentbuffer = newBuffer;
    newNode->segmentbuffer->prevbuffer = newNode;
    newNode->segmentbuffer->nextbuffer = NULL;

    //memcpy(newNode->firstsegment->seqNum, , 32);
    //memcpy(newNode->firstsegment->seqNum, , 32);
    newNode->segmentbuffer->payloadsize = dataSize;
    
}


void connectionRecord(conNode* head){

}


void freeLinkedList(conNode* firstNode){
    if(firstNode->nextnode != NULL)
        freeLinkedList(firstNode->nextnode);

    free(firstNode);
}

*/