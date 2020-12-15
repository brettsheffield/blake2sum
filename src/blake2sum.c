#include <errno.h>
#include <sodium.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define HASHSIZE crypto_generichash_BYTES
#define HEXLEN HASHSIZE * 2 + 1

int main(void)
{
	unsigned char hash[HASHSIZE];
	char hex[HEXLEN];
	char *s;
	size_t byt;
	int pagesz;
	pagesz = getpagesize();
	s = malloc(pagesz);
	if (!s) return ENOMEM;
	crypto_generichash_state state;
	crypto_generichash_init(&state, NULL, 0, HASHSIZE);
	while ((byt = fread(s, 1, pagesz, stdin))) {
		crypto_generichash_update(&state, (unsigned char *)s, byt);
	}
	crypto_generichash_final(&state, hash, HASHSIZE);
	sodium_bin2hex(hex, HEXLEN, hash, sizeof hash);
	puts(hex);
	free(s);
	return 0;
}
