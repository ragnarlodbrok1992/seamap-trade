#include "rand.h"

#include <Windows.h>
#include <Wincrypt.h>

#include <stdio.h>

uint64_t get_rand_uint64t() {
  uint64_t rand_int = 0;

  HCRYPTPROV hCryptProv = 0;

  if (!CryptAcquireContextW(&hCryptProv, 0, 0, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_SILENT)) {
    fprintf(stderr, "Error: secureRand: CryptAcquireContextW failed");
  }

  if (!CryptGenRandom(hCryptProv, sizeof(uint64_t), (unsigned char*) &rand_int)) {
    fprintf(stderr, "Error: secureRand: CryptGenRandom failed");
  }

  return rand_int;
}
