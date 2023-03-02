#include<stdio.h>
#include"headers/spwd.h"
#include"headers/ansi.h"
#include"headers/module.h"

int main(int argc, char** argv) {
  char* pname = *argv++;
  char* sep = *argv++;
  char* lc = "-";

  for (unsigned short i = 2; i < argc; ++i)
    module(*argv++, &lc, sep);

  printf("%s%s\033[0m ",ansi_col(lc,'f'),sep);
  return 0;
}
