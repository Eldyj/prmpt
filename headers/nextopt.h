#ifndef _NEXTOPT_H_
#  define _NEXTOPT_H_

// WARNING: this thing modifies str
short next_opt(char** str, char** buf, char sep) {
  char* str_c = *str;
  while (*str_c != sep) {
    if (!*str_c) {
      *buf = *str;
      return 1;
    }
    ++str_c;
  }
  *str_c = 0;
  *buf = *str;
  *str = str_c+1;
  //printf(*str);
  //printf(*buf);
  return 0;
}
#endif /* !_NEXTOPT_H_ */
