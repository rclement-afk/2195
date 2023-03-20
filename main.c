#include <kipr/wombat.h>
#include <create_functions.h>
#include <create_comp_lib.h>
#include <stdlib.h>
//arm max is 1386
//arm min is 400
//close claw 300
//claw open 1635
//how to make the robot fit in the starting box,close the claw,put the arm down and put the robot in the back corner.
int main()
{
  create_connect();
  enable_servos();
  slow_arm(530);
    msleep(100);
    slow_hand(650);
    //start up
    msleep(100);
    slow_hand(1200);
    msleep(150);
    create_forward(10,250);
    msleep(100);
    //taken first pom
    slow_hand(620);
    msleep(100);
    slow_arm(1300);
    msleep(100);
    create_right(180,250);
    msleep(100);
    slow_hand(1300);
    msleep(100);
    create_left(220,250);
    msleep(100);
    create_drive_direct(-250,-250);
    msleep(300);
    slow_arm(500);
    msleep(100);
    create_forward(10,250);
    msleep(100);
    slow_hand(600);
    msleep(100);
    slow_arm(800);
    msleep(100);
    create_right(90,250);
    msleep(100);
    slow_hand(1300);
    msleep(100);
   // turning for third pom
    create_left(27,250);
    msleep(100);
    slow_arm(450);
    msleep(100);
    create_forward(13,250);
    msleep(100);
    //grabbing the third pom
    slow_hand(620);
    msleep(100);
    create_right(45,250);
    msleep(100);
    slow_hand(1200);
    msleep(100);
    slow_arm(1200);
    msleep(100);
    create_left(20,250);
    msleep(100);
   create_drive_direct(-250,-250);
    msleep(1300);
    //turning for fourth pom
    create_left(20,250);
    msleep(100);
    slow_arm(500);
    msleep(100);
    create_forward(36,250);
    msleep(100);
    //closing on second green pom
    slow_hand(620);
    msleep(100);
    create_left(180,250);
    msleep(100);
    //opening claw to release second green pom.
     slow_hand(1300);
    msleep(100);
    slow_arm(1300);
    msleep(1000);
    create_left(80,250);
    msleep(1000);
    create_backward(20,250);
    msleep(1000);
    square_up_back_create(1,250);
    msleep(1000);
    create_left(105,250);
    msleep(100);
    slow_hand(620);
    msleep(100);
    slow_arm(520);
    msleep(100);
    //getting ready for the fling of the two red poms
   create_forward(20,250);
    msleep(100);
    create_right(90,200);
    msleep(100);
 //everything above is perfect
    slow_arm(1300);
    msleep(100);
    create_backward(6,250);
    msleep(100);
    create_right(15,250);
    msleep(100);
    square_up_back_create(1,250);//squaring up to get the next green poms
    msleep(100);
    create_forward(2,250);
    msleep(100);
    create_left(90,250);
    slow_arm(500);
    msleep(100);
    slow_hand(1400);
    msleep(100);
    create_forward(24,250);
    msleep(100);
    slow_hand(620);
    msleep(100);
    slow_arm(1300);
    msleep(100);
    create_left(180,250);
    msleep(100);
    create_forward(37,250);
    msleep(100);
    create_left(45,250);//this line turns final green stack to starting box
    msleep(100);
    create_forward(10,250);
    msleep(100);
    slow_hand(1200);
    msleep(100);
    create_right(145,250);
    msleep(100);
    return 0;
}
