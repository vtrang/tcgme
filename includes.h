#include<stdio.h>
#include<string.h> 
extern int height;
extern int width;
typedef enum {
		wall1 = 1,
		wall2,
		wall3, 
		player, 
		switch1, 
		switch2, 
		spikeExtended, 
		spikeRetracted, 
		doorButton1,
		doorButton2,
		doorClosed,
		doorOpened,
	} gamepiece;

void help();
void print();