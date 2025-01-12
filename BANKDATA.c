#include "TYPEDEF.h"
#include <stdio.h>
#include "BANKDATA.h"
#include <string.h>
#define CLIENTS 5
//float64 Cash[CLIENTS];
extern Bank_Account_N Bank_Account[CLIENTS];
extern uint16 Counter;
void new_customer(void)
{
    if (Counter<CLIENTS&&Counter>=0)
    {
        printf("enter Customer name\n");
        fflush(stdin);
        fgets(Bank_Account[Counter].client_name,30,stdin);
        printf("enter Customer N.id\n");
        scanf("%llu",&Bank_Account[Counter].National_id);
        printf("enter Customer Bank id\n");
        scanf("%llu",&Bank_Account[Counter].Bank_id);
        printf("enter Customer Cash\n");
        scanf("%llu",&(Bank_Account[Counter].Cash));
        //scanf("%lf",&Cash[Counter]);
        printf("enter Customer Bank Account Type\n");
        fflush(stdin);
        fgets(Bank_Account[Counter].Bank_Account_Type,8,stdin);
        printf("enter Customer Bank Account Visa Type\n");
        fflush(stdin);
        fgets(Bank_Account[Counter].Bank_Account_Visa,7,stdin);
        Counter++;
    }
    else
    {
        printf("Clients are Full\n");
    }
}
void edit_customer(uint64 id)
{
    uint8 i;
    for(i=0;i<CLIENTS;i++)
    {
        if (Bank_Account[i].Bank_id==id)
        {
            break;
        }
    }
    printf("enter Customer name\n");
    fflush(stdin);
    fgets(Bank_Account[i].client_name,30,stdin);
    printf("enter Customer N.id\n");
    scanf("%llu",&Bank_Account[i].National_id);
    printf("enter Customer Cash\n");
    scanf("%llu",&Bank_Account[i].Cash);
    printf("enter Customer Bank Account Type\n");
    fflush(stdin);
    fgets(Bank_Account[i].Bank_Account_Type,8,stdin);
    printf("enter Customer Bank Account Visa Type\n");
    fflush(stdin);
    fgets(Bank_Account[i].Bank_Account_Visa,7,stdin);
}
void print_customer(uint64 id)
{
    uint8 i;
    for(i=0;i<CLIENTS;i++)
    {
        if (Bank_Account[i].Bank_id==id)
        {
            break;
        }
    }
    if (i!=CLIENTS)
    {
        printf("the Name of client is %s",Bank_Account[i].client_name);
        printf("the national id of client is %llu\n",Bank_Account[i].National_id);
        printf("the Bank id of client is %llu\n",Bank_Account[i].Bank_id);
        printf("the cash  of client is %llu\n",Bank_Account[i].Cash);
        printf("the Bank type of client is %s",Bank_Account[i].Bank_Account_Type);
        printf("the Visa type of client is %s\n",Bank_Account[i].Bank_Account_Visa);
    }
    else
    {
        printf("WRONG ID \n");
    }
}
void transfer_cash(uint64 id,uint64 id2,uint64 Cash2)
{
    uint8 i,j;
    for(i=0;i<CLIENTS;i++)
    {
        if (Bank_Account[i].Bank_id==id)
        {
            break;
        }
    }
    for(j=0;j<CLIENTS;j++)
    {
        if (Bank_Account[j].Bank_id==id2)
        {
            break;
        }
    }
    if ((i!=CLIENTS)&&(j!=CLIENTS))
    {
        if(Cash2<=Bank_Account[i].Cash)
        {
            Bank_Account[j].Cash=Cash2+Bank_Account[j].Cash;
            Bank_Account[i].Cash=Bank_Account[i].Cash-Cash2;
            printf("Cash for Receiver id %llu after transfer the money is %llu\n",Bank_Account[j].Bank_id,Bank_Account[j].Cash);
            printf("Cash for Donor id %llu after transfer the money is %llu\n",Bank_Account[i].Bank_id,Bank_Account[i].Cash);
        }
        else
        {
            printf("cash you have in your account is insufficient enough for that transfer \n");
        }
    }
    else
    {
        printf("one of the entered clients not exist in our database\n");
    }
}
void remove_customer(uint64 id)
{
    uint8 i;
    for(i=0;i<CLIENTS;i++)
    {
        if (Bank_Account[i].Bank_id==id)
        {
            break;
        }
    }
    if (i!=CLIENTS)
    {
        for(;i<CLIENTS-1;i++)
        {
            Bank_Account[i]=Bank_Account[i+1];
        }
        Counter--;
        Bank_Account[i].Bank_id=0;
        strcpy(Bank_Account[i].client_name,"\0");
        strcpy(Bank_Account[i].Bank_Account_Type,"\0");
        strcpy(Bank_Account[i].Bank_Account_Visa,"\0");
        Bank_Account[i].National_id=0;
        Bank_Account[i].Cash=0;
    }
    else
    {
        printf("entered id is not exist to be removed\n");
    }
}
