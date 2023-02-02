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

int food,total;

void search_food()
{
    total = 0;
    hotel_define();

    while (1) {

        system ("COLOR 06");
        printf("\n\n\t\t\t\t\t\t\t==== Please choose the food ====\n\n\t\t\t\t\t\t\t1) %s\t%d/=\n", m[1].food_one, m[1].price_one);delay(50);
        printf("\t\t\t\t\t\t\t2) %s\t%d/=",m[1].food_two, m[1].price_two);delay(50);
        printf("\n\t\t\t\t\t\t\t3) %s\t%d/=\n", m[1].food_three, m[1].price_three);delay(50);
        printf("\t\t\t\t\t\t\t4) %s\t%d/=\n", m[2].food_one, m[2].price_one);delay(50);
        printf("\t\t\t\t\t\t\t5) %s\t%d/=\n",m[2].food_two, m[2].price_two);delay(50);
        printf("\t\t\t\t\t\t\t6) %s\t%d/=\n", m[2].food_three, m[2].price_three);delay(50);
        printf("\t\t\t\t\t\t\t7) %s\t%d/=\n",m[3].food_one, m[3].price_one);delay(50);
        printf("\t\t\t\t\t\t\t8) %s\t%d/=\n", m[3].food_two, m[3].price_two);delay(50);
        printf("\t\t\t\t\t\t\t9) %s\t%d/=\n\n",m[3].food_three, m[3].price_three);delay(50);
        printf("\t\t\t\t\t\t\t10) Cart\n");delay(50);
        printf("\t\t\t\t\t\t\t11) Exit");delay(50);
        printf("\n\t\t\t\t\t\t\tPlease Enter Your Choice\t\t\t  :\t\t");
        scanf("%d", &food);
        if (food > 11 || food == 0) {
            printf("\t\t\t\t\t\t\tPlease Enter the valid choice\n\n");delay(1500);
            search_food();
        }

        else if (food == 10){
            cart();
        }
        else if (food == 11){
            main();
        }
        else{
            food_order(food);
        }
    }
}

