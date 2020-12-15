#include <sodium.h>
#include <stdio.h>
#include <string.h>

#define HASHSIZE crypto_generichash_BYTES
#define HEXLEN HASHSIZE * 2 + 1

int main(void)
{
	char s[1024];
	unsigned char hash[HASHSIZE];
	char hex[HEXLEN];
	crypto_generichash_state state;
	crypto_generichash_init(&state, NULL, 0, HASHSIZE);
	while (fgets(s, sizeof s, stdin)) {
		crypto_generichash_update(&state, (unsigned char *)s, strlen(s));
	}
	crypto_generichash_final(&state, hash, HASHSIZE);
	sodium_bin2hex(hex, HEXLEN, hash, sizeof hash);
	puts(hex);
	return 0;
}
