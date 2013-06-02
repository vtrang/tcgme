#include<includes.h>

int height;
int width;
char map[100][100];

void print(){
	//print map
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}


gamepiece getGamepiece(char * arg){
		if (strcmp("wall1", arg)==0){
			return wall1;
		}
		else if (strcmp("wall2", arg)==0){
			return wall2;
		}
		else if (strcmp("wall3", arg)==0){
			return wall3;
		}
		else if (strcmp("player", arg)==0){
			return player;
		}
		else if (strcmp("switch1", arg)==0){
			return switch1;
		}
		else if (strcmp("switch2", arg)==0){
			return switch2;
		}
		else if (strcmp("spikeExtended", arg)==0){
			return spikeExtended;
		}
		else if (strcmp("spikeRetracted", arg)==0){
			return spikeRetracted;
		}
		else if (strcmp("doorButton1", arg)==0){
			return doorButton1;
		}
		else if (strcmp("doorButton2", arg)==0){
			return doorButton2;
		}
		else if (strcmp("doorClosed", arg)==0){
			return doorClosed;
		}
		else if (strcmp("doorOpened", arg)==0){
			return doorOpened;
		}
		else{
			return 0;
		}
	}
	char getTile(gamepiece g)
	{
	    switch( g ) {
		case wall1:
			return '|';
	    case wall2:
	        return '-';
		case wall3:
			return '+';
		case player:
			return 'P';
		case switch1:
			return '/';
		case switch2:
			return '\\';
		case spikeExtended:
			return '^';
		case spikeRetracted:
			return '*';
		case doorButton1:
			return ':';
		case doorButton2:
			return '.';
		case doorClosed:
			return 'I';
		case doorOpened:
			return 'D';
	    }
	}