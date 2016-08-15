
struct dgt_t{
  int val1;
  int val2;
} obj;


char *tgl_strndup (const char *s, size_t n);

static inline void out_of_memory (void) {
  fprintf (stderr, "Out of memory\n");
  exit (1);
}

static inline void ensure_ptr (void *p) {
  if (p == NULL) {
    out_of_memory ();
  }
}
