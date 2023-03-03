#ifndef _STRING_H_
#  define _STRING_H_

unsigned long strlen(const char* str) {
  char* str_p = (char*)str;
  while(*str_p++);
  return str_p - str - 1;
}

unsigned short strcmp(const char* str1, const char* str2) {
  if (str1 == str2) return 0;
  char* s1 = (char*)str1;
  char* s2 = (char*)str2;

  while (*s1 || *s2) if (*s1++ != *s2++) return 1;
  return 0;
}

unsigned long str_count_char(const char *str, const char ch) {
  size_t count = 0;
  while (*str) if (*str++ == ch) ++count;
  return count;
}

unsigned short starts_with(const char *str, const char *prefix) {
  size_t len = strlen(prefix);
  for (size_t i = 0; i < len; ++i) if (str[i] != prefix[i]) return 0;
  return 1;
}

#endif /* !_STRING_H_ */
