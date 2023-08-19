#include "kernel/types.h"
#include "user/user.h"
#include "stddef.h"

void 
prime(int fd[]){
  char buf[36];
  read(fd[0],buf,36);
  for(int i=2;i<36;i++)
  {
    if(buf[i]=='1')
    {
      printf("prime %d\n", i);
      buf[i]='0';
      for(int j=i+1;j<36;j++)
      {
        if(j%i==0)
        {
          buf[j]='0';
        }
      }
      break;
    }
    if(i==35)
    {
        exit(0);
    }
  }
  int pid = fork();
  if(pid>0)
  {
    write(fd[1],buf,36);
  }
  if(pid==0)
  {
    prime(fd);
  }
}

int 
main(int argc, char argv[]){
  
  char buf[36];
  for(int i=2;i<36;i++)
  {
    buf[i]= '1';
  }
  int fd[2];
  pipe(fd);
  int pid = fork();
  if(pid>0)
  {
    write(fd[1],buf,36);
    wait(0);
  }

  if(pid==0)
  {
    prime(fd);
    wait(0);
  }
  exit(0);
}