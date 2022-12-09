#ifndef ___TELEMETRY_H__
#define ___TELEMETRY_H__

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

#endif //___TELEMETRY_H__
