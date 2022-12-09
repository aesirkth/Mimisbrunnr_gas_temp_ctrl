#ifndef ___CONTROL_H__
#define ___CONTROL_H__

class telemetry {
    public:
        int temp1;
        int temp2;
        int temp3;
        int temp4;
        int temp5;
        char pump;
        char heater;
};


void measure_all_temp();

#endif //___CONTROL_H__
