#include "ros/ros.h"                    //Declaring required header files
#include "voting/vote.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "iostream"

using namespace std;

int main(int argc, char **argv)              //main function
{
    //Initialize the ROS system and become a node .
    ros::init(argc, argv, "publ");              
    ros::NodeHandle nh;

    //Declaring variables to take input from console as c++
    int dd,mm,yyyy,x;
    long long int num;
    char input[1000],vote;


    //Declaring Publisher object and topic
    ros::Publisher p = nh.advertise<voting::vote>("voted",1000);
    ros::Rate rate(10);

    //ros loop
    while(ros::ok)              //executes until stops
    {
        voting::vote msg;

        //geiing inputs, precessing validity and saving it in object
        printf("\n______________________________________________________\n$$$$$$$$$$ Welcome to voting machine $$$$$$$$$$\nEnter your name:");
        scanf("\n%d",&x);
        cin.getline(input,998);

        msg.votername.data=input;

        printf("\nEnter your Date of birth(dd:mm:yyyy): ");
        scanf("%d:%d:%d",&dd,&mm,&yyyy);
        

        if(!(mm<13&&mm>0))
        {
            printf("\ninvalid month entered. Re-enter credentials");
            continue;
        }

        if((2021-yyyy<=18))
        {
            printf("\nYou are not of legal age to vote. Kinly allow the next vote");
            continue;
        }

        if(dd>31&&dd<1)
        {
            printf("\nYou have entered invaild date. Re-enter the details");
            continue;
        }

        msg.dd.data=dd;
        msg.mm.data=mm;
        msg.yyyy.data=yyyy;

        printf("\nEnter the voter ID : ");
        scanf("%lld",&num);

        msg.voteridnum.data=num;

        printf("\nCasting vote: (Choose the candidate correctly)\nCandidate list:\nA. Dr.Sivaselvan\nB. Dr.Gowthaman\nC. Dr.Sudhir Varadharajan\nD. Dr.Ashok Kumar Reddy\nE. Dr.Karthick\nF. Dr.Raja\nEnter A,B,C,D,E or F (the candidate you are casting your vote for):  ");
        scanf("\n%c",&vote);

        if(!(vote=='A'||vote=='B'||vote=='C'||vote=='D'||vote=='E'||vote=='F'))
        {
            printf("\nInvalid vote Choose correct\nRe-Enter the details");
            printf("\nEnter any number to proceed : ");
            scanf("%d",&x);
            continue;
        }

        msg.voting_to.data=vote;

        printf("\n\n\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\nChecking entered Details:\n\nName: %s\nDate of Birth: %d:%d:%d\nVoter ID : %d\nVoted for : ",input,dd,mm,yyyy,num);

        


        switch(vote)                     
    {
        case 'A':
        printf("A. Dr.Sivaselvan");
        break;

        case 'B':
        printf("B. Dr.Gowthaman");
        break;

        case 'C':
        printf("C. Dr.Sudhir Varadharajan");
        break;

        case 'D':
        printf("D. Dr.Ashok Kumar Reddy");
        break;

        case 'E':
        printf("E. Dr.Karthick");
        break;

        case 'F':
        printf("F. Dr.Raja");
        break;
    }

        printf("\n\nCheck if your entered details are correct if yes enter '1' else enter anyother number to re-enter details : ");
        scanf("\n%d",&x);
        

        if(!(x==1))
        {
            continue;
        }
        msg.votername.data=input;

        p.publish(msg);

        printf("\nYour vote is SUCCESSFULLY CASTED");
        printf("\nEnter any number to proceed : ");
        scanf("%d",&x);


        printf("\n\n\n\n\n\n\n");
        printf("______________________________________________________\n");


        rate.sleep();

    }


    return 0;
}