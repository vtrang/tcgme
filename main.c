#include<includes.h>

	//Looper
	int run = 1;
	//Declarations of a map as a young character matrix
	char map[100][100];
	int width = 0;
	int height = 0;
	//Input Space
	char userArg1[100];
	char userArg2[100];
	char userArg3[100];
	int userArg4[100];
	int userArg5[100];

	int main()
	{
	    printf("*You are using MapEditor. Type help at anytime for a command list.\n");
		while (run == 1){
			
			printf("\n*Usage: new | load | save | edit | print | help | quit\n");
			scanf("%s", userArg1);
			
			if(strcmp("new", userArg1)==0){
				
				printf("*Usage: \"<width> <height>\"\n");
				printf("*Back: \"0 0\"\n");
				scanf("%d %d", userArg4, userArg5);
				if(0 == *userArg4){
					//do nothing
				}
				else{
					printf("*Creating new %d x %d map...\n",*userArg4,*userArg5);
					width = *userArg4;
					height = *userArg5;
					//create map
					for(int i = 0; i < height; i++){
						for(int j = 0; j < width; j++){
							map[i][j] = '-';
						}
					}
					//print map
					print();
				}
			}
			
			if(strcmp("load",userArg1)==0){
				
				printf("*Usage: \"<file>\"\n");
				printf("*Back: \"cancel\"\n");

				scanf("%s", userArg1);
				
				if(strcmp("cancel", userArg1)==0){
					//do nothing
				}
				else {
					//load map from file

					FILE *file = fopen(userArg1, "r");
					if (!file){
						
						printf("error opening file\n");
					}
					else{
						printf("*Loading %s...\n", userArg1);
						char next;
						width = 0;
						height = 0;
						int count = 0;
						while((next = fgetc(file)) != EOF){
							count++;
							if(next == '\n'){
								height++;
								width = (count-height)/height;
							}
							else{
								if(width==0){
									map[height][count-1] = next;
								}
								else{
									map[height][(count % (width+1))-1] = next;
								}
							}
						}
					}					
					fclose(file);
					//print map
					print();
				}
			}
						
			if(strcmp("save",userArg1)==0){
				
				printf("*Usage: \"<file>\" (existing files will be overwritten)\n");
				printf("*Back: \"cancel\"\n");

				scanf("%s", userArg1);

				if(strcmp("cancel", userArg1)==0){
					//do nothing
				}
				else{
					//save map to file
					printf("*Saving %s\n", userArg1);
					FILE *file = fopen(userArg1, "w");
					
					for(int i = 0; i < height; i++){
						for(int j = 0; j < width; j++){
							fputc(map[i][j],file);
						}
						fputc('\n',file);
					}
					fclose(file);
				}
			}
			
			if(strcmp("edit",userArg1)==0){
				
				printf("*Usage:\n");
				printf("*      Insert a character at (x,y): \"<x> <y> <char>\"\n");
				printf("*      Replace row x with character: \"row <x> <char>\"\n");
				printf("*      Replace column y with character: \"column <y> <char>\"\n");
				printf("*      Insert character into all spaces: \"all <char>\"\n");
				printf("*      To delete, use \"delete\" in place of <char>\n");
				printf("*      Back: \"cancel\"\n");
				
				scanf("%s", userArg1);
				//printf("*You entered: %s\n", userArg1);
				if(strcmp("cancel", userArg1)==0){
					//do nothing
				}

				else if(strcmp("row", userArg1)==0){
					//row logic		
					scanf("%s %s", userArg1, userArg2);
					if (strcmp("delete", userArg2)==0){
						for(int i = 0; i < width; i++){
							map[atoi(userArg1)][i] = ' ';
						}
					}
					else{
						gamepiece g = getGamepiece(userArg2);
						if (g){*userArg2 = getTile(g);}

						for(int i = 0; i < width; i++){
							map[atoi(userArg1)][i] = *userArg2;
						}	
					}
					print();	
				}
				
				else if(strcmp("column", userArg1)==0){
					//column logic
					
					scanf("%s %s", userArg1, userArg2);
					if (strcmp("delete", userArg2)==0){
						for(int i = 0; i < height; i++){
							map[i][atoi(userArg1)] = ' ';
						}
					}
					else{
						gamepiece g = getGamepiece(userArg2);
						if (g){*userArg2 = getTile(g);}
						for(int i = 0; i < height; i++){
							map[i][atoi(userArg1)] = *userArg2;
						}	
					}
					print();

					
				}
				
				else if(strcmp("all", userArg1)==0){
					//all logic
					scanf("%s", userArg1);
					if(strcmp("delete", userArg1)==0){
						memset(map, 0, sizeof(map));
					}
					else{
						gamepiece g = getGamepiece(userArg1);
						if (g){*userArg1 = getTile(g);}
						for(int i = 0; i < height; i++){
							for(int j = 0; j < width; j++){
								map[i][j] = *userArg1;
							}
						}
					}
					print();
				}
				else{
					//cell logic
					scanf("%s %s", userArg2, userArg3);
					if (strcmp("delete", userArg3)==0){
						map[atoi(userArg2)][atoi(userArg1)] = ' ';
					}
					else{
						gamepiece g = getGamepiece(userArg3);
						if (g){*userArg3 = getTile(g);}
						map[atoi(userArg2)][atoi(userArg1)] = *userArg3;
					}
					
					print();
				}
			}
			
		
			if (strcmp("print",userArg1)==0){
				print();
			}
			
			if (strcmp("help",userArg1)==0){
				help();
			}
			
			if(strcmp("quit",userArg1)==0){
				run = 0;
			}
		}
		
		return 0;	
		
	}