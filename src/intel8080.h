#include <stdlib.h>
#include <stdint.h>

typedef struct condition_flags {
    uint8_t    zero:1;
    uint8_t    sign:1;
    uint8_t    parity:1;
    uint8_t    carry:1;
    uint8_t    accumulator:1;
    uint8_t    pad:3;
} condition_flags;    

//    typedef struct State8080 {    
//     uint8_t    a;    
//     uint8_t    b;    
//     uint8_t    c;    
//     uint8_t    d;    
//     uint8_t    e;    
//     uint8_t    h;    
//     uint8_t    l;    
//     uint16_t    sp;    
//     uint16_t    pc;    
//     uint8_t     *memory;    
//     struct      ConditionCodes      cc;    
//     uint8_t     int_enable;    
//    } State8080;    

typedef struct State8080 {
    uint16_t pc;
    uint16_t sp;
    uint8_t* ram;

    uint8_t a;

    uint8_t b;
    uint8_t c;

    uint8_t d;
    uint8_t e;

    uint8_t h;
    uint8_t l;

    uint8_t w;
    uint8_t z;

    condition_flags cf;
} State8080;