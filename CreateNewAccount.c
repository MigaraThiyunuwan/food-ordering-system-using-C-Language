#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

struct details {
    char name[100];
    char pw[100];
    char mail[100];
    char phnNum[10];
};

// Structure to store names of the hotels and their food details
struct hotels {
    char hotel[100];
    char food_one[20];
    char food_two[20];
    char food_three[20];
    int price_one, price_two, price_three;
};

struct details s[100];
struct hotels m[5];
char casual_name[100], casual_pw1[100]; //character array
char casual_pw2[100], casual_mail[100]; //to save details
char casual_phnNum[100];                //that user enter first
int x,y,j;
int k = 1, i, count = 0, upper_case = 0;
int lower_case = 0, special = 0, numbers = 0;
int success = 0, x, choice;
char mailcopy[100][100];    // character array
char pwcopy[100][100];      // to copy previous
char namecopy[100][100];    // users' detaiils
char phnNumcopy[100][100];  // from txt files

void createNewAccount()
{
    system ("COLOR 04");
    printf("\n\t\t\t\t\t                                ------------------\n");delay(50);
    printf("\t\t\t\t\t                                Create New Account\n");delay(50);
    printf("\t\t\t\t\t                                ------------------\n");delay(50);

    printf("\n\t\t\t\t* Enter your first name only..\n\t\t\t\t* Enter valid Email address..");delay(50);
    printf("\n\t\t\t\t* Your password must contain one uppercase, one lowercase, one number and one of these \"@ , # , & , *\"");delay(50);
    printf("\n\t\t\t\t* Your Phone number must be 10 digits..\n");delay(50);

    printf("\n\n\t\t\t\t\t\t\tEnter Your first name \t\t  :   \t");
    scanf("%s", casual_name);

    printf("\t\t\t\t\t\t\tEnter Your Email \t\t  :    \t");
    scanf("%s", casual_mail);

    printf("\t\t\t\t\t\t\tEnter password\t\t\t  :\t");
    scanf("%s", casual_pw1);

    printf("\t\t\t\t\t\t\tRe-Enter password\t\t  :\t");
    scanf("%s", casual_pw2);

    printf("\t\t\t\t\t\t\tEnter Your phone Number\t\t  :\t");
    scanf("%s", casual_phnNum);

    x = validate();
    if (x == 1)
        checking_account();
}

int validate()
{
    for (i = 0; casual_name[i] != '\0'; i++) {
        if (!((casual_name[i] >= 'a' && casual_name[i] <= 'z') || (casual_name[i] >= 'A' && casual_name[i] <= 'Z'))) {
            system ("COLOR 40");
            printf("\n\t\t\t\t\t\t\t !!!!!!!! Please Enter the valid Name !!!!!!!!\n");delay(1500);
            k = 0;
            break;
        }
    }
    if (k == 1) {
        count = 0;

        for (i = 0; casual_mail[i] != '\0'; i++) {
            if (casual_mail[i] == '@' || casual_mail[i] == '.')
                count++;
        }
        if (count >= 2 && strlen(casual_mail) >= 5) {

            if (!strcmp(casual_pw1, casual_pw2)) {

                if (strlen(casual_pw1) >= 8 && strlen(casual_pw1) <= 12) {
                    upper_case = 0;
                    lower_case = 0;
                    numbers = 0;
                    special = 0;

                    for (i = 0; casual_pw1[i] != '\0'; i++) {
                        if (casual_pw1[i] >= 'A' && casual_pw1[i] <= 'Z'){
                            upper_case++;
                        }
                        else if (casual_pw1[i] >= 'a' && casual_pw1[i] <= 'z'){
                            lower_case++;
                        }
                        else if (casual_pw1[i] >= '0' && casual_pw1[i] <= '9'){
                            numbers++;
                        }
                        else if (casual_pw1[i] == '@' || casual_pw1[i] == '&' || casual_pw1[i] == '#' || casual_pw1[i] == '*'){
                            special++;
                        }
                    }
                    if (upper_case >= 1 && lower_case >= 1 && numbers >= 1 && special >= 1) {

                        if (strlen(casual_phnNum) == 10) {

                            return 1;
                        }

                        else {
                                system ("COLOR 40");
                                printf("\n\n\t\t\t\t\t\t\t!!!!!!!! Please Enter the 10 digit phone number !!!!!!!!\n\n");delay(1500);
                                return 0;
                        }
                    }

                    else {
                            system ("COLOR 40");
                            printf("\n\n\t\t\t\t\t\t\t!!!!!!!! Please Enter the strong password, Your password must contain \n\t\t\t\t\t\t\tat least one uppercase, ");
                            printf("Lowercase, Number and special character !!!!!!!!\n\n");delay(1500);
                            return 0;
                    }
                }
                else {
                        system ("COLOR 40");
                        printf("\n\t\t\t\t\t\t\t!!!!!!!! Your password is not valid!\n\t\t\t\t\t\t\tLength must between 8 to 12 !!!!!!!!\n\n");delay(1500);
                        return 0;
                }
            }
            else {
                    system ("COLOR 40");
                    printf("\n\t\t\t\t\t\t\t!!!!!!!! password Mismatch !!!!!!!!\n\n");delay(1500);
                    return 0;
            }
        }
        else {
                system ("COLOR 40");
                printf("\n\t\t\t\t\t\t\t!!!!!!!! Please Enter Valid E-Mail !!!!!!!!\n\n");delay(1500);
                return 0;
        }
    }
}

// function to Check whether user already has an account?
void checking_account()
{
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

       for (i = 0; i < 100; i++) {

        if (!(strcmp(casual_mail, mailcopy[i]) && strcmp(casual_pw1, pwcopy[i]))){

        system ("COLOR 40");
            printf("\n\n\t\t\t\t\t\t\t!!!!!!!! Account Already Existed. Please Login !!!!!!!!\n\n");delay(1500);
            main();
            break;

       }

    }

    if (i == 100) {

        strcpy(s[j].name, casual_name);
        strcpy(s[j].pw, casual_pw1);
        strcpy(s[j].mail, casual_mail);
        strcpy(s[j].phnNum, casual_phnNum);

    FILE *fptr;
    fptr = fopen("emails.txt", "a+");

    if (fptr == 0){
        printf("Error!");
        exit(1);
    }else{
        fprintf(fptr,"%s\n",s[j].mail);
        fclose(fptr);
    }
    FILE *ptr;
    ptr = fopen("passwords.txt", "a+");

    if (ptr == 0){
        printf("Error!");
        exit(1);
    }else{
        fprintf(ptr,"%s\n",s[j].pw);
        fclose(ptr);
    }
    FILE *xyz;
    xyz = fopen("names.txt", "a+");

    if (xyz == 0){
        printf("Error!");
        exit(1);
    }else{
        fprintf(xyz,"%s\n",s[j].name);
        fclose(xyz);
    }

    FILE *pqr;
    pqr = fopen("phoneNumbers.txt", "a+");

    if (pqr == 0){
        printf("Error!");
        exit(1);
    }else{
        fprintf(pqr,"%s\n",s[j].phnNum);
        fclose(pqr);
    }

    j++;

     FILE *mal;
    mal = fopen("jfile.txt", "r+");

    if (mal == 0){
        printf("Error!");
        exit(1);
    }else{
        fprintf(mal,"%d", j);
    }
    fclose(mal);

        system("cls");
        printf("\n\n\n===============================================================  Account Created Successfully !!  ====================================================================\n\n");
   }
}
