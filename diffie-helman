#include <math.h>
#include <stdio.h>

int key_calculation(int val_A, int privateKey, int val_mod) {
  long long int first = pow(val_A, privateKey);
  int res = first % val_mod;
  return res;
}

int main() {
  int n, g, x, y, final_a, final_b, k1, k2;
  printf("Enter Public Keys for A and B (must be prime numbers): ");
  scanf("%d%d", &n, &g);
  printf("\nEnter Private keys for A and B (random numbers): ");
  scanf("%d%d", &x, &y);

  final_a = key_calculation(g, x, n);
  final_b = key_calculation(g, y, n);

  k1 = key_calculation(final_b, x, n);
  k2 = key_calculation(final_a, y, n);

  if (k1 == k2)
    printf("\nKey for A : %d\nKey for B : %d", k1, k2);
  return 0;
}
