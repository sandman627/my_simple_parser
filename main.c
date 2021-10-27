#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "parsing.h"


int main()
{
    printf("\nRunning Network Assignment Code\n");
    FILE *fp = fopen("datafiles/packet_hw2.pcap","rb");
    
    int packet_num = 0;
    printf("Enter the number of packets to read: ");
    scanf("%d", &packet_num);

    if(fp == NULL)
    {
        printf("\nNo such file!!!!\n");
        exit(1);
    }
    else{
        int i = 0;
        while (fp != NULL && packet_num != i)
        {
            i++;
            hexprint(fp);
        }
    }
 
    fclose(fp);
    printf("program done!!!\n");
	return 0;
}