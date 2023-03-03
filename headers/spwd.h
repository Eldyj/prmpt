#ifndef _SPWD_H_
#  define _SPWD_H_

#  ifndef _PWDS_H_
#    include"pwds.h"
#  endif /* !_PWDS_H_ */

#  ifndef _STRING_H_
#    include"string.h"
#  endif /* !_STRING_H_ */

char* spwd(void) {
  char* pwd = getenv("PWD");
  char* home = getenv("HOME");
  if (!pwd) return "ERR: PWD environment variable not set";

  if (!strcmp(pwd,home)) return "~";

  if (starts_with(pwd,home)) {
    pwd += strlen(getenv("HOME")) - 1;
    pwd[0] = '~';
    pwd[1] = '/';
  }

  char buf[str_count_char(pwd, '/')*3];
  char* buf_ptr = buf;
  char* buf_p = buf;
  char* tmp;

  while(!next_opt(&pwd,&tmp,'/')) {
    if (!*tmp) continue;
    if (*tmp != '~') *buf_p++ = '/';
    *buf_p++ = *tmp;
    if (*tmp == '.') *buf_p++ = tmp[1];
  }

  *buf_p++ = '/';
  *buf_p++ = *tmp;
  if (*tmp == '.') *buf_p++ = tmp[1];

  *buf_p++ = 0;
  return buf_ptr;
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

#endif /* _SPWD_H_ */
