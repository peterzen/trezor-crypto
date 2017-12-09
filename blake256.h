#ifndef __BLAKE256_H__
#define __BLAKE256_H__

#include <stdint.h>
#include <stddef.h>

typedef struct
{
  uint32_t h[8], s[4], t[2];
  int buflen, nullt;
  uint8_t  buf[64];
} state256;

typedef state256 state224;

typedef struct
{
  uint64_t h[8], s[4], t[2];
  int buflen, nullt;
  uint8_t buf[128];
} state512;

typedef state512 state384;


#define BLAKE256_DIGEST_LENGTH  64

void blake256_compress( state256 *S, const uint8_t *block );
void blake256_init( state256 *S );
void blake256_update( state256 *S, const uint8_t *in, uint64_t inlen );
void blake256_final( state256 *S, uint8_t *out );
void blake256_hash( uint8_t *out, const uint8_t *in, uint64_t inlen );

#endif
