#include "myShell_12172133.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>
#define CMD_ARG 10
#define CMD_GRP 10
#define SIZE 15

void saveHistory();
void showHistory();
char historyBuf[150] = {0};
const char* prompt = "12172133_shell$";
char* cmdgrps[CMD_GRP];
char* cmdvector[CMD_ARG];
char  cmdline[SIZE];
bool back = false;
void fatal(char* str);
void cmdStart(char* cmdgrp);
int parsing(char* s, const char* delimiters, char** list, int MAX_LIST);
void zombie_handler(int signo);

pid_t pid;
int status;

int main(int argc, char** argv)
{
    int status;
    pid_t pid;
    sigset_t set;

    sigfillset(&set);
    sigdelset(&set, SIGCHLD);
    struct sigaction act;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_RESTART;
    act.sa_handler = zombie_handler;
    sigaction(SIGCHLD, &act, NULL);

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	    while (1) {
		fputs(prompt, stdout);
	    fgets(cmdline, SIZE, stdin);
		saveHistory();
        if ((strlen(cmdline) - 1) == 0) { continue; }
         cmdline[strlen(cmdline) - 1] = '\0';
	    for (int i = 0; i < strlen(cmdline); i++) {
		   if (cmdline[i] == '&') {
		      cmdline[i] = ' ';
	          back = true;
			}
	    else { back = false; }
	
		}
	 cmdStart(cmdline);
     printf("\n");
	}
   return 0;
 }

  void fatal(char* str)
   {
     perror(str);
     exit(1);
   }

 void zombie_handler(int signo) {
     pid_t spid;
     int sstatus;
     while ((spid = waitpid(-1, &sstatus, WNOHANG)) > 0);
}

 void cmdStart(char* cmdgrp)
  {
     int i = 0;
	 int count = 0;

	 parsing(cmdgrp, " \t", cmdvector, CMD_ARG);
	
   if (quit(cmdvector)) {
	   exit(EXIT_FAILURE);	
	}
	else if (help(cmdvector)){
	   return;
   }
	else if (!strcmp("history", cmdvector[0]))
   {
	   showHistory();
	   return;
   }
	
	
   pid = fork();
   if (pid == -1)
   {
	   perror("fork is failed");
	   exit(1);
   }
   else if (pid == 0)
   {
	   signal(SIGINT, SIG_DFL);
	   signal(SIGQUIT, SIG_DFL);
	   execvp(cmdvector[0], cmdvector);
	   fatal("exec error");
   }
   else
   {
	   if (back == true){
		   return;
	   }
		  

	   waitpid(pid, &status, WUNTRACED);
   } 
}
  

 int parsing(char* string, const char* delimiters, char** cmdvector, int MAX_LIST) {
	   int i = 0;
       int tokens = 0;
       char* newString = NULL;
	
	  if ((string == NULL) || (delimiters == NULL)) return -1;
	
	    newString = string + strspn(string, delimiters);     //delimiters skip
	   if ((cmdvector[tokens] = strtok(newString, delimiters)) == NULL)
	     return tokens;

	   tokens = 1;
    while (1) {
	       if ((cmdvector[tokens] = strtok(NULL, delimiters)) == NULL)
		          break;
	      if (tokens == (MAX_LIST - 1)) return -1;
	      tokens++;
	
	}
	    return tokens;

}

void saveHistory()
{
	for (int i = 134; i >= 0; i--)
	{
		historyBuf[i + 15] = historyBuf[i];
	}
	for (int i = 0; i < 15; i++)
	{
		historyBuf[i] = ' ';
		historyBuf[i] = cmdline[i];
	}
}

void showHistory()
{
	for (int i = 0; i < 150; i++)
	{
		if (i % 15 == 0)
		{
			printf("\n");
		}
		printf("%c", historyBuf[i]);
	}

}

