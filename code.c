#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<time.h>

void delay();                   // FOR DELAYING THE LOGIN
void header();                  // MAIN MENU OF LOGIN PORTAL
void start();                   // CALL HEADER AND CONTINUE FURHTER
void newacc();                  // CREATE NEW ACCOUNT
void trans();                   // DEPOSIT OR WITHDRAW MONEY
void view();                    // VIEW ACCOUNT DETAILS
void update();                  // UPDATE ACCOUNT DETAILS
void dlt();                     // DELETE ACCOUNT
void cont();                    // CONTINUE TO MAIN MENU
void acc();

void id(long long int *);   // CHECK VALIDITY OF CITIZENSHIP NUMBER
void mob(long long int *);  // CHECK VALIDITY OF MOBILE NUMBER
void age(int *);            // CHECK VALIDITY OF AGE
void bal(double *);         // CHECK VALIDITY OF BALANCE

struct date
{
    int d;
    int m;
    int y;
};

struct account
{
    long long int acno;       // ACCOUNT NUMBER
    char name[20];            // NAME
    int age;                  // AGE
    char add[50];             // ADDRESS
    char so[50];              // FATHER'S NAME
    long long int mob;        // MOBILE NUMBER
    long long int id;         // CITIZENSHIP NUMBER
    char dob[20];             // DATE OF BIRTH
    struct date deposit;      // LAST DEPOSIT DATE
    struct date withdrawal;   // LAST DATE OF WITHDRAWAL
    struct date open;         // ACCOUNT OPENING DATE
    char type[10];            // ACCOUNT TYPE
    double bal;               // BALANCE
};

int pin; // PIN FOR LOGIN

int main()

{
    int i=3;
    system("COLOR 80");        // SET COLOR OF LOGIN PORTAL AND TEXT
    printf("ENTER YOUR PIN\n");
    scanf("%d", &pin);
if(pin==1998)
{
    system("cls");
    printf("\n\n\n\n\t\tLOADING . ");
    //delay();
    printf(" . ");
    //delay();
    printf(" . ");
    //delay();
    start();
}

else
{
    while(--i)
    {
    system("cls");
    printf("ENTERED PIN IS WRONG %d ATTEMPT REMAINING\n",i);
    printf("\nENTER YOUR PIN\n");
    scanf("%d", &pin);
    if(pin==1998)
    {
    system("cls");
    printf("\n\n\n\n\t\tLOADING . ");
    delay();
    printf(" . ");
    delay();
    printf(" . ");
    delay();
    start();
    }
    if(i==1)
    {
        system("cls");
        printf("\n\n\t\tATTEMPTS EXCEEDED\n\n");
        exit(1);
    }
    }
}

return 0;
}


void delay()
{
    int i;
    for(i=0;i<1000000000;i++)
    {

    }
}


void header()
{

   system("cls");

   int i;

   printf("\n\n\n");

   for(i=0;i<10;i++)
   printf(" ");

   for(i=0;i<10;i++)
   printf("*");

   printf("WELCOME TO BANKING PORTAL");

   for(i=0;i<10;i++)
   printf("*");

   printf("\n\n");
   printf(" \n\nPRESS!\n\n");
   printf("      1. CREATE NEW ACCOUNT\n\n");
   printf("      2. DEPOSIT OR WITHDRAWAL MONEY\n\n");
   printf("      3. UPDATE ACCOUNT DETAILS\n\n");
   printf("      4. VIEW ACCOUNT DETAILS\n\n");
   printf("      5. VIEW CUSTOMESRS' DETAILS\n\n");
   printf("      6. CLOSE ACCOUNT\n\n");
   printf("         ANY OTHER KEY TO LOGOUT\n\n");

}


void start()
{

   int ch;
   header();
   scanf("%d", &ch);
   switch(ch)
   {
   case 1: // NEW ACCOUNT
                newacc();
                break;

   case 2: // TRANSACTION
                trans();
                break;

   case 3: // UPDATE
                update();
                break;

   case 4: // VIEW ACCOUNT DETAILS
               acc();
               break;

   case 5: // VIEW CUSTOMERS' LIST
                view();
                break;

   case 6: // DELETE ACCOUNT
                dlt();
                break;

  default: // LOGOUT
                system("cls");
                printf("\n\n\t\t\t\t!! THANK YOU FOR BANKING WITH US !!\n\n");
                exit(1);
    }

}


void cont()
{
    int ch;
    printf("\n\n\nPRESS!\n\n");
    printf("\t1. FOR MENU\n");
    printf("\t   ANY OTHER KEY TO LOGOUT\n");
    printf("\n");
    scanf("%d", &ch);
    if(ch==1)
    {

    system("cls");
    start();
    }
    else
    {
        system("cls");
        printf("\n\n\t\t\t\t!! THANK YOU FOR BANKING WITH US !!\n\n");
        exit(1);
    }
}


void newacc()
{
    time_t t=time(NULL);
    struct tm tm = *localtime(&t);


    system("cls");

    FILE *fp1;

    long long int c=34426350000;
    struct account a1,a2;
    printf("\n\n   Enter Name - ");
    fflush(stdin);
    scanf("%[^\n]%*c",a1.name);
    printf("   Enter Age - ");
    scanf("%d", &a1.age);
    age(&(a1.age));
    printf("   Enter Date Of Birth(dd/mm/yyyy) - ");
    fflush(stdin);
    scanf("%[^\n]%*c", a1.dob);
    printf("   Enter Citizenship Number - ");
    scanf("%lld", &a1.id);
    id(&(a1.id));
    printf("   Enter Mobile Number - ");
    scanf("%lld", &a1.mob);
    mob(&(a1.mob));
    fflush(stdin);
    printf("   Enter Father's Name - ");
    scanf("%[^\n]%*c", a1.so);
    printf("   Enter Address - ");
    scanf("%[^\n]%*c", a1.add);
    fflush(stdin);
    printf("   Enter Your Account Type[SAVINGS / FIXED] - ");
    scanf("%[^\n]%*c", &a1.type);
    printf("   Enter Amount to Deposit [Minimum 1000] - ");
    scanf("%lf", &a1.bal);
    bal(&(a1.bal));


   fp1=fopen("cs1.txt", "r");

    while(fread(&a2,sizeof(struct account),1,fp1))
    {
        if(a1.id == a2.id)
        {
            system("cls");
            printf("\n\n\tAccount Already Exist\n\n");
            cont();
        }
        c=a2.acno;
    }

    fclose(fp1);
    a1.acno=c+1;

    a1.open.d=tm.tm_mday;
    a1.open.m=tm.tm_mon+1;
    a1.open.y=tm.tm_year+1900;

    a1.deposit.d=tm.tm_mday;
    a1.deposit.m=tm.tm_mon+1;
    a1.deposit.y=tm.tm_year+1900;

    a1.withdrawal.d=0;
    a1.withdrawal.m=0;
    a1.withdrawal.y=0;

    printf("\n\n\t\t......PROCESSING......");

    //delay();



    system("cls");
    printf("\n\n\t\t!!CONGRATULATIONS!! ACCOUNT CREATED\n\n");
    printf("\t\t    ACCOUNT NUMBER : %lld \n", a1.acno);

    fp1=fopen("cs1.txt", "a");
    fwrite(&a1, sizeof( struct account), 1, fp1);
    fclose(fp1);

    cont();
}


void view()
{

   system("cls");

   FILE *fp1;
   fp1=fopen("cs1.txt","r");

    if(fp1==NULL)
    printf("NO LIST FOUND\n");

    else
    {

     struct account a2;
     printf("\t\tCUSTOMERS' DETAILS\n\n");
     printf("**************************************************");
     while(fread(&a2,sizeof(struct account), 1, fp1))
     {
     printf("\n\nPERSONAL DETAILS\n\n");
     printf("NAME - %s\n", a2.name);
     printf("AGE - %d\n", a2.age);
     printf("FATHER'S NAME - %s\n",a2.so);
     printf("DATE OF BIRTH - %s\n", a2.dob);
     printf("CITIZENSHIP NUMBER - %lld\n",a2.id);
     printf("MOBILE NUMBER - %lld\n", a2.mob);
     printf("ADDRESS - %s\n\n", a2.add);
     printf("BANKING DETAILS\n\n");
     printf("ACCOUNT NUMBER - %lld\n", a2.acno);
     printf("ACCOUNT TYPE - %s\n", a2.type);
     printf("BALANCE - %lf\n", a2.bal);
     printf("OPENING DATE - %d/%d/%d\n", a2.open.d, a2.open.m,a2.open.y);
     printf("DEPOSIT DATE - %d/%d/%d\n", a2.deposit.d, a2.deposit.m, a2.deposit.y);
     printf("WITHDRAWAL DATE - %d/%d/%d\n\n", a2.withdrawal.d,a2.withdrawal.m,a2.withdrawal.y);
     printf("**************************************************");
    }
     fclose(fp1);

    }
     cont();

}


void trans()
{

   system("cls");

   FILE *fp1,*fp2;
   fp1=fopen("cs1.txt", "r");
   fp2=fopen("cs2.txt", "w");
   fclose(fp2);

  if(fp1==NULL)
    printf("NO LIST FOUND\n");

  else
   {   struct account a3,a1;
       int ch,c=0;
       long long int d;
       double a;

       printf("Enter Account Number\n");
       scanf("%lld", &d);

       while(fread(&a3, sizeof( struct account), 1, fp1))
       {
         if(d==a3.acno)
         {   system("cls");
             c++;

             printf("\n\nPress!\n\t1 Withdraw Money\n\t2 Deposit Money\n\t3 Cancel Transaction\n");
             scanf("%d", &ch);

             if(ch==1)
             {
               system("cls");

               printf("Enter Amount\n");
               scanf("%lf", &a);

               if((a3.bal-a)>=1000)
               {
                   a3.bal-=a;

                   time_t t = time(NULL);
                   struct tm tm= *localtime(&t);

                    a3.withdrawal.d= tm.tm_mday;
                    a3.withdrawal.m= tm.tm_mon+1;
                    a3.withdrawal.y= tm.tm_year+1900;

                   system("cls");
                   printf("\n\t\tWithdrawal Successful\n");
               }
               else
               {
                   system("cls");
                   printf("\n\t\tNot Enough Amount in Account\n");
                   cont();
               }
              }
           else if(ch==2)
           {   system("cls");
               printf("Enter Amount\n");
               scanf("%lf", &a);
               a3.bal+=a;

                time_t t = time(NULL);
                   struct tm tm= *localtime(&t);

                   a3.deposit.d = tm.tm_mday;
                   a3.deposit.m = tm.tm_mon+1;
                   a3.deposit.y = tm.tm_year+1900;

               system("cls");
               printf("\n\t\tAmount Successfully Deposited\n");

           }
           else
           {
                system("cls");
                cont();
           }
           break;
        }

     }

     if(!c)
     {
         system("cls");
         printf("\n\n\n\t\t\tEntered Account Number Does Not Exist\n");
     }

     fclose(fp1);
     fp1=fopen("cs1.txt", "r");

     while(fread(&a1,sizeof(struct account ),1, fp1))
     {
         if(d==a1.acno)
         {
            fp2=fopen("cs2.txt","a");
            fwrite(&a3, sizeof( struct account), 1, fp2);
            fclose(fp2);
         }
         else
         {
            fp2=fopen("cs2.txt","a");
            fwrite(&a1, sizeof( struct account), 1, fp2);
            fclose(fp2);

         }
     }
     fclose(fp1);

     struct account a2;
     fp1=fopen("cs1.txt", "w");
     fp2=fopen("cs2.txt", "r");

     while(fread(&a2, sizeof(struct account), 1, fp2))
     {
        fp1=fopen("cs1.txt","a");
        fwrite(&a2, sizeof(struct account), 1, fp1);
        fclose(fp1);
     }

     fclose(fp2);
     fp2=fopen("cs2.txt", "w");
     fclose(fp2);
     cont();
   }

}


void dlt( )
{
   int c=0;
   system("cls");

   FILE *fp1,*fp2;
   fp1=fopen("cs1.txt", "r");
   fp2=fopen("cs2.txt", "w");
   fclose(fp2);

   if(fp1==NULL)
    printf("NO LIST FOUND\n");
   else
    {
        struct account a1;
        long long int d;

        printf("Enter Account Number\n");
        scanf("%lld", &d);

        while(fread(&a1,sizeof(struct account ),1, fp1))
        {

         if(d==a1.acno)
         {  c++;
            continue;
         }
         else
         {

            fp2=fopen("cs2.txt","a");
            fwrite(&a1, sizeof( struct account), 1, fp2);
            fclose(fp2);

         }

     }

     fclose(fp1);

     struct account a2;

     fp1=fopen("cs1.txt", "w");
     fp2=fopen("cs2.txt", "r");

     while(fread(&a2, sizeof(struct account), 1, fp2))
     {

        fp1=fopen("cs1.txt","a");
        fwrite(&a2, sizeof(struct account), 1, fp1);
        fclose(fp1);

     }

     fclose(fp2);
     fp2=fopen("cs2.txt", "w");
     fclose(fp2);

     if(!c)
									   	 {
									         system("cls");
									         printf("\n\n\n\t\t\tEntered Account Number Does Not Exist\n");
									         cont();
									     }

     system("cls");

     printf("\n\n\t\tAccount Successfully Closed\n");

     cont();
    }

}


void update()
{

    system("cls");

    int c;

    FILE *fp1,*fp2;
    fp1=fopen("cs1.txt", "r");
    fp2=fopen("cs2.txt", "w");
    fclose(fp2);

    if(fp1==NULL)
    printf("NO LIST FOUND\n");
    else
        {
            struct account a1,a3;
            long long int d;

            printf("Enter Account Number\n");
            scanf("%lld", &d);

            while(fread(&a1,sizeof(struct account ),1, fp1))
            {
                    if(d==a1.acno)
                    {
						c++;
                        printf("\n\nTo Update Press!\n");
                        printf("\n\n\t\t1. Name\n\t\t2. DOB\n\t\t3. Age\n\t\t4. Citizenship Number\n\t\t5. Mobile No.\n\t\t6. Father's name\n\t\t7. Address\n\n");
                        scanf("%d", &c);
                        system("cls");

                switch(c)
                {

                    case 1: printf("Name - ");
                            fflush(stdin);
                            scanf("%[^\n]%*c", a1.name);
                            break;

                    case 2: printf("DOB - ");
                            fflush(stdin);
                            scanf("%[^\n]%*c", a1.dob);
                            break;

                    case 3: printf("AGE - ");
                            scanf("%d", &a1.age);
                            age(&(a1.age));
                            break;

                    case 4: printf("ID - ");
                            scanf("%lld", &a1.id);
                            id(&(a1.id));
                            break;

                    case 5: printf("Mobile Number - ");
                            scanf("%lld", &a1.mob);
                            mob(&(a1.mob));
                            break;

                    case 6: printf("Father's Name - ");
                            fflush(stdin);
                            scanf("%[^\n]%*c", a1.so);
                            break;

                    case 7: printf("Address - ");
                            fflush(stdin);
                            scanf("%[^\n]%*c", a1.add);

                }

            break;
                      }
               }

                        fclose(fp1);
                        fp1=fopen("cs1.txt", "r");
                        fp2=fopen("cs2.txt", "w");
                        fclose(fp2);

                        while(fread(&a3,sizeof(struct account ),1, fp1))
                            {

                                if(d==a3.acno)
                                {

                                    fp2=fopen("cs2.txt","a");
                                    fwrite(&a1, sizeof( struct account), 1, fp2);
                                    fclose(fp2);
                                }
                                else
                                {
                                    fp2=fopen("cs2.txt","a");
                                    fwrite(&a3, sizeof( struct account), 1, fp2);
                                    fclose(fp2);

                                }
                }


                                     fclose(fp1);
                                     fp1=fopen("cs1.txt","w");
                                     fclose(fp1);
                                     fp2=fopen("cs2.txt", "r");

                                     while(fread(&a3, sizeof(struct account), 1, fp2))
                                     {
                                        fp1=fopen("cs1.txt","a");
                                        fwrite(&a3, sizeof(struct account), 1, fp1);
                                        fclose(fp1);
                                     }

                                     fclose(fp2);
                                     fp2=fopen("cs2.txt", "w");
                                     fclose(fp2);
									  if(!c)
									   	 {
									         system("cls");
									         printf("\n\n\n\t\t\tEntered Account Number Does Not Exist\n");
									         cont();
									     }
									                                     system("cls");

                                     printf("\n\n\t\tAccount Successfully Updated\n");
                                     cont();
                                }

}

void acc()
{
    system("cls");

    int c=0;
    long long int a;
    struct account a1;
    printf("Enter Account Number\n");
    scanf("%lld", &a);
    FILE *fp1;
    fp1=fopen("cs1.txt", "r");

    while(fread(&a1, sizeof(struct account),1, fp1))
    {
        if(a==a1.acno)
        {   system("cls");
            c++;

     printf("**************************************************");
     printf("\n\nPERSONAL DETAILS\n\n");
     printf("NAME - %s\n", a1.name);
     printf("AGE - %d\n", a1.age);
     printf("FATHER'S NAME - %s\n",a1.so);
     printf("DATE OF BIRTH - %s\n", a1.dob);
     printf("CITIZENSHIP NUMBER - %lld\n",a1.id);
     printf("MOBILE NUMBER - %lld\n", a1.mob);
     printf("ADDRESS - %s\n\n", a1.add);
     printf("BANKING DETAILS\n\n");
     printf("ACCOUNT NUMBER - %lld\n", a1.acno);
     printf("ACCOUNT TYPE - %s\n", a1.type);
     printf("BALANCE - %lf\n", a1.bal);
     printf("OPENING DATE - %d/%d/%d\n", a1.open.d, a1.open.m,a1.open.y);
     printf("DEPOSIT DATE - %d/%d/%d\n", a1.deposit.d, a1.deposit.m, a1.deposit.y);
     printf("WITHDRAWAL DATE - %d/%d/%d\n\n", a1.withdrawal.d,a1.withdrawal.m,a1.withdrawal.y);
     printf("**************************************************");
        break;
        }
    }
    if(c==0)
    {
        printf("\n\n\t\tEntered Account Number Does Not Exist\n");

    }
    fclose(fp1);
    cont();
}


void age(int *a)
{
    if((*a)<=0)
    {
        system("cls");
        printf("\n\n\tEntered Age is Invalid\n\n");
        cont();
    }
    return ;
}

void id(long long int *a)
{

    if((*a)<=0)
    {
        system("cls");
        printf("\n\n\tEntered Id is Invalid\n\n");
        cont();
    }

}

void mob(long long int *a)
{

   long long int temp = *a;
   int i=1;

   while(temp/=10)
   i++;

   if( (*a)<=0 || i<10)
    {
        system("cls");
        printf("\n\n\tEntered Mobile Number is Invalid\n\n");
        cont();
    }



}

void bal(double *a)
{
    if((*a)<1000)
    {
        system("cls");
        printf("\n\n\tEntered Amount is less than 1000\n\n");
        cont();
    }

}
