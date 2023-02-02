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

int total, food_choice,n;
void hotels(int hotel_choice)
{
    total = 0;

    FILE *abc;
            abc = fopen("cart.txt", "a+");
            if (abc == 0){
                printf("Error!");
                    exit(1);
            }else{
                fprintf(abc,"\n\t\t\t From %s ",m[hotel_choice].hotel);
                fclose(abc);
            }

    while (1) {

        system ("COLOR 06");
        printf("\n\n\t\t\t\t\t\t\t===== List of foods available in %s =====\n\n",m[hotel_choice].hotel);delay(50);
        printf("\t\t\t\t\t\t\t1) %s\t\t\tRs: %d /=\n",m[hotel_choice].food_one, m[hotel_choice].price_one);delay(50);
        printf("\t\t\t\t\t\t\t2) %s\t\t\tRs: %d /=\n",m[hotel_choice].food_two, m[hotel_choice].price_two);delay(50);
        printf("\t\t\t\t\t\t\t3) %s\t\t\tRs: %d /=\n",m[hotel_choice].food_three, m[hotel_choice].price_three);delay(50);
        printf("\n\t\t\t\t\t\t\t4) Cart\n");delay(50);
        printf("\t\t\t\t\t\t\t5) Exit\n\n\n");
        printf("\t\t\t\t\t\t\tEnter your choice\t\t  :\t\t");
        scanf("%d", &food_choice);

        if (food_choice == 1) {
            printf("\t\t\t\t\t\t\tPlease Enter the Count of %s\t\t",m[hotel_choice].food_one);
            scanf("%d", &n);
            total = total + (n * m[hotel_choice].price_one);
            printf("\n\t\t\t\t\t\t\tYour Total Order Amount is\t %d\n", total);

            FILE *abc;
            abc = fopen("cart.txt", "a+");
            if (abc == 0){
                printf("Error!");
                    exit(1);
            }else{
                fprintf(abc,"\n %d * %s =\t\t\t\t %d",n,m[hotel_choice].food_one,(n * m[hotel_choice].price_one) );
                fclose(abc);
            }

        }
        else if (food_choice == 2) {
            printf("\t\t\t\t\t\t\tPlease Enter the Count of %s\t\t",m[hotel_choice].food_two);
            scanf("%d", &n);
            total = total + (n * m[hotel_choice].price_two);
            printf("\n\t\t\t\t\t\t\tYour Total Order Amount is\t %d\n", total);

            FILE *abc;
            abc = fopen("cart.txt", "a+");
            if (abc == 0){
                printf("Error!");
                    exit(1);
            }else{
                fprintf(abc,"\n %d * %s =\t\t\t\t %d",n,m[hotel_choice].food_two,(n * m[hotel_choice].price_two) );
                fclose(abc);
            }


        }
        else if (food_choice == 3) {
            printf("\t\t\t\t\t\t\tPlease Enter the Count of %s\t\t", m[hotel_choice].food_three);
            scanf("%d", &n);
            total = total + (n * m[hotel_choice].price_three);
            printf("\n\t\t\t\t\t\t\tYour Total Order Amount is\t %d\n", total);

            FILE *abc;
            abc = fopen("cart.txt", "a+");
            if (abc == 0){
                printf("Error!");
                    exit(1);
            }else{
                fprintf(abc,"\n %d * %s =\t\t\t\t %d",n,m[hotel_choice].food_three,(n * m[hotel_choice].price_three) );
                fclose(abc);
            }

        }

        else if (food_choice == 4) {
            cart();
        }
        else if (food_choice == 5) {
            search_hotels();
        }
        else {
            printf("\t\t\t\t\t\t\tPlease Enter the valid Choice\n\n");delay(1500);
        }
    }
}
