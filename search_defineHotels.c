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

struct hotels {
    char hotel[100];
    char food_one[20];
    char food_two[20];
    char food_three[20];
    int price_one, price_two, price_three;
};

struct details s[100];
struct hotels m[5];

int hotel_choice;

void hotel_define()
{
    // Initializing the structure with GALADARI HOTEL and some foods name and their respective costs.
    strcpy(m[1].hotel, "GALADARI HOTEL");
    strcpy(m[1].food_one, "CHICKEN BIRIYANI ");
    strcpy(m[1].food_two, "CHEESE PASTA ");
    strcpy(m[1].food_three, "CAESAR SALAD  ");
    m[1].price_one = 7000;
    m[1].price_two = 4000;
    m[1].price_three = 3500;

    // Initializing the structure with SHANGRI-LA HOTEL and some foods name and their respective costs.
    strcpy(m[2].hotel, "SHANGRI-LA HOTEL");
    strcpy(m[2].food_one, "NAI MIRIS PIZZA ");
    strcpy(m[2].food_two, "SPICED CHICKEN");
    strcpy(m[2].food_three, "CHANA MASALAA");
    m[2].price_one = 2000;
    m[2].price_two = 1500;
    m[2].price_three = 1000;

    // Initializing the structure with THE KINGSBURY hotel and some foods name and their respective costs.
    strcpy(m[3].hotel, "THE KINGSBURY");
    strcpy(m[3].food_one, "BBQ PORK RIBS");
    strcpy(m[3].food_two, "CARAMEL MACCHIATO");
    strcpy(m[3].food_three, "DUCK & NOODLES SOUP");
    m[3].price_one = 1600;
    m[3].price_two = 1000;
    m[3].price_three = 1800;

    // Initializing the structure with HILTON COLOMBO hotel and some foods name and their respective costs.
    strcpy(m[4].hotel, "HILTON COLOMBO");
    strcpy(m[4].food_one, "GODAMBA ROTI MEAL");
    strcpy(m[4].food_two, "TANDOORI CHICKEN");
    strcpy(m[4].food_three, "BACON BEEF BURGER");
    m[4].price_one = 4800;
    m[4].price_two = 800;
    m[4].price_three = 1300;

    // Initializing the structure with CINNAMON GRAND hotel and some foods name and their respective costs.
    strcpy(m[5].hotel, "CINNAMON GRAND");
    strcpy(m[5].food_one, "PEACH ALMOND TART");
    strcpy(m[5].food_two, "CHOCOLATE PUDDING");
    strcpy(m[5].food_three, "FALOODA & BERRY");
    m[5].price_one = 2900;
    m[5].price_two = 1400;
    m[5].price_three = 800;
}

void search_hotels()
{
    hotel_define();
        system("cls");
        system ("COLOR 06");
        printf("\n\t\t\t\t\t                                   ------------------\n");delay(100);
        printf("\t\t\t\t\t                                   Select your choice\n");delay(100);
        printf("\t\t\t\t\t                                   ------------------\n");delay(100);

        printf("\t\t\t\t\t\t _________________________________________ _______________________");delay(75);
        printf("\n\t\t\t\t\t\t|                                         |                       |");delay(75);
        printf("\n\t\t\t\t\t\t|             %s              |       Enter no 1      |",m[1].hotel);delay(75);
        printf("\n\t\t\t\t\t\t|_________________________________________|_______________________|");delay(75);
        printf("\n\t\t\t\t\t\t|                                         |                       |");delay(75);
        printf("\n\t\t\t\t\t\t|            %s             |       Enter no 2      |",m[2].hotel);delay(75);
        printf("\n\t\t\t\t\t\t|_________________________________________|_______________________|");delay(75);
        printf("\n\t\t\t\t\t\t|                                         |                       |");delay(75);
        printf("\n\t\t\t\t\t\t|               %s             |       Enter no 3      |",m[3].hotel);delay(75);
        printf("\n\t\t\t\t\t\t|_________________________________________|_______________________|");delay(75);
        printf("\n\t\t\t\t\t\t|                                         |                       |");delay(75);
        printf("\n\t\t\t\t\t\t|             %s              |       Enter no 4      |",m[4].hotel);delay(75);
        printf("\n\t\t\t\t\t\t|_________________________________________|_______________________|");delay(75);
        printf("\n\t\t\t\t\t\t|                                         |                       |");delay(75);
        printf("\n\t\t\t\t\t\t|               %s            |       Enter no 5      |",m[5].hotel);delay(75);
        printf("\n\t\t\t\t\t\t|_________________________________________|_______________________|");delay(75);
        printf("\n\t\t\t\t\t\t|                                         |                       |");delay(75);
        printf("\n\t\t\t\t\t\t|                  EXIT                   |       Enter no 6      |");delay(75);
        printf("\n\t\t\t\t\t\t|_________________________________________|_______________________|");delay(75);


    printf("\n\n\t\t\t\t\t\t\tSelect The Hotel\t\t  :\t\t");
    scanf("%d", &hotel_choice);
    if (hotel_choice > 6 || hotel_choice == 0) {
        printf("\t\t\t\t\t\t\tPlease Enter the valid choice\n\n");delay(1500);
        search_hotels();
    }
    else if (hotel_choice == 6){
       main();
    }
    else {
        hotels(hotel_choice);
    }
}
