
#include<stdio.h>
#include"conio2.h"
#include<ctype.h>
#include<string.h>
//#include<conio.h>
#include"rlyres.h"
#include<malloc.h>

int enterchoice()
{
    clrscr();
    int choice,i;
    //textbackground(WHITE);
    textcolor(RED);
    gotoxy(20,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("-");
    printf("\nselect an option\n1-View Trains\n2-Book tickets\n3-View ticket\n4-search ticket no\n");
    printf("5-view all bookings\n6-view train bookings\n7-cancel ticket\n8-Cancel train\n9-Quit");
    printf("\n\nEnter choice: ");
    fflush(stdin);
    scanf("%d",&choice);
    return choice;
}


void add_trains()
{
    FILE *fp;
    fp=fopen("d:\\myproject\\alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[4]={
            {"123","BPL","GWA",2100,1500},
            {"546","BPL","DEL",3500,2240},
            {"345","HBJ","AGR",1560,1135},
            {"896","HBJ","MUM",4500,3360}
        };

        fp=fopen("d:\\myproject\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        printf("Train details saved successfully\n");
        getch();
        fclose(fp);
    }

  /*  else
    {
        printf("file already present\n");
        getch();
        fclose(fp);
    }   */

}


void view_trains()
{
    int i;
    textcolor(LIGHTGREEN);
    printf("TRAIN NO\tFROM\tTO\tFIRST Ac FAIR\t2nd AC FAIR\n");
    for(i=1;i<=80;i++)
    {
        printf("-");
    }
    FILE *fp;
    fp=fopen("d:\\myproject\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        printf("\n%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
    }
    printf("\n\n\n");
    fclose(fp);
}

int check_train_no(char *p)
{
    FILE *fp;
    Train tr;
    fp=fopen("d:\\myproject\\alltrains.dat","rb");
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,p)==0)
        {
            return 1;
        }
    }
    return 0;
}

Passenger* get_passenger_details()
{
    int valid;
    clrscr();
    gotoxy(45,1);
    textcolor(LIGHTGREEN);
    printf("press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter passenger name:");
//    static Passenger psn;
    Passenger psn;
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,19);
        printf("Reservation cancel");
        getch();
        return NULL;
    }
    gotoxy(1,2);
    textcolor(YELLOW);
    printf("Enter gender(M/F):");
    do
    {
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(1,19);
            printf("Reservation cancel");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        if(psn.gender!='M'&&psn.gender!='F')
        {
            textcolor(LIGHTRED);
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(1,19);
            printf("Invalid gender!!! Gender should be M or F (uppercase)");
            getch();
            gotoxy(1,19);
            printf("\t\t\t\t\t\t\t");
            gotoxy(14,2);
            printf(" \b");
            textcolor(YELLOW);
        }
    }while(psn.gender!='M'&&psn.gender!='F');

    gotoxy(1,3);
    //char train_no[20];
    textcolor(YELLOW);
    printf("Enter train no:");
    do
    {
        fflush(stdin);
        fgets(psn.train_no,20,stdin);
        char *pos;
        pos=strchr(psn.train_no,'\n');
        *pos='\0';
        if(strcmp(psn.train_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,19);
            printf("Reservation cancel");
            getch();
            return NULL;
        }

        valid=check_train_no(psn.train_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,19);
            printf("\t\t\t\t\t\t");
            gotoxy(1,19);
            printf("Invalid Train no!!");
            getch();
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(16,3);
            printf("\t\t\t\t");
            gotoxy(16,3);
            textcolor(YELLOW);
        }
    }while(valid!=1);

    gotoxy(1,4);
    printf("Enter travel class (First Ac-F,Second AC-S):");
    do
    {
        fflush(stdin);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(1,19);
            printf("Reservation cancel");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        if(psn.p_class!='F'&&psn.p_class!='S')
        {
            textcolor(LIGHTRED);
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(1,19);
            printf("Invalid class no!!! class should be F or S (uppercase)");
            getch();
            gotoxy(1,19);
            printf("\t\t\t\t\t\t\t\t\t");
            gotoxy(45,4);
            printf(" \b");
            textcolor(YELLOW);
        }
    }while(psn.p_class!='F'&&psn.p_class!='S');

    gotoxy(1,5);
    textcolor(YELLOW);
    printf("Enter address:");
    fflush(stdin);
    fgets(psn.address,30,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,19);
        printf("Reservation cancel");
        getch();
        return NULL;
    }
    gotoxy(1,6);
    printf("Enter age:");
    do
    {
        fflush(stdin);
        scanf("%d",&psn.age);
        if(psn.age=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(1,19);
            printf("Reservation cancel");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        if(psn.age<0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(1,19);
            printf("Invalid age...");
            getch();
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(11,6);
            printf("\t\t\t");
            gotoxy(11,6);
            textcolor(YELLOW);
        }
    }while(psn.age<0);

    gotoxy(1,7);
    textcolor(YELLOW);
    printf("Enter mobile no:");
    do
    {
        fflush(stdin);
        scanf("%s",psn.mob_no);
        fflush(stdin);
        //fgets(psn.mob_no,10,stdin);
        //pos=strchr(psn.mob_no,'\n');
        //*pos='\0';

        if(strcmp(psn.mob_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(1,19);
            printf("Reservation cancel");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        valid=check_mob_no(psn.mob_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(1,19);
            printf("Invalid mob no...");
            getch();
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(17,7);
            printf("\t\t\t");
            gotoxy(17,7);
            textcolor(YELLOW);
        }

    }while(valid==0);
    return &psn;
}


int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
        return 0;

    if((*p_mob)=='6'||*(p_mob)=='7'||(*p_mob)=='8'||(*p_mob)=='9')
    {

        while(*p_mob!='\0')
        {
            if(isdigit(*p_mob)==0)
                return 0;
            p_mob++;
        }
        return 1;
    }
    else  return 0;
}


int get_booked_ticket_count(char *train_no,char tc)
{
    FILE *fp=fopen("d:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
        return 0;

    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0 && pr.p_class==tc)
            count++;
    }
    fclose(fp);
    return count;
}

int last_ticket_no()
{
    FILE *fp=fopen("d:\\myproject\\allbookings.dat","rb");

    if(fp==NULL)
        return 0;

    Passenger pr;
    fseek(fp,(-1)*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticket_no;
}



int book_ticket(Passenger p)
{
    int ticket_count;
    ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count>=2)
    {
        textcolor(LIGHTRED);
        printf("all seats are full in train no %s in %c...please try booking in other class",p.train_no,p.p_class);
        return  -1;
    }
    p.ticket_no=last_ticket_no()+1;

    FILE *fp=fopen("d:\\myproject\\allbookings.dat","ab");
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);

    return p.ticket_no;
}



int accept_ticket_no()
{
    clrscr();
    int ticket_no;
    gotoxy(45,1);
    textcolor(LIGHTGREEN);
    printf("press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("enter your ticket no:");
    do
    {
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,18);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,18);
            printf("Cancelling input...!");
            textcolor(WHITE);
            printf("\npress any key");
            getch();
            textcolor(YELLOW);
            return 0;
         }

        if(ticket_no<0)
        {
            gotoxy(1,19);
            textcolor(LIGHTRED);
            printf("ticket no should be positive number...");
            getch();
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(22,1);
            printf("\t");
            gotoxy(22,1);
            textcolor(YELLOW);
        }
    }while(ticket_no<0);

    return ticket_no;
}


void view_ticket(int ticket_no)
{
    //int flag=0;
    Passenger p;
    FILE *fp=fopen("D:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nno bookings done yet");
        getch();
        return;
    }

    while(fread(&p,sizeof(p),1,fp)==1)
    {
        if(p.ticket_no==ticket_no)
        {
            clrscr();
            textcolor(LIGHTGREEN);
            printf("Passenger details are:\nTicket no=%d\nname=%s\nAge=%d\nGender=%c\nmobile no=%s\nAddress=%s\nTrain no=%s\nClass=%c",p.ticket_no,p.p_name,p.age,p.gender,p.mob_no,p.address,p.train_no,p.p_class);
            printf("\n\n");
            textcolor(WHITE);
            printf("\n\npress any key for main menu");
            getch();
            fclose(fp);
            return;
        }
    }
        textcolor(LIGHTGREEN);
        printf("\nno details found for ticket no %d",ticket_no);
        textcolor(WHITE);
        printf("\n\npress any key for main menu");
        getch();
        textcolor(YELLOW);
        fclose(fp);

}


int cancel_ticket(int ticket)
{
    int found=0,check=0;
    FILE *fp1=fopen("d:\\myproject\\allbookings.dat","rb");
    if(fp1==NULL)
    {
        clrscr();
        textcolor(LIGHTRED);
        printf("no bookings done yet");
        getch();
        return -1;
    }
    FILE *fp2=fopen("d:\\myproject\\temp.dat","wb+");
    Passenger p;
    while(fread(&p,sizeof(p),1,fp1)==1)
    {
        if(p.ticket_no==ticket)
        {
            found=1;
            continue;
        }
        fwrite(&p,sizeof(p),1,fp2);
        check=1;
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("d:\\myproject\\temp.dat");
    }

    else if(check==0)
    {
        remove("d:\\myproject\\allbookings.dat");
        remove("d:\\myproject\\temp.dat");
    }

    else
    {
        remove("d:\\myproject\\allbookings.dat");
        rename("d:\\myproject\\temp.dat","d:\\myproject\\allbookings.dat");
    }
    return found;
}

char* accept_mob_no()
{
    int valid=0;
    static char mob_no[11];
    textcolor(LIGHTGREEN);
    gotoxy(45,1);
    printf("press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("enter mobile no:");
    do
    {
        fflush(stdin);
        scanf("%s",mob_no);
        if(strcmp(mob_no,"0")==0)
        {
            gotoxy(1,18);
            textcolor(LIGHTRED);
            printf("cancelling input!!");
            textcolor(WHITE);
            printf("\npress any key...");
            getch();
            gotoxy(1,18);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,19);
            printf("\t\t\t\t\t\t");
            return NULL;
        }
        valid=check_mob_no(mob_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(1,19);
            printf("Invalid mob no...");
            getch();
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(17,1);
            printf("\t\t\t");
            gotoxy(17,1);
            textcolor(YELLOW);
        }

    }while(valid==0);
    return mob_no;

}

int* get_ticket_no(char *p_mob_no)
{
    int count=0;
    Passenger pr;
    FILE *fp=fopen("d:\\myproject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        clrscr();
        textcolor(LIGHTRED);
        printf("no bookings done yet");
        getch();
        textcolor(YELLOW);
        return NULL;
    }

    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
            count++;
    }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int i=0;
    int *p=(int*)malloc((count+1)*sizeof(int));
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            *(p+i)=pr.ticket_no;
            i++;
        }
    }
    *(p+i)=-1;
    fclose(fp);
    return p;
}


void view_all_tickets(char *mob_no,int *pticket_no)
{
    if(pticket_no==NULL)
    {
        clrscr();
        textcolor(LIGHTRED);
        printf("no ticket is booked of this mobile number %s",mob_no);
        getch();
        return;
    }
    textcolor(LIGHTGREEN);
    clrscr();
    printf("ALL tickets for mobile no %s are shown below",mob_no);
    int i;
    printf("\n\nTICKET NO\n");
    printf("-----");
    for(i=0;*(pticket_no+i)!=-1;i++)
    {
        printf("\n%d",*(pticket_no+i));
    }
    textcolor(WHITE);
    printf("\npress any key to go to main menu");
    getch();
    textcolor(YELLOW);
    free(pticket_no);
    getch();
}



int cancel_train(char *ptrain_no)
{
    int flag=0;
    FILE *fp=fopen("d:\\myproject\\allbookings.dat","rb");
    FILE *tempfp=fopen("d:\\myproject\\temp1.dat","wb");

    Passenger pr;

    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,ptrain_no)==0)
        {
            flag++;
            continue;
        }
        fwrite(&pr,sizeof(pr),1,tempfp);

    }

     fclose(fp);
     fclose(tempfp);

    if(flag!=0)
    {
        remove("d:\\myproject\\allbookings.dat");
        rename("d:\\myproject\\temp1.dat","d:\\myproject\\allbookings.dat");
        return 0;
    }
    else
        remove("d:\\myproject\\temp1.dat");

    return 1;
}


char* accept_train_no()
{
    static char train_no[10];
    int valid;
    gotoxy(45,1);
    textcolor(LIGHTGREEN);
    printf("press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter train no:");
    do
    {
        fflush(stdin);
        fgets(train_no,10,stdin);
        char *pos;
        pos=strchr(train_no,'\n');
        *pos='\0';

        if(strcmp(train_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,18);
            printf("cancelling input!!");
            textcolor(WHITE);
            printf("\npress any key...");
            getch();
            return NULL;
        }

        valid=check_train_no(train_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,19);
            printf("\t\t\t\t\t\t");
            gotoxy(1,19);
            printf("Invalid Train no!!");
            getch();
            gotoxy(1,19);
            printf("\t\t\t\t\t");
            gotoxy(16,1);
            printf("\t\t\t\t");
            gotoxy(16,1);
            textcolor(YELLOW);
        }
    }while(valid!=1);

 return &train_no;
}


void view_bookings(char *p_train_no)
{
    clrscr();
    int found=0,i;
    Passenger pr;
    FILE *fp=fopen("d:\\myproject\\allbookings.dat","rb");
    clrscr();
    textcolor(LIGHTGREEN);
    printf("tickets for train no %s is below:",p_train_no);
    printf("\n\n\nticket no   class  name\t\t   gender  age  mobile no\n");
    for(i=1;i<=80;i++)
        printf("-");

    int row=6;
    printf("\n");
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,p_train_no)==0)
        {
            printf("%d\t     %c\t   %s",pr.ticket_no,pr.p_class,pr.p_name);
            gotoxy(38,row++);
            printf("%c\t   %d\t %s\n",pr.gender,pr.age,pr.mob_no);
            found=1;
        }
    }

    if(!found)
    {
        clrscr();
        textcolor(LIGHTRED);
        printf("\n There is 0 booking  for train no %s",p_train_no);

    }

    textcolor(WHITE);
    printf("\n\n\npress any key to go back to main menu");
    getch();
    textcolor(YELLOW);
    fclose(fp);
}


void view_all_booking()
{
    clrscr();
    int i;
    Passenger pr;
    FILE *fp=fopen("d:\\myproject\\allbookings.dat","rb");
    clrscr();
    textcolor(LIGHTGREEN);
    printf("tickets for all the trains are below:");
    printf("\n\n\nTic No  class  Train no  name\t\t\t   gender  age  mobile no\n");

    for(i=1;i<=80;i++)
        printf("-");

    int row=6;
    printf("\n");
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        printf("%d\t %c\t%s\t %s",pr.ticket_no,pr.p_class,pr.train_no,pr.p_name);
        gotoxy(55,row++);
        printf("%c\t   %d\t %s\n",pr.gender,pr.age,pr.mob_no);
    }

    textcolor(WHITE);
    printf("\n\n\npress any key to go back to main menu");
    getch();
    textcolor(YELLOW);
    fclose(fp);
}
