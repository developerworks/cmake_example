#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strndup.h"

int main(int argc, char* argv[])
{
    const char *p = "https://segmentfault.com/u/developerworks"; // 栈上的内存
    char *q; // 堆上的内存?
    q = tgl_strndup(p, 24);
    printf("p=0x%x, v=%s\n", p, p);
    printf("q=0x%x, v=%s\n", q, q);
    printf("struct address: 0x%x\n", &obj);
    printf("length of p: %d\n", strlen(p));
    memset (q, 0, sizeof(p));
    free(q);
    return 0;
}

char *tgl_strndup (const char *s, size_t n) {
  size_t l = 0;
  for (l = 0; l < n && s[l]; l++) { }
  char *p = malloc (n + 1);
  ensure_ptr (p);
  memcpy (p, s, l);
  p[l] = 0; // 字符串终止符号\0
  return p;
}

