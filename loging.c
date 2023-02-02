#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

// function to user loging

char casual_name[100], casual_pw1[100]; //character array
char casual_pw2[100], casual_mail[100]; //to save details
char casual_phnNum[100];                //that user enter first
int y,i,c,hotel_choice, search_choice, confirm;
char mailcopy[100][100];    // character array
char pwcopy[100][100];      // to copy previous
char namecopy[100][100];    // users' detaiils
char phnNumcopy[100][100];  // from txt files
void login()
{
    system("cls");
    system ("COLOR 0C");
    printf("\n\n\t\t\t\t\t\t\t\t\t========= LOGIN =========\n\n");
    printf("\t\t\t\t\t\t\tEnter Your Email \t\t  :    \t");
    scanf("%s", casual_mail);                           // getting user details as
    printf("\t\t\t\t\t\t\tEnter password\t\t\t  :\t");
    scanf("%s", casual_pw1);                            // casual details

    // load previous users' details into character array
    FILE *fptr;
    fptr = fopen("emails.txt", "a+");
    if (fptr == 0){
        printf("Error!");
        exit(1);

    }
    for(y=0; y<100; y++){
        fscanf(fptr, "%s",mailcopy[y]);
    }
    fclose(fptr);

       FILE *ptr;
    ptr = fopen("passwords.txt", "a+");
    if (ptr == 0){
        printf("Error!");
        exit(1);
    }
    for(y=0; y<100; y++){
        fscanf(ptr, "%s",pwcopy[y]);
    }
    fclose(ptr);

    // checking whether is there an account for this mail
    for (i = 0; i < 100; i++) {

        if (!strcmp(casual_mail,mailcopy[i])) {
                c=i;
                break;
        }
    }
    if (i==100){
       system ("COLOR 40");
        printf("\t\t\t\t\t\t\t\t There is not account for this Email..\n\t\t\t\t\t\t\t\t\tPlease create new account!\n\n");delay(1500);
        main();
    }

        if (!strcmp(casual_pw1,pwcopy[c])) {

    FILE *xyz;
    xyz = fopen("names.txt", "a+");
    if (xyz == 0){
        printf("Error!");
        exit(1);

    }
    for(y=0; y<100; y++){
        fscanf(xyz, "%s",namecopy[y]);
    }
    fclose(xyz);

       FILE *pqr;
    pqr = fopen("phoneNumbers.txt", "a+");
    if (pqr == 0){
        printf("Error!");
        exit(1);

    }
    for(y=0; y<100; y++){
        fscanf(pqr, "%s",phnNumcopy[y]);
    }
    fclose(pqr);

                system("cls");
                system ("COLOR 09");
                printf("\n\n\t\t\t\t\t\t\t\t\t      Welcome %s!\n",namecopy[i]);delay(100);
                printf("\t\t\t\t\t\t\t\t====== You are successfully logged in ======\n\n");delay(100);
                printf("\n\t\t\t\t\t                                   ------------------\n");delay(100);
                printf("\t\t\t\t\t                                   Select your choice\n");delay(100);
                printf("\t\t\t\t\t                                   ------------------\n");delay(100);

                printf("\t\t\t\t\t\t _________________________________________ _______________________");delay(100);
                printf("\n\t\t\t\t\t\t|                                         |                       |");delay(100);
                printf("\n\t\t\t\t\t\t|    TO ORDER FOODS FROM 5 STAR HOTELS    |       Enter no 1      |");delay(100);
                printf("\n\t\t\t\t\t\t|_________________________________________|_______________________|");delay(100);
                printf("\n\t\t\t\t\t\t|                                         |                       |");delay(100);
                printf("\n\t\t\t\t\t\t|      TO ORDER YOUR FAVOURITE FOODS      |       Enter no 2      |");delay(100);
                printf("\n\t\t\t\t\t\t|_________________________________________|_______________________|");delay(100);
                printf("\n\t\t\t\t\t\t|                                         |                       |");delay(100);
                printf("\n\t\t\t\t\t\t|                 EXIT                    |       Enter no 3      |");delay(100);
                printf("\n\t\t\t\t\t\t|_________________________________________|_______________________|");delay(100);

                printf("\n\n\t\t\t\t\t\t\tEnter your choice\t\t  :\t\t");
                scanf("%d", &search_choice);

                switch (search_choice) {
                case 1: {
                    search_hotels();
                    break;
                }
                case 2: {
                    search_food();
                    break;
                }
                case 3: {
                    main();
                    break;
                   // return;
                }
                default: {
                    system ("COLOR 40");
                    printf("\t\t\t\t\t\t\tPlease Enter the valid choice\n\n");delay(1500);
                    break;
                }
                }
            }

    else{
       system ("COLOR 40");
        printf("\n\n\t\t\t\t\t\t\t\tYour email and password doesn't match!\n\n");delay(1500);
        main();

    }
}
