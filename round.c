#include <stdio.h>
#include <math.h>
#include "MT.h"

#define N 1000000

int gen(void)
{
  double a;
  FILE *fp;

  init_genrand(42);

  fp = fopen("input.dat", "w");
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0)
      a = genrand_real1();
    else
      a = -genrand_real1();
    fprintf(fp, "%8.8f\n", a);
  }
  fclose(fp);

  return 0;
}

int run_round(void)
{
  float b;
  short a;
  FILE *fp, *gp;

  fp = fopen("input.dat", "r");
  gp = fopen("result_round.dat", "w");
  for (int i = 0; i < N; i++) {
    fscanf(fp, "%f", &b);
    a = round(b * 256.0);
    fprintf(gp, "%d\n", a);
    a = round(b / 256.0);
    fprintf(gp, "%d\n", a);
  }
  fclose(fp);
  fclose(gp);

  return 0;
}

int run_rint(void)
{
  float b;
  long long a;
  FILE *fp, *gp;

  fp = fopen("input.dat", "r");
  gp = fopen("result_rint.dat", "w");
  for (int i = 0; i < N; i++) {
    fscanf(fp, "%f", &b);
    a = rint(b * 16777216.0);
    fprintf(gp, "%d\n", a);
    a = rint(b / 256.0);
    fprintf(gp, "%d\n", a);
  }
  fclose(fp);
  fclose(gp);

  return 0;
}

int main(void)
{
  gen();
  run_round();
  run_rint();
  return 0;
}
