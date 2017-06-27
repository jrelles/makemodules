#include "stdio.h"

int test_a(void);
int test_b(void);
int test_c(void);

int main(void)
{
    printf("a = %d\n", test_a());
    printf("b = %d\n", test_b());
    printf("c = %d\n", test_c());

    return 0;
}

