#ifndef EASELIB_H
#define EASELIB_H

#include <math.h>

#define NONE     0
#define LINEAR   1
#define SINE     2
#define CUBIC    3
#define QUINT    4
#define CIRC     5
#define ELASTIC  6
#define QUAD     7
#define QUART    8
#define EXPO     9
#define BACK     10
#define BOUNCE   11


// these are pre-baked math constants, compilers should do this automatically too, but i don't trust them
#define c1 1.70158
#define c3 2.70158
#define c4 2.09439
#define n1 7.5625
#define d1 2.75



float ease(float t, int ease_in, int ease_out){

    float eased;

    if(ease_in==NONE){
        t+=1;
        t*=0.5;
    }

    //clamps "t" to be between 0.0 and 1.0
    if (t < 0.0)
        return 0.0;
    else if (t > 1.0)
        return 1.0;


    char ease;
    _Bool reversed=0;

    if(t>=0.5 && ease_out!=NONE){
        t=1.0-t;
        reversed=1.0;
        ease = ease_out;
    }else{
        ease = ease_in;
    }

    if(ease_out!=NONE) t*=2;


    switch(ease){

        case LINEAR: eased = t; break;

        case SINE: eased = 1.0 - cos((t * 3.141592653) / 2.0); break;

        case CUBIC: eased = t*t*t; break;

        case QUINT: eased = t*t*t*t*t; break;

        case CIRC: eased = 1.0 - sqrt(1.0 - t*t); break;

        case ELASTIC: eased = (t == 0 ? 0 : t == 1 ? 1 : -pow(2, 10 * t - 10) * sin((t * 10 - 10.75) * c4)); break;

        case QUAD: eased = t*t; break;

        case QUART: eased = t*t*t*t; break;

        case EXPO: eased = (t == 0 ? 0 : pow(2, 10 * t - 10)); break;

        case BACK: eased = c3 * t*t*t - c1 * t*t; break;

        case BOUNCE:    // yes, bounce is a brutally complex one.
            t= 1-t;
            if (t < 1 / d1) {
                eased =  n1 * t * t;
            } else if (t < 2 / d1) {
                t -= 1.5 / d1;
                eased =  n1 * t * t + 0.75;
            } else if (t < 2.5 / d1) {
                t -= 2.25 / d1;
                eased =  n1 * t * t + 0.9375;
            } else {
                t -= 2.25 / d1;
                eased =  n1 * t * t + 0.984375;
            }
            eased = 1-eased;
            break;
    }




        if(ease_in==NONE) return -eased+1;
        else if(ease_out==NONE) return eased;


            if(reversed) return (-eased+2)/2;
            return eased/2;


}

#endif
