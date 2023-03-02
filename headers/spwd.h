#ifndef _ELDYJ_SPWD_H_
#define _ELDYJ_SPWD_H_

#  ifndef _PWDS_H_
#  include"pwds.h"
#  endif /* !_PWDS_H_ */

#  ifndef _STRING_H
#  include <string.h>
#  endif /* _STRING_H */

size_t str_count_char(const char *str, const char ch) {
    size_t count = 0;
    while (*str) if (*str++ == ch) ++count;
    return count;
}

unsigned short starts_with(const char *str, const char *prefix) {
  size_t len = strlen(prefix);
  for (size_t i = 0; i < len; ++i) if (str[i] != prefix[i]) return 0;
  return 1;
}

char* spwd(void) {
  char* pwd = getenv("PWD");
  char* home = getenv("HOME");
  if (!pwd)
    return "ERR: PWD environment variable not set";

  if (!strcmp(pwd,home)) return "~";

  if (starts_with(pwd,home)) {
    pwd += strlen(getenv("HOME")) - 2;
    pwd[0] = '/';
    pwd[1] = '~';
    pwd[2] = '/';
  }

  char buf[str_count_char(pwd, '/')*3];
  char* buf_p = buf;
  
  while (*pwd) {
    if (*pwd == '/') {
      if (pwd[1] == '~') {
        ++pwd;
        *buf_p++ = '~';
        continue;
      }
      *buf_p++ = *pwd++;
      if (*pwd == '.') *buf_p++ = *pwd++;
      *buf_p++ = *pwd++;
      ++pwd;
    }

    if (*pwd) ++pwd;
  }

  *buf_p = '\0';
  return (char*) buf;
}

/*
char* spwde(void) {
  char* spwd_ = spwd();
  if (spwd_[0] == '~' && spwd_[1] == '\0') return spwd_;
  char* cwd_ = cwd() + 1;

  char result[strlen(spwd_) + strlen(cwd_)];
  char* beforespwd = (char*)result;
  char* afterspwd = beforespwd + strlen(spwd_);
  
  while(*spwd_)*beforespwd++ = *spwd_++;
  while(*cwd_)*afterspwd++  = *cwd_++;

  *afterspwd = 0;

  return (char*)result;
}
*/

#endif /* _ELDYJ_SPWD_H_ */
