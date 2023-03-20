#include <kipr/wombat.h>
#include <create_functions.h>
#include <create_comp_lib.h>
#include <stdlib.h>
#define right_motor 0
#define left_motor 1
#define target_theta_45 265000
#define target_theta_90 507500 // WORKING ON NUMBERS FOR 4184
#define target_theta_180 1095000 // ALL NUMBERS SHOULD BE GOOD
#define target_theta_01 140000
#define target_theta_02 1200000
#define target_theta_03 485000
#define target_theta_05 225000
int target_theta_m45 = target_theta_45;
int target_theta_m90 = target_theta_90;
int target_theta_m180 = target_theta_180; 

#define analog_white 300
#define analog_black 3500
#define digital_right 0
#define digital_left 1
#define left_IR 1
#define right_IR 0
#define stop 0
#define cliff 1700

#define hat 0

int turn = 110;
int square = 200;
int PID = 150;

void move(l_speed,r_speed){
    mav(right_motor,r_speed);
    mav(left_motor,l_speed);
}

int white = 1;
int black = 2;
int physical = 3;
int black_speed;
void square_up(int ending,int speed){
    if(speed > 0 && speed < 600){
        black_speed = 0.5*speed;
    }
    else{black_speed = 0.25*speed;}
    if(ending == 1 || ending == 2){
        while(1){
            if(analog(left_IR)<analog_white && analog(right_IR)<analog_white){
                move(speed,speed);
            }
            if(analog(right_IR)>analog_white){
                move(speed,stop);
            }
            if(analog(left_IR)>analog_white){
                move(stop,speed);
            }
            if(analog(left_IR)>analog_white && analog(right_IR)>analog_white) {
                move(stop,stop);
                break;
            }
        }
    }
    if(ending == 3){
        ao();
    }
    switch(ending){
        case 3:
            {
                while(1){
                    if(digital(digital_right)==0 && digital(digital_left)==0){
                        move(speed,speed);
                    }
                    if(digital(digital_right)==1){
                        move(speed,stop);
                    }
                    if(digital(digital_left)==1){
                        move(stop,speed);
                    }
                    if(digital(digital_right)==1 && digital(digital_left)==1){
                        move(stop,stop);
                        break;
                    }
                }
            }
        case 1:
            {
                while(1){
                    if(analog(left_IR)>analog_white && analog(right_IR)>analog_white){
                        move(black_speed,black_speed);
                    }
                    if(analog(left_IR)<analog_white){
                        move(stop,black_speed);
                    }
                    if(analog(right_IR)<analog_white){
                        move(black_speed,stop);
                    }
                    if(analog(left_IR)<analog_white && analog(right_IR)<analog_white){
                        move(stop,stop);
                        break;
                    }
                    
                }
            }
        case 2:
            {
                while(1){
                    if(analog(left_IR)>analog_white && analog(right_IR)>analog_white){
                        move(-1*black_speed,-1*black_speed);
                    }
                    if(analog(left_IR)<analog_white){
                        move(stop,-1*black_speed);
                    }
                    if(analog(right_IR)<analog_white){
                        move(-1*black_speed,stop);
                    }
                    if(analog(left_IR)<analog_white && analog(right_IR)<analog_white){
                        move(stop,stop);
                        break;
                    }
                }
            }
    }
}

double bias = 0.0;

double calibrate_gyro(){
    int i = 0;
    double avg = 0;
    while( i < 50){
        avg += gyro_z();
        msleep(1);
        i++;
        printf("Gyro Z: %d\n",gyro_z());
    }
    bias = avg / 50.0;
    printf("New Bias: %f\n", bias);
    return bias;
}

void drive_with_gyro(int speed, double time){}

void PID_gyro_drive(int speed, double time){}

void turn_with_gyro_create(int speed, int deg){}
void turn_with_gyro(int speed, int deg){}

void PID_gyro_drive_create(int speed, double time){}

// white = 1 "through"
// black = 2 "stop"
void square_up_front_create(int ending,int speed){
    if(speed > 0 && speed < 600){
        black_speed = 0.5*speed;
    }
    else{black_speed = 0.25*speed;}
    if(ending == 1 || ending == 2){
        while(1){
            if(get_create_lfcliff_amt()>cliff && get_create_rfcliff_amt()>cliff){
                create_drive_direct(speed,speed);
            }
            if(get_create_rfcliff_amt()<cliff){
                create_drive_direct(speed,stop);
            }
            if(get_create_lfcliff_amt()<cliff){
                create_drive_direct(stop,speed);
            }
            if(get_create_lfcliff_amt()<cliff && get_create_rfcliff_amt()<cliff) {
                create_drive_direct(stop,stop);
                break;
            }
        }
    }
    switch(ending){
        case 1:
            {
                while(1){
                    if(get_create_lfcliff_amt()<cliff && get_create_rfcliff_amt()<cliff){
                        create_drive_direct(black_speed,black_speed);
                    }
                    if(get_create_lfcliff_amt()>cliff){
                        create_drive_direct(stop,black_speed);
                    }
                    if(get_create_rfcliff_amt()>cliff){
                        create_drive_direct(black_speed,stop);
                    }
                    if(get_create_lfcliff_amt()>cliff && get_create_rfcliff_amt()>cliff){
                        create_drive_direct(stop,stop);
                        break;
                    }
                }
            }
        case 2:
            {
                while(1){
                    if(get_create_lfcliff_amt()<cliff && get_create_rfcliff_amt()<cliff){
                        create_drive_direct(-1*black_speed,-1*black_speed);
                    }
                    if(get_create_lfcliff_amt()>cliff){
                        create_drive_direct(stop,-1*black_speed);
                    }
                    if(get_create_rfcliff_amt()>cliff){
                        create_drive_direct(-1*black_speed,stop);
                    }
                    if(get_create_lfcliff_amt()>cliff && get_create_rfcliff_amt()>cliff){
                        create_drive_direct(stop,stop);
                        break;
                    }
                }
            }
    }
}

void linefollow_create(int speed){
    while(1){
        if(get_create_rcliff_amt()<cliff){
            create_drive_direct((3*speed)/4,speed);
        }
        if(get_create_rcliff_amt()>cliff){
            create_drive_direct(speed,(3*speed)/4);
        }
    }
}

void square_up_back_create(int ending,int speed){
    if(speed > 0 && speed < 600){
        black_speed = 0.5*speed;
    }
    else{black_speed = 0.25*speed;}
    if(ending == 1 || ending == 2){
        while(1){
            if(get_create_lcliff_amt()>cliff && get_create_rcliff_amt()>cliff){
                create_drive_direct(speed,speed);
            }
            if(get_create_rcliff_amt()<cliff){
                create_drive_direct(speed,stop);
            }
            if(get_create_lcliff_amt()<cliff){
                create_drive_direct(stop,speed);
            }
            if(get_create_lcliff_amt()<cliff && get_create_rcliff_amt()<cliff) {
                create_drive_direct(stop,stop);
                break;
            }
        }
    }
    switch(ending){
        case 1:
            {
                while(1){
                    if(get_create_lcliff_amt()<cliff && get_create_rcliff_amt()<cliff){
                        create_drive_direct(black_speed,black_speed);
                    }
                    if(get_create_lcliff_amt()>cliff){
                        create_drive_direct(stop,black_speed);
                    }
                    if(get_create_rcliff_amt()>cliff){
                        create_drive_direct(black_speed,stop);
                    }
                    if(get_create_lcliff_amt()>cliff && get_create_rcliff_amt()>cliff){
                        create_drive_direct(stop,stop);
                        break;
                    }
                }
            }
        case 2:
            {
                while(1){
                    if(get_create_lcliff_amt()<cliff && get_create_rcliff_amt()<cliff){
                        create_drive_direct(-1*black_speed,-1*black_speed);
                    }
                    if(get_create_lcliff_amt()>cliff){
                        create_drive_direct(stop,-1*black_speed);
                    }
                    if(get_create_rcliff_amt()>cliff){
                        create_drive_direct(-1*black_speed,stop);
                    }
                    if(get_create_lcliff_amt()>cliff && get_create_rcliff_amt()>cliff){
                        create_drive_direct(stop,stop);
                        break;
                    }
                }

            }
    }
}

void turn_90(){
    double theta = 0;
    int targetTheta = target_theta_90; 

    create_drive_direct(60,60*-1);
    while(theta < targetTheta){
        msleep(10);
        theta += abs(gyro_z() - bias) * 10;
        printf("Turn Gyro Z: %d\n",gyro_z());
    }
    create_drive_direct(0,0);
}

int bump = 100;

void reach_material(){
}

void create_line_follow(int dist){
    set_create_distance(0);
    while (get_create_distance() < dist){
        if (get_create_lfcliff_amt() < 1600){
            create_drive_direct(134,200);
        }
        else{
            create_drive_direct(200,134);
        }
        msleep(15);
    }
}