#include "ros/ros.h"                //Declaring required headers
#include "voting/vote.h"
#include "stdio.h"
#include "string.h"


//declaring count variables
int na=0,nb=0,nc=0,nd=0,ne=0,nf=0,voter=0;


//function to fetch and process the input
void message_pub(const voting::vote::ConstPtr &mes)
{
    long long int vid=mes->voteridnum.data;

    int dd=mes->dd.data;
    int mm=mes->mm.data;
    int yyyy=mes->yyyy.data;
    
    //counting the votes
    switch(mes->voting_to.data)                     
    {
        case 'A':
        na++;
        break;

        case 'B':
        nb++;
        break;

        case 'C':
        nc++;
        break;

        case 'D':
        nd++;
        break;

        case 'E':
        ne++;
        break;

        case 'F':
        nf++;
        break;

    }
    voter++;
    printf("\n\n\n\n\n\n\n\n_______________________________________________\nLast vote:\n");
    printf("\nName of the voter : ");
    ROS_INFO("%s",mes->votername.data.c_str());
    printf("\nVoter ID : %lld",vid);
    printf("\nDate of birth : %d/%d/%d",dd,mm,yyyy);




    printf("\n\n------------*****Results*****------------\n");
    printf("A. Dr.Sivaselvan : %d\nB. Dr.Gowthaman : %d\nC. Dr.Sudhir Varadharajan : %d\nD. Dr.Ashok Kumar Reddy : %d\nE. Dr.Karthick : %d\nF. Dr.Raja : %d\n",na,nb,nc,nd,ne,nf);
}

int main(int argc, char **argv)                 //main function
{
    //Initialize the ROS system and become a node .
    ros::init(argc, argv, "subs");
    ros::NodeHandle nh;

    
    //Initialising subscriber object from topic
    ros::Subscriber s = nh.subscribe("voted",1000,&message_pub);
    
    //facilitating loop of main function
    ros::spin(); 


    return 0;
}