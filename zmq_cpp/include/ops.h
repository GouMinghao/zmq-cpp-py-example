#include <cstdint>

#pragma pack(push)
#pragma pack(1) // align in 1 byte

typedef struct
{
    int32_t op1;
    int32_t op2;
} OpInput_t;

typedef struct
{
    int32_t res;
} OpOutput_t;

#pragma pack(pop)