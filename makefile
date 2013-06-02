-std=c99
editor: main.c help.c print.c
	gcc -std=c99 -o editor main.c help.c print.c -I.