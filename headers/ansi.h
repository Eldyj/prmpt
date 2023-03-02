#ifndef _ANSI_H_
#define _ANSI_H_

#  ifndef _STRING_H
#  include<strinh.h>
#  endif /* !_STRING_H */

char* ansi_col(char* name, char mode) {
  char* res = "\033[00m";

  switch (mode) {
    case 'f':
      res[2] = '3';
      break;
    case 'b':
      res[2] = '4';
      break;
  }

  if      (!strcmp(name, "red"))     res[3] = '1';
  else if (!strcmp(name, "green"))   res[3] = '2';
  else if (!strcmp(name, "yellow"))  res[3] = '3';
  else if (!strcmp(name, "blue"))    res[3] = '4';
  else if (!strcmp(name, "magenta")) res[3] = '5';
  else if (!strcmp(name, "purple"))  res[3] = '5';
  else if (!strcmp(name, "cyan"))    res[3] = '6';
  else if (!strcmp(name, "white"))   res[3] = '7';
  else if (!strcmp(name, "black"))   res[3] = '0';
  else if (mode == 'f')              res[3] = '7';
  else if (mode == 'b')              res[3] = '0';
  return res;
}
#endif /* !_ANSI_H_ */
