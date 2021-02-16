#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

typedef struct Train
{
    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
}Train;

typedef struct Passenger
{
    char p_name[20];
    char gender;
    char train_no[20];
    char p_class;
    char address[30];
    int age;
    int ticket_no;
    char mob_no[11];
}Passenger;


int enterchoice();
void add_trains();
void view_trains();
void view_all_booking();
char* accept_mob_no();
int* get_ticket_no(char *);
void view_all_tickets(char *,int *);
void view_bookings(char *);
int cancel_ticket(int);
int cancel_train(char *);

//fn's for booking ticket of passenger
Passenger* get_passenger_details();
int check_train_no(char *);
int get_booked_ticket_count(char *,char);
int last_ticket_no();
int book_ticket(Passenger);
int check_mob_no(char *);

//fn based on view ticket
int accept_ticket_no();
void view_ticket(int);

//fn for view ticket of paricular train
char* accept_train_no();
int check_train_no(char *);

#endif // RLYRES_H_INCLUDED
