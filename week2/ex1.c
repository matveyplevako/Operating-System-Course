#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {
    int integer_variable = INT_MAX;
    float float_variable = FLT_MAX;
    double double_variable = DBL_MAX;

    printf("int max value: %d\nsize: %lu\n\n", integer_variable, sizeof(integer_variable));
    printf("float max value: %f\nsize: %lu\n\n", float_variable, sizeof(float_variable));
    printf("double max value: %f\nsize: %lu\n\n", double_variable, sizeof(double_variable));

    return 0;
}

