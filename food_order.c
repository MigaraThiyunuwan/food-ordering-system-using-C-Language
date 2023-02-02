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

int hotel_id,n,total;

void food_order(int food)
{
    if (food >= 1 && food <= 3)
        hotel_id = 1;
    else if (food >= 4 && food <= 6)
        hotel_id = 2;
    else
        hotel_id = 3;
    if ((food % 3) == 1) {
        printf("\t\t\t\t\t\t\tPlease Enter the Count of %s\t  :\t\t", m[hotel_id].food_one);
        scanf("%d", &n);
        total = total + (n * m[hotel_id].price_one);
            printf("\n\t\t\t\t\t\t\tYour Total Order Amount is\t %d\n", total);

            FILE *abc;
            abc = fopen("cart.txt", "a+");
            if (abc == 0){
                printf("Error!");
                    exit(1);
            }else{
                fprintf(abc,"\n %d * %s =\t\t\t\t %d",n,m[hotel_id].food_one,(n * m[hotel_id].price_one) );
                fclose(abc);
            }

    }
    else if ((food % 3) == 2) {
        printf("\t\t\t\t\t\t\tPlease Enter the Count of %s\t  :\t\t", m[hotel_id].food_two);
        scanf("%d", &n);
        total = total + (n * m[hotel_id].price_two);
            printf("\n\t\t\t\t\t\t\tYour Total Order Amount is\t %d\n", total);

            FILE *abc;
            abc = fopen("cart.txt", "a+");
            if (abc == 0){
                printf("Error!");
                    exit(1);
            }else{
                fprintf(abc,"\n %d * %s =\t\t\t\t %d",n,m[hotel_id].food_two,(n * m[hotel_id].price_two) );
                fclose(abc);
            }


    }
    else if ((food % 3) == 0) {
        printf("\t\t\t\t\t\t\tPlease Enter the Count of %s\t  :\t\t", m[hotel_id].food_three);
        scanf("%d", &n);
        total = total + (n * m[hotel_id].price_three);
            printf("\n\t\t\t\t\t\t\tYour Total Order Amount is\t\t %d\n", total);

            FILE *abc;
            abc = fopen("cart.txt", "a+");
            if (abc == 0){
                printf("Error!");
                    exit(1);
            }else{
                fprintf(abc,"\n %d * %s =\t\t\t\t %d",n,m[hotel_id].food_three,(n * m[hotel_id].price_three) );
                fclose(abc);
            }

    }
}
