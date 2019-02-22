#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static int append = 0;
static int interrupt=0;

int  parse(int argc, char *argv[]){
  char c;
  while((c=getopt(argc,argv, "aip")) != -1){
    switch (c) {
      case 'a':
        append=1;
        break;
      case 'i':
        interrupt=1;
      default:
        abort();
        break;
    }
  }
  return 0;
}

int main(int argc, char *argv[]){
  char buf[100];
  size_t len;
  char *file_mode;
  int i;
  parse(argc,argv);

  if(append==1){
    file_mode="a";
  }
  else{
    file_mode="w";
  }
  int pop = optind;
  FILE *fileyboi = fopen(argv[pop],file_mode);
  while (fgets(buf,99,stdin)) {
    fprintf(stdout, "%s",buf);
    fprintf(fileyboi, "%s",buf);
  }
  fclose(fileyboi);
}
//A lot of what slowed me down was that I could not think of a good starting place. I was also very stuck because i was using fscanf instead of fgets
//In the future I may do a lot more research at the start of the implementation to give myself and better starting place
//The proffessional code has a lot of error checking that I do not employ in my code. It also only uses one large function.
//Another distinction is that its switch statement has two other cases that I did not account for.
