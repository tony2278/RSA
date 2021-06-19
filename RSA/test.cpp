#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rsa.h"
#include "write2file.h"

int main2(int argc, char **argv)
{
	write2file();

	readfromfile();
}

int main1(int argc, char **argv)
{
  struct public_key_class pub[1];
  struct private_key_class priv[1];
  rsa_gen_keys(pub, priv, PRIME_SOURCE_FILE);

  printf("Private Key:\n Modulus: %lld\n Exponent: %lld\n", (long long)priv->modulus, (long long) priv->exponent);
  printf("Public Key:\n Modulus: %lld\n Exponent: %lld\n", (long long)pub->modulus, (long long) pub->exponent);
  
  char message[] = "20210529smiles20220529";
  int i;

  printf("Original:\n");
  for(i=0; i < strlen(message); i++){
    printf("%lld ", (long long)message[i]);
  }  

  printf("\nOriginal:\n");
  for (i = 0; i < strlen(message); i++) {
	  printf("%c ", message[i]);
  }
  
  long long *encrypted = rsa_encrypt(message, sizeof(message), pub);
  if (!encrypted){
    fprintf(stderr, "Error in encryption!\n");
    return 1;
  }
  printf("\nEncrypted:\n");
  for(i=0; i < strlen(message); i++){
    printf("%lld\n", (long long)encrypted[i]);
  }  
  
  char *decrypted = rsa_decrypt(encrypted, 8*sizeof(message), priv);
  if (!decrypted){
    fprintf(stderr, "Error in decryption!\n");
    return 1;
  }
  printf("\nDecrypted:\n");
  for(i=0; i < strlen(message); i++){
    printf("%lld ", (long long)decrypted[i]);
  }  

  printf("\nDecrypted:\n");
  for (i = 0; i < strlen(message); i++) {
	  printf("%c ", decrypted[i]);
  }
  
  printf("\n");
  free(encrypted);
  free(decrypted);
  return 0;
}
