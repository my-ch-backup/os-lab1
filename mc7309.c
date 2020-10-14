#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    char input[50];
    printf("lab1>");
    scanf("%s", input);
    printf("Parent Process%d\n", getpid());
   
    //if(strcmp(input, "printid") == 0){
       
   
    char *homedir = getenv("HOME"); //pull environment variable HOME
    char *argv[] = { "/bin/ls","-l", homedir, NULL }; //equivalent to /bin/ls -l $HOME
    char *envp[] = {  NULL };
    int child_status;
    if (fork() == 0 && homedir != NULL) { //if process is a child and homedir is not null
        execve(argv[0], argv, envp); //execute /bin/ls -l $HOME
        exit(0);
    }
    wait(&child_status); //parent process suspends until child terminates
    return 0;
}
