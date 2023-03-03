#ifndef _ANSI_H_
#  define _ANSI_H_

#  ifndef _STRING_H
#    include<strinh.h>
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

  res[3] = (!strcmp(name, "red"))    ?'1':
           (!strcmp(name, "green"))  ?'2':
           (!strcmp(name, "yellow")) ?'3':
           (!strcmp(name, "blue"))   ?'4':
           (!strcmp(name, "magenta")||
            !strcmp(name, "purple")) ?'5':
           (!strcmp(name, "cyan"))   ?'6':
           (!strcmp(name, "white"))  ?'7':
           (!strcmp(name, "black"))  ?'0':
           (mode == 'f')             ?'7':
                                      '0';
  return res;
}
#endif /* !_ANSI_H_ */
