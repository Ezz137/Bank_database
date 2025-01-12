#ifndef BANKDATA.H
#define BANKDATA.H
typedef struct Bank_Account_t
{
    uint8 client_name [30];
    uint8 Bank_Account_Type [8];
    uint8 Bank_Account_Visa [7];
    uint64 National_id;
    uint64 Bank_id;
    uint64 Cash;
}Bank_Account_N;

void new_customer(void);
void edit_customer(uint64 id);
void print_customer(uint64 id);
void transfer_cash(uint64 id,uint64 id2,uint64 Cash2);
void remove_customer(uint64 id);
#endif
