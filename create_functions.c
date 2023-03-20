#include <kipr/wombat.h>
#include <create_functions.h>
#include <create_comp_lib.h>
#define hand 0
#define arm 1
#define base 0
#define arm_max 1200
#define arm_min 300
#define arm_mid 600
#define hand_max 2047 //also start
#define hand_min 600
#define hand_close 330
#define base_max 1300
#define base_min 0
#define base_start 150
#define left 2
#define right 1

int cube_wide = 1361;
int cube_grab = 620;
/* If you change one of the defines above that matches one below, you must change the other as well */

//#define down 1200
//int down = down;
int up = down - 900;
int mid = down - 600;
int arm_water = down - 400;
int arm_building = down - 640;

//#define front 1300
//int front = front;
int back = front - 1300;

//#define closed 600
//int closed = closed;
int open = closed + 1447;
int tight = closed - 300;
int small_open = closed + 1000;
int tightish = closed - 75;

void slow_arm (int x )//this funtion slows 
{ 

    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (x > arm_max) {desired_position = arm_max;}
    else if(x < arm_min) {desired_position = arm_min;}
    else {desired_position = x;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
    }

    set_servo_position (arm, x);
    disable_servo (arm);
}

void slow_hand (int x )//this funtion slows 
{ 

    enable_servo(hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (x > hand_max) {desired_position = hand_max;}
    else if(x < hand_min) {desired_position = hand_min;}
    else {desired_position = x;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(hand, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(hand, current_position);
         msleep(2);
        }
    }

    set_servo_position (hand, x);
    disable_servo (hand);
}

void slow_base (int x )//this funtion slows 
{ 

    enable_servo(base);
    int desired_position;
    int current_position = get_servo_position(base);
    if (x > base_max) {desired_position = base_max;}
    else if(x < base_min) {desired_position = base_min;}
    else {desired_position = x;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(base, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(base, current_position);
         msleep(2);
        }
    }

    set_servo_position (base, x);
    disable_servo (base);
}

void start_position(){
    slow_arm(up);
    slow_base(back);
    slow_arm(mid);
    slow_hand(open);
}

void arm_out(){
    slow_base(front);
    slow_arm(down);
}

void slow_base_valve()//this function slows 
{ 

    enable_servo(base);
    int desired_position;
    int current_position = get_servo_position(base);
    if (front-750 > base_max) {desired_position = base_max;}
    else if(front-750 < base_min) {desired_position = base_min;}
    else {desired_position = front-750;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(base, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(base, current_position);
         msleep(2);
        }
    }

    set_servo_position (base, front-750);
    disable_servo (base);
}

void slow_start() 
{ 	
    enable_servo(arm);
    enable_servo(hand);
    enable_servo(base);
    int d = mid;
    int dd = open;
    int ddd = back;
    int c = get_servo_position(arm);
    int cc = get_servo_position(hand);
    int ccc = get_servo_position(base);

    while((c != d) || (cc != dd) || (ccc != ddd)) // this loop is being exited instantly. need to fix.
    {
        if(c < d)
        { c=c+1;
         set_servo_position(arm, c);
         msleep(2);
        }
        if(c > d)
        { c=c-1;
         set_servo_position(arm, c);
         msleep(2);
        }
        if(cc < dd)
        { cc=cc+1;
         set_servo_position(hand, cc);
         msleep(2);
        }
        if(cc > dd)
        { cc=cc-1;
         set_servo_position(hand, cc);
         msleep(2);
        }
        if(ccc < ddd)
        { ccc=ccc+1;
         set_servo_position(base, ccc);
         msleep(2);
        }
        if(ccc > ddd)
        { ccc=ccc-1;
         set_servo_position(base, ccc);
         msleep(2);
        }
        msleep(2);
    }
    set_servo_position(arm, mid);
    set_servo_position(hand,open);
    set_servo_position(base,back);
    disable_servo(arm);
    disable_servo(hand);
    disable_servo(base);
}

void slow_arm_pre_valve()//this funtion slows 
{ }

void slow_base_front()//this funtion slows 
{ 
    enable_servo(base);
    int desired_position;
    int current_position = get_servo_position(base);
    if (front > base_max) {desired_position = base_max;}
    else if(front < base_min) {desired_position = base_min;}
    else {desired_position = front;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(base, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(base, current_position);
         msleep(2);
        }
    }

    set_servo_position (base, front);
    disable_servo (base);
}

void slow_arm_up()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (up > arm_max) {desired_position = arm_max;}
    else if(up < arm_min) {desired_position = arm_min;}
    else {desired_position = up;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
    }

    set_servo_position (arm, up);
    disable_servo (arm);
}

void slow_arm_up2()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (up > arm_max) {desired_position = arm_max;}
    else if(up < arm_min) {desired_position = arm_min;}
    else {desired_position = up;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
    }

    set_servo_position (arm, up);
    disable_servo (arm);

    enable_servo(base);
    int desired_position2;
    int current_position2 = get_servo_position(base);
    if (front > base_max) {desired_position2 = base_max;}
    else if(front < base_min) {desired_position2 = base_min;}
    else {desired_position2 = front;}

    while(current_position2 != desired_position2)
    {
        if(current_position2 < desired_position2)
        { current_position2=current_position2 +1;
         set_servo_position(base, current_position2);
         msleep(2);
        }
        if(current_position2 > desired_position2)
        { current_position2=current_position2 -1;
         set_servo_position(base, current_position2);
         msleep(2);
        }
    }

    set_servo_position (base, front);
    disable_servo (base);
}

void slow_hand_open()//this funtion slows 
{ 
    enable_servo(hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (small_open > hand_max) {desired_position = hand_max;}
    else if(small_open < hand_min) {desired_position = hand_min;}
    else {desired_position = small_open;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(hand, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(hand, current_position);
         msleep(2);
        }
    }

    set_servo_position (hand, small_open);
    disable_servo (hand);
}

void slow_hand_small_open()//this funtion slows 
{}

void slow_arm_down()//this funtion slows 
{ 
    enable_servo(arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (down > arm_max) {desired_position = arm_max;}
    else if(down < arm_min) {desired_position = arm_min;}
    else {desired_position = down;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(arm, current_position);
         msleep(2);
        }
    }

    set_servo_position (arm, down);
    disable_servo (arm);
}

void slow_hand_close()//this funtion slows 
{ 
    enable_servo(hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (tight > hand_max) {desired_position = hand_max;}
    else if(tight < hand_min) {desired_position = hand_min;}
    else {desired_position = tight;}

    while(current_position != desired_position)
    {
        if(current_position < desired_position)
        { current_position=current_position +1;
         set_servo_position(hand, current_position);
         msleep(1);
        }
        if(current_position > desired_position)
        { current_position=current_position -1;
         set_servo_position(hand, current_position);
         msleep(1);
        }
    }

    set_servo_position (hand, tight);
    disable_servo (hand);
}

void short_pause(){
    create_stop();
    msleep(250);
}

void slow_arm_bucket()//this funtion slows 
{ }

void shake_arm(){}

void fast_hand (int x )//this funtion slows 
{ 

    enable_servo(hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (x > hand_max) {desired_position = hand_max;}
    else if(x < hand_min) {desired_position = hand_min;}
    else {desired_position = x;}

    while(current_position >= desired_position+2 || current_position <= desired_position-2)
    {
        if(current_position < desired_position)
        { current_position=current_position +2;
         set_servo_position(hand, current_position);
         msleep(2);
        }
        if(current_position > desired_position)
        { current_position=current_position -2;
         set_servo_position(hand, current_position);
         msleep(2);
        }
    }

    set_servo_position (hand, x);
    disable_servo (hand);
}

void grab_water(){}

void pile_water(int x){}

void push_water(){}

void recover_water(){}
void first_water(){}
void all_water(){}
void first_water_down(){}

void all_water_drop(){}

void shake_arm_bucket(){}

int black;
int white;

void create_forward(int dist, int speed)
{
    dist*=10; //Converts centimeters into millimeters
    set_create_distance(0); //Clears create position counter
    create_drive_straight(speed); //Initializes movement
    while(get_create_distance()<dist) //Waits until distance traveled reaches distance
    {
        msleep(1);
    }
    create_stop(); //Stops movement
}

void create_backward(int dist, int speed)
{
    dist*=10; //Converts centimeters into millimeters
    set_create_distance(0); //Clears create position counter
    create_drive_straight(-speed); //Initializes movement 
    while(get_create_distance()>-dist) //Waits until distance traveled reaches distance
    {
        msleep(1);
    }
    create_stop(); //Stops movement
}

void create_left(int degrees, int speed)
{
    set_create_total_angle(0); //Clears create angle counter
    create_drive_direct(-speed,speed); //Initializes movement
    while(get_create_total_angle()<degrees) //Waits until angle turned reaches degrees
    {
        msleep(5);
    }
    create_stop(); //Stops movement
}
/**
 * create_right makes the create turn right in place. 
 * Requires no predefined constants
 * degrees: angle to turn in degrees
 * speed: speed to drive at on a range from 0-1000
 */
void create_right(int degrees, int speed)
{
    set_create_total_angle(0); //Clears create angle counter
    create_drive_direct(speed,-speed); //Initializes movement
    while(get_create_total_angle()>-degrees) //Waits until angle turned reaches degrees
    {
        msleep(5);
    }
    create_stop(); //Stops movement
}
