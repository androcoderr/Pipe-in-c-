#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
     FILE *ls_output;
    char buffer[128];
    ls_output=popen("ls","r");
    if(ls_output==NULL){
          perror("popen.");
          exit(EXIT_FAILURE);
    }
   printf("content of the current directory :\n");
   while(fgets(buffer,sizeof(buffer),ls_output)!=NULL)
   {
      printf("%s",buffer);
   }
   if(pclose(ls_output) == -1){
      perror("pclose..");
      exit(EXIT?EXIT_FAILURE);
   }
    return 0;
}