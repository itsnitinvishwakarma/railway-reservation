
#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
//#include<conio.h>
#include"rlyres.h"

int main()
{
    int tn,result;
    Passenger *pr;
    int ticket;
    int *pticket_no;
    char *pmob_no;
    char *ptrain_no;
    int choice;

    add_trains();

 do
 {
    choice=enterchoice();
    switch(choice)
    {
    case 1:
        clrscr();
        view_trains();
        textcolor(WHITE);
        printf("\npress any key to go back to main menu");
        getch();
        clrscr();
        break;

    case 2:
        clrscr();
        pr=get_passenger_details();
        if(pr!=NULL)
        {
            tn=book_ticket(*pr);
            if(tn==-1)
            {
                printf("\nbooking Failed!");
                getch();
                break;
            }
            printf("\nticket no %d",tn);
            getch();
        }
        clrscr();
        break;

    case 3:
        ticket=accept_ticket_no();
        if(ticket!=0)
        {
            view_ticket(ticket);
        }
        break;

    case 4:
        clrscr();
        pmob_no=accept_mob_no();
        if(pmob_no!=NULL)
        {
            pticket_no=get_ticket_no(pmob_no);
            view_all_tickets(pmob_no,pticket_no);
        }
        clrscr();
        break;

    case 5:
        clrscr();
        view_all_booking();
        clrscr();
        break;

    case 6:
        clrscr();
        ptrain_no=accept_train_no();
        if(ptrain_no!=NULL)
        {
            view_bookings(ptrain_no);
        }
        clrscr();
        break;

    case 7:
        clrscr();
        ticket=accept_ticket_no();
        if(ticket!=0)
        {
            result=cancel_ticket(ticket);
            if(result==0)
            {
                textcolor(LIGHTRED);
                printf("Sorry! NO tickets booked against ticket no %d",ticket);
            }
            else if(result==1)
            {
                textcolor(LIGHTGREEN);
                printf("ticket no %d successfully cancelled.",ticket);
            }
            textcolor(WHITE);
            printf("\n\npress any key...");
        }
        getch();
        clrscr();
        break;

    case 8:
        clrscr();
        ptrain_no=accept_train_no();
        if(ptrain_no!=NULL)
        {
            result=cancel_train(ptrain_no);
            if(result==0)
            {
                textcolor(LIGHTGREEN);
                printf("\nTrain cancelled.");

            }
            else
            {
                textcolor(LIGHTGREEN);
                printf("\nTrain cancelled");
                printf("\nNo tickets were booked for that train no");
            }
        }
        textcolor(WHITE);
        printf("\nPress any key...");
        getch();
        clrscr();
        break;

    case 9 :
        exit(1);

    default:
        textcolor(RED);
        printf("Wrong choice!!Try again");
        printf("Press any key...");
        getch();
    }
} while(1);
return 0;
}
