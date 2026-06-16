/* 
   Demo zu Informatik_02_Datentypen Slide 8.
   
   Einfach kompilieren mit 'gcc funwithfloats.c'
   und danach ausführen, z.B.: './a.out'

   Viel Spaß,
   RO 28.10.2020
*/

#include <stdio.h>
#include <stdlib.h>

#define BG_COLOR_MRED       "\033[48;2;205;0;0m"
#define BG_COLOR_MORANGE    "\033[48;2;205;140;0m"
#define BG_COLOR_MGREEN     "\033[48;2;0;205;0m"
#define FG_COLOR_MRED       "\033[38;2;205;0;0m"
#define FG_COLOR_MORANGE    "\033[38;2;205;140;0m"
#define FG_COLOR_MGREEN     "\033[38;2;0;205;0m"
#define ANSI_C_RST   "\x1b[0m"

#define BINPRINT(v,l) {int zz; for (zz=0; zz<l; zz++) printf("%1d", (v>>(31-zz+l))&1);}

void printfcol(float fval)
{
  unsigned int s, e, m;
  unsigned int *ui;
 
  ui = (unsigned int *) &fval;
  s = (*ui >> 31) & 0x00000001;
  e = (*ui >> 23) & 0x000000ff;
  m = (*ui) & 0x007fffff;
  
  printf(BG_COLOR_MRED);
  BINPRINT(s,1);
  printf(ANSI_C_RST " " BG_COLOR_MORANGE);
  BINPRINT(e,8);
  printf(ANSI_C_RST " " BG_COLOR_MGREEN);
  BINPRINT(m,23);
  printf(ANSI_C_RST "\n");

  printf(FG_COLOR_MORANGE "e=%3u(%4d)" FG_COLOR_MGREEN "m = %8u(%f)" ANSI_C_RST "\n", e, e-127, m, m/((float)0x800000));
  printf("%d*(1+%u/2^23)*2^(%u-127) bzw. ", s ? -1 : 1, m, e);
  printf("%d*(1+%f)*2^(%d)\n\n", s ? -1 : 1, m/((float)0x800000), e-127);
  
  return;
}

int main (int argc, char *argv[])
{
  float fval1, fval2, fsum;
  
  if (argc != 3)
    {
      printf ("usage is: %s <float1> <float2>\n", argv[0]);      
      exit(1);
    }
    
  sscanf(argv[1], "%f", &fval1);
  sscanf(argv[2], "%f", &fval2);

  fsum = fval1 + fval2;
  
  printf("%f + %f = %f\n\n", fval1, fval2, fsum);

  printfcol(fval1);
  printfcol(fval2);
  printfcol(fsum);

  return 0;
}
