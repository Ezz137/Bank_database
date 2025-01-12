#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "TYPEDEF.h"
#include "BANKDATA.h"
#define CLIENTS 5
uint16 Counter;
Bank_Account_N Bank_Account[CLIENTS];
int main()
{
       uint8 choice=0;
       while (1)
       {
            static uint32 id;
            printf("Please choose an option from the following\n1-Create a new Customer (please press 1)\n2-edit an exist customer (please press 2)\n3-remove a customer (please press 3)\n4-print customer data (please press 4)\n5-transfer money between 2 accounts (please press 5)\n6-to exit (please press 6)\n ");
            scanf("%i",&choice);
            switch (choice)
            {
                case 1:
                {
                    new_customer();
                    break;
                }
                case 2:
                {
                    printf("enter your id\n");
                    scanf("%lu",&id);
                    edit_customer(id);
                    break;
                }
                case 4:
                {
                    printf("enter your id\n");
                    scanf("%lu",&id);
                    print_customer(id);
                    break;
                }
                case 5:
                {
                    uint64 id2=0;
                    uint64 Cash2=0;
                    printf("enter your id\n");
                    scanf("%llu",&id);
                    printf("second id plz\n");
                    scanf("%llu",&id2);
                    printf("cash transfered please\n");
                    scanf("%llu",&Cash2);
                    transfer_cash(id,id2,Cash2);
                    break;
                }
                case 3:
                {
                    printf("enter your id\n");
                    scanf("%lu",&id);
                    remove_customer(id);
                    break;
                }
                case 6:
                {
                    printf("\nThank you\n");
                    break;
                }
                default:
                {
                    printf("\nplease enter correct number\n");
                }
            }
       }
    return 0;
}
