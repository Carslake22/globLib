/*!
    @file string11.c
    @brief Source file for string11.h
    @author Stuart Ianna
    @version 1.0
    @date June 2018
    @copyright GNU GPLv3
    @warning None
    @bug 

    @details

    @par Verified Compilers
    - arm-none-eabi-gcc (15:4.9.3+svn231177-1) 4.9.3 20150529 (prerelease)
*/

#include "string11.h"

static void (*out)(uint8_t);

void STRING11_setOutput(void (*out_fun)(uint8_t)){

    out = out_fun;
    return;
}

void print_c(char x){

    out((char)(x));
}

void print_u8(uint8_t x){

    if(x < 10){

        out(x+48);
        return;
    }
    if(x < 100){

        out((uint8_t)(x/10) + 48);
        out(x%10 + 48);
        return;
    }
    else{

        out((uint8_t)(x/100) + 48);
        x = x%100;
        out((uint8_t)(x/10) + 48);
        out(x%10 + 48);
        return;
    }
}

void print_8(int8_t x){

    if(x < 0){

        out('-');
    }
    print_u8(x*-1);

}

void print_u16(uint16_t x){

    uint16_t top = 10000;
    uint16_t mod;
    uint8_t printed = 0;

    if(x == 0){

        out((char)'0');
        return;
    }

    while(top){

        mod = x/top;
        if(mod || printed){
            out((uint8_t)(mod+48));
            printed = 1;
        }
        x = x % top;
        top /= 10;
    }
    return;
}

void print_16(int16_t x){

    if(x < 0){

        out('-');
        print_u16(x*-1);
    }
    else{

        print_u16(x);
    }
    return;
}

void print_u32(uint32_t x){

    uint32_t top = 1000000000;
    uint32_t mod;
    uint8_t printed = 0;

    if(x == 0){

        out((char)'0');
            printed = 1;
        return;
    }

    while(top){

        mod = x/top;
        if(mod || printed){
            out((uint8_t)(mod+48));
            printed = 1;
        }
        x = x % top;
        top /= 10;
    }
    return;
}

void print_32(int32_t x){

    if(x < 0){

        out('-');
        print_u32(x*-1);
    }
    else{

        print_u32(x);
    }
    return;

}

void print_f(float x){

    if(x < 0){

        out('-');
        x *= -1;
    }

    int32_t intpart = (int32_t)x;
    float decpart = x - intpart;
    uint8_t count = 0;

    print_u32(intpart);

    out((char)'.');

    while(count < MAX_DEC){

        decpart *= 10;
        out((uint8_t)decpart + 48);
        decpart -= (uint8_t)decpart;
        count++;
    }

}

void print_s(char *x){

    while(*x != 0){

        out((char)*x);
        x++;
    }

}

void prints_c(char x){
    
    print_c(x);
    print_c((char)' ');
}

void prints_u8(uint8_t x){

    print_u8(x);
    print_c((char)' ');

}

void prints_8(int8_t x){

    print_8(x);
    print_c((char)' ');
}

void prints_u16(uint16_t x){

    print_u16(x);
    print_c((char)' ');
}

void prints_16(int16_t x){

    print_16(x);
    print_c((char)' ');
}

void prints_u32(uint32_t x){

    print_u32(x);
    print_c((char)' ');
}

void prints_32(int32_t x){

    print_32(x);
    print_c((char)' ');
}

void prints_f(float x){

    print_f(x);
    print_c((char)' ');
}

void prints_s(char *x){

    print_s(x);
    print_c((char)' ');
}

void printc_c(char x){
    
    print_c(x);
    print_c((char)',');
}

void printc_u8(uint8_t x){

    print_u8(x);
    print_c((char)',');

}

void printc_8(int8_t x){

    print_8(x);
    print_c((char)',');
}

void printc_u16(uint16_t x){

    print_u16(x);
    print_c((char)',');
}

void printc_16(int16_t x){

    print_16(x);
    print_c((char)',');
}

void printc_u32(uint32_t x){

    print_u32(x);
    print_c((char)',');
}

void printc_32(int32_t x){

    print_32(x);
    print_c((char)',');
}

void printc_f(float x){

    print_f(x);
    print_c((char)',');
}

void printc_s(char *x){

    print_s(x);
    print_c((char)',');
}

void printl_c(char x){
    
    print_c(x);
    print_c((char)'\n');
    print_c((char)'\r');
}

void printl_u8(uint8_t x){

    print_u8(x);
    print_c((char)'\n');
    print_c((char)'\r');

}

void printl_8(int8_t x){

    print_8(x);
    print_c((char)'\n');
    print_c((char)'\r');
}

void printl_u16(uint16_t x){

    print_u16(x);
    print_c((char)'\n');
    print_c((char)'\r');
}

void printl_16(int16_t x){

    print_16(x);
    print_c((char)'\n');
    print_c((char)'\r');
}

void printl_u32(uint32_t x){

    print_u32(x);
    print_c((char)'\n');
    print_c((char)'\r');
}

void printl_32(int32_t x){

    print_32(x);
    print_c((char)'\n');
    print_c((char)'\r');
}

void printl_f(float x){

    print_f(x);
    print_c((char)'\n');
    print_c((char)'\r');
}

void printl_s(char *x){

    print_s(x);
    print_c((char)'\n');
    print_c((char)'\r');
}

void printt_c(char x){
    
    print_c(x);
    print_c((char)'\t');
}

void printt_u8(uint8_t x){

    print_u8(x);
    print_c((char)'\t');

}

void printt_8(int8_t x){

    print_8(x);
    print_c((char)'\t');
}

void printt_u16(uint16_t x){

    print_u16(x);
    print_c((char)'\t');
}

void printt_16(int16_t x){

    print_16(x);
    print_c((char)'\t');
}

void printt_u32(uint32_t x){

    print_u32(x);
    print_c((char)'\t');
}

void printt_32(int32_t x){

    print_32(x);
    print_c((char)'\t');
}

void printt_f(float x){

    print_f(x);
    print_c((char)'\t');
}

void printt_s(char *x){

    print_s(x);
    print_c((char)'\t');
}

