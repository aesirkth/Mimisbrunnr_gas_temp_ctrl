#ifndef ___CONFIG_H__
#define ___CONFIG_H__



class configuration {
    public:
        int tank_temp;
        int water_temp;
        int pid_conf;
        char temp1;
        char temp2;
        char temp3;
        char temp4;
        char temp5;
        char pump;
        char heater;
};


void activate_config_menu();

#endif //___CONFIG_H__
