#include "mikemath.h"
#include<stdio.h>


int main(int argc, char** argv) {
    vector_h v1 = {.x = 1.0f, .y = 2.0f};
    vector_h v2 = {.x = 3.0f, .y = 4.0f};
    vector_h result = {.x = 0.0f, .y = 0.0f};
     
    Add(&result, &v1);
    printf("intermediary result: (%f, %f)\n", result.x, result.y);

    Add(&result, &v2);
    printf("final result: (%f, %f)\n", result.x, result.y);

    return 0;
}

void Add(vector_h* out, vector_h *in) {
    out->x = out->x + in->x;
    out->y = out->y + in->y;
}
