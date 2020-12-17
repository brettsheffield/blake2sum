#include <errno.h>
#include <sodium.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define HASHSIZE crypto_generichash_BYTES
#define HEXLEN HASHSIZE * 2 + 1

int main(int argc, char *argv[])
{
	unsigned char hash[HASHSIZE];
	char hex[HEXLEN];
	char *s;
	size_t byt;
	int pagesz;
	crypto_generichash_state state;
	if (argc == 1) {
		pagesz = getpagesize();
		s = malloc(pagesz);
		if (!s) return ENOMEM;
	}
	crypto_generichash_init(&state, NULL, 0, HASHSIZE);
	if (argc == 1) {
		while ((byt = fread(s, 1, pagesz, stdin))) {
			crypto_generichash_update(&state, (unsigned char *)s, byt);
		}
	}
	else if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			crypto_generichash_update(&state, (unsigned char *)argv[i], strlen(argv[i]));
		}
	}
	crypto_generichash_final(&state, hash, HASHSIZE);
	sodium_bin2hex(hex, HEXLEN, hash, sizeof hash);
	puts(hex);
	if (argc == 1) free(s);
	return ferror(stdin);
}
