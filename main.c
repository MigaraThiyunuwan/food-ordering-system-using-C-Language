#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "CreateNewAccount.h"
#include "loging.h"
#include "search_defineHotels.h"
#include "search_food.h"
#include "hotels.h"
#include "food_order.h"
#include "cart.h"

void delay(int milisecond){
clock_t startTime = clock();
while(clock() < (startTime + milisecond));
}
int  choice,j;
int main(){

    while (1) {
        system ("COLOR 02");
        printf("\n");
        printf("\t\t\t\t\t              ******************************************************\n");delay(100);
        printf("\t\t\t\t\t              *                       WELCOME!                     *\n");delay(100);
        printf("\t\t\t\t\t              *                                                    *\n");delay(100);
        printf("\t\t\t\t\t              *               ------------------------             *\n");delay(100);
        printf("\t\t\t\t\t              *                  ONLINE FOOD CORNER                *\n");delay(100);
        printf("\t\t\t\t\t              *               ------------------------             *\n");delay(100);
        printf("\t\t\t\t\t              *                                                    *\n");delay(100);
        printf("\t\t\t\t\t              *          Structured programming mini project       *\n");delay(100);
        printf("\t\t\t\t\t              *                      Group no 1                    *\n");delay(100);
        printf("\t\t\t\t\t              *                                                    *\n");delay(100);
        printf("\t\t\t\t\t              ******************************************************\n\n");delay(100);

    printf("\n\t\t\t\t\t                                ------------------\n");delay(50);
    printf("\t\t\t\t\t                                Select your choice\n");delay(50);
    printf("\t\t\t\t\t                                ------------------\n");delay(50);

    printf("\t\t\t\t\t\t _________________________________________ _______________________");delay(50);
    printf("\n\t\t\t\t\t\t|                                         |                       |");delay(50);
    printf("\n\t\t\t\t\t\t|          CREATE NEW ACCOUNT             |       Enter no 1      |");delay(50);
    printf("\n\t\t\t\t\t\t|_________________________________________|_______________________|");delay(50);
    printf("\n\t\t\t\t\t\t|                                         |                       |");delay(50);
    printf("\n\t\t\t\t\t\t|       LOGIN TO EXISTING ACCOUNT         |       Enter no 2      |");delay(50);
    printf("\n\t\t\t\t\t\t|_________________________________________|_______________________|");delay(50);
    printf("\n\t\t\t\t\t\t|                                         |                       |");delay(50);
    printf("\n\t\t\t\t\t\t|                 EXIT                    |       Enter no 3      |");delay(50);
    printf("\n\t\t\t\t\t\t|_________________________________________|_______________________|");delay(50);

   FILE *mal;
    mal = fopen("jfile.txt", "r");

    if (mal == 0){
        printf("Error!");
        exit(1);
    }else{
        fscanf(mal,"%d", &j);
    }
    fclose(mal);

        printf("\n\n\t\t\t\t\t\t\tEnter your choice\t\t  :\t\t");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            system("cls");
            createNewAccount();
            break;
        }
        case 2: {
            system("cls");
            login();
            break;
        }
        case 3: {
            exit(1);
            return 0;
        }
        default: {
            printf("\n\t\t\t\t\t\t\t !!!!!!!! Please Enter the valid choice !!!!!!!!\n"); delay(1500);
            main();
            break;
        }
        }
    }
}
