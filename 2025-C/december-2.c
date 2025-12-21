#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main() {
   FILE *in;
   fopen_s(&in, "december-2.in", "r");

   char input[10000];
   fgets(input, 10000, in);

   char *token;
   char *context = NULL;
   token = strtok_s(input, ",", &context);

   long long sum = 0;

   while (token != NULL) {
       char* low = malloc(100);
       char* high = malloc(100);

       int i = 0;
       while (token[i] != '-') {
           low[i] = token[i];
           i++;
       }
       low[i] = '\0';

       i++;
       int offset = i;
       while (token[i] != '\0') {
           high[i - offset] = token[i];
           i++;
       }
       high[i - offset] = '\0';

       for (long long val = strtoll(low, NULL, 0); val <= strtoll(high, NULL, 0); val++) {
           char* id = malloc(100);
           sprintf(id, "%lld", val);
           int len = strlen(id);
           if (len % 2 == 0) {
               char invalid = TRUE;
               for (int j = 0; j < len / 2; j++) {
                   if (id[j] != id[j + len / 2]) {
                       invalid = FALSE;
                       break;
                   }
               }
               if (invalid) {
                   sum += val;
                   printf("INVALID: %s\n", id);
               }
           }
       }

       token = strtok_s(NULL, ",", &context);
   }

   printf("%lld\n", sum);
}
