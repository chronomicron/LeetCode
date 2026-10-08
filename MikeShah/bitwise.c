#include<stdio.h>

int main() {
    unsigned int a = 9; // 1001 in binary
    unsigned int b = 24; // 11000 in binary

    unsigned int result;

    result = a << 2; // Left shift a by 2 bits

    printf("Left Shift: binary = %b, result = %d\n", result, result); // Should print 36 (100100 in binary)
    

    result = a >> 2; // Right shift a by 2 bits
    printf("Right Shift: binary = %b, result = %d\n", result, result); // Should print 2 (0010 in binary)

    result = ~a; // Bitwise NOT of a
    printf("Bitwise NOT: binary = %b, result = %d\n", result, result); // Should print 4294967296 (in 32-bit unsigned representation)

    result = a & b; // Bitwise AND of a and b
    printf("Bitwise AND: binary = %b, result = %d\n", result, result); // Should print 8 (1000 in binary)

    result = a | b; // Bitwise OR of a and b
    printf("Bitwise OR: binary = %b, result = %d\n", result, result); // Should print 33 (100001 in binary)

    result = a ^ b; // Bitwise XOR of a and b
    printf("Bitwise XOR: binary = %b, result = %d\n", result, result); // Should print 25 (11001 in binary)

    return 0;
}
