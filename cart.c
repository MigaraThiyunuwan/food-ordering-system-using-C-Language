#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int total,cart_choice,i,confirm;
char namecopy[100][100];
char phnNumcopy[100][100];

void cart()
{
    system("cls");
    system ("COLOR 0A");

    printf("\n\n\n\n\t\t\t\t\t\t\t\t    ============= Cart =============");delay(50);delay(50);
    printf("\n\n\t\t\t\t\t\t\tYour Total Order Amount is \t\t\t Rs %d/=\n\n", total);delay(50);
    printf("\t\t\t\t\t\t\t=========================================================\n");delay(50);
    printf("\t\t\t\t\t\t\t=========================================================\n");delay(50);
    printf("\n\n\t\t\t\t\t\t\t Do You wish to order (yes=1/no=0):\t\t\t");
    scanf("%d", &cart_choice);
    if (cart_choice == 1) {

            FILE *abc;
            abc = fopen("cart.txt", "a+");
            if (abc == 0){
                printf("Error!");
                    exit(1);
            }else{

                fprintf(abc,"\nYour Total Order Amount is Rs \t\t\t %d/=\n\n",total);
                fprintf(abc," Client name: %s            Phone Number: %s\n",namecopy[i], phnNumcopy[i]);
                fprintf(abc,"=========================================================\n");
                fclose(abc);
            }

        printf("\n\n\t\t\t\t\t\t\tThank You for your order!! Your Food is on the way. Welcome again!!\n\n");
        exit(1);
        return;
    }
    else if (cart_choice == 0) {

            FILE *abc;
            abc = fopen("cart.txt", "a+");
            if (abc == 0){
                printf("Error!");
                    exit(1);
            }else{

                fprintf(abc,"\n\t\t This Order Canceled!!!!\n");
                fprintf(abc,"=========================================================\n");
                fclose(abc);
            }

        printf("\t\t\t\t\t\t\tDo You want to exit (1) or Go back (0) :");
        scanf("\t\t\t\t%d", &confirm);
        if (confirm == 1) {


            printf("\n\n\t\t\t\t\t\t\tOops! Your order is cancelled!! \nExiting Application...\nThank You visit again!\n");
            exit(1);
            return;
        }

        else {
            printf("\n\n\t\t\t\t\t\t\t\t\tThank You\n\n");
            login();
        }
    }
    else {
        printf("\n\n\t\t\t\t\t\t\tPlease Enter the correct choice\n\n");delay(1500);
        cart();
    }
}
