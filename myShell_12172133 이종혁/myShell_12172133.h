#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool quit(char* cmdvector[])
 {
	 if (!strcmp("quit", cmdvector[0])){
		printf("\nmy Shell developed by JonghyeokLee(12172133)\n");
		 return true;}
	 else
		 return false;
 }

 bool help(char* cmdvector[])
 {
	 if (!strcmp("help", cmdvector[0]))
	 {	
		 printf("\n\n12172133_shell$ help\nDescription\n\nmyShell is simple version of shell, you can try normal commands of shell by exec function here!, here's a few description of commands. you may also use other commands you know\n\n");
		 printf("-ls\n	show the information of files in where you are located\n");
		 printf("-ls -l\n	show the details of files in where you are located\n");
		 printf("-ls -al\n	show the information of hidden files\n\n");
		 printf("empty space is needed to use background operation. ex) ls &\n\n");
		 printf("alert! -cd is not availble due to the limitation of exec\n\n");
		 return true;
	 }
	 else
		 return false;

 }
