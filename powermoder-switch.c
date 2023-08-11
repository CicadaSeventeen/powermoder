#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int printhelp( char *cmd ){
    printf("switch of powermoder\n");
    printf("usage:  %s  <profile name>\n",cmd);
    printf("<profile name> can be found under \'/etc/powermoder/\'\n");
}

int main( int argc , char *argv[] ){
    char cmdline[100];
    if ( argc != 2 ){
        printhelp(argv[0]);
        exit(-1);
    }
    strcpy(cmdline,"/etc/powermoder/");
    strcat(cmdline,argv[1]);
    if ( access(cmdline,4) == 0 ){
        strcpy(cmdline,"PATH=$PATH:/usr/local/sbin:/usr/local/bin:/sbin:/usr/sbin powermoder profile ");
        strcat(cmdline,argv[1]);
        setuid(0);
        system(cmdline);
        exit(0);
    }
    else{
        printf("profile not found\n\n");
        printhelp(argv[0]);
        exit(-1);
    }
}
