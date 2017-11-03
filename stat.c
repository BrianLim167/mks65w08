#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

int main(){
char path[] = "stat.c";
  struct stat info;
  stat("stat.c",&info);
  size_t size = info.st_size;

  printf("Stats for %s\n",path);
  printf("========\n");

  printf("Size\n");
  printf("\t");
  if (size / (1024 * 1024 * 1024)){
    printf("%luGB ", size / (1024 * 1024 * 1024));
    size %= (1024 * 1024 * 1024);
  }
  if (size / (1024 * 1024)){
    printf("%luMB ", size / (1024 * 1024));
    size %= (1024 * 1024);
  }
  if (size / (1024)){
    printf("%luKB ", size / (1024));
    size %= (1024);
  }
  if (size){
    printf("%luB ", size);
  }
  printf("\n");
  printf("--------\n");

  printf("Permissions\n");
  printf("\t%o\n", info.st_mode % 01000);
  printf("--------\n");

  printf("Last time of access\n");
  printf("\t%s\n", ctime(&info.st_atime));
  printf("--------\n");


  return 0;
}
