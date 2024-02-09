#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>

//Queue Structure
struct node {
    int data;
    struct node *next;
}*front = NULL, *rear = NULL,*nn = NULL,*ptr = NULL;

//Order Structure
struct order {
    int numofitems, itemcode[30], itemquantity[30],amount;
}s[500];

//Passwords Structure
struct passwords{
    char pass[10];
}p[3];

int ordernum,i,numberoforders = 0;

//function declarations for waiter and cook
struct node* addorder(struct node *);
struct node* delorder(struct node *);
void waiter(struct node *);
void cook();
void display(struct node *);
void admin();

//internal functions for waiter and cook
void menudisplay();
void orderdisplay(int);
void itemdisplay(int);
int cost(int);

//function declarations for admin
void changepassword();
void orderhistory();
void deletehistory();

//backend functions
void delay(int);
void delay_print(char *);
void about();
void writee();
void readd();

//order functions-------------------------------------

void menudisplay() {
    printf("1. French Fries - Rs.30\n2. Shawarma - Rs.90\n");
    printf("3. Noodles - Rs.65\n4. Pasta - Rs.60\n");
    printf("5. Water Bottle - Rs.30\n");
}

void itemdisplay(int itemcode) {
    switch(itemcode) {
        case 1: printf("French Fries"); break;
        case 2: printf("Shawarma"); break;
        case 3: printf("Noodles"); break;
        case 4: printf("Pasta"); break;
        case 5: printf("Water Bottle"); break;
    }
}

int cost(int itemcode) {
    switch(itemcode) {
        case 1: return 30;
        case 2: return 90;
        case 3: return 65;
        case 4: return 60;
        case 5: return 30;
    }
}

void orderdisplay(int ordernum) {
    s[ordernum].amount = 0;
    printf("Item Name\t Item Quantity\t Amount\n");
    for(i=0; i<s[ordernum].numofitems; i++) {
        itemdisplay(s[ordernum].itemcode[i]);
        printf("\t\t%d",s[ordernum].itemquantity[i]);
        printf("\t%d\n",s[ordernum].itemquantity[i] * cost(s[ordernum].itemcode[i]));
        s[ordernum].amount += s[ordernum].itemquantity[i] * cost(s[ordernum].itemcode[i]);
    }
}

//admin functions-----------------------------

void changepassword() {
    system("cls");
    int op;
    printf("Which password do you want to change ?\n\n");
    cp:fflush(stdin);
    printf("1. Waiter\n2. Chef\n3. Admin\n\n : ");
    scanf("%d", &op);
    fflush(stdin);
    if(op>3 || op<1) {
        printf("\nInvalid Option\n");
        goto cp;
    }
    printf("\nEnter New Password : ");
    scanf("%s",p[op-1].pass);
    writee();
    system("cls");
    printf("Password changed successfully. Exiting...\n");
    delay(1);
}

void orderhistory() {
    int totalcollections = 0;
    system("cls");
    printf("Order Number\tNo. of Items\tBill Amount\n");
    for(i=1;i<ordernum;i++) {
        printf("\t%d\t\t%d\t\t%d\n", i,s[i].numofitems,s[i].amount);
        totalcollections += s[i].amount;
    }
    printf("\nTotal Collections : %d\n", totalcollections);   
    printf("\nPress any key to continue...\n");
    getch();
}

void deletehistory() {
    char op;
    system("cls");
    printf("NOTE: The Program Needs to Restart to perform the following operation");
    printf("\n\nAre you sure you want to delete the history ? [Y/N] : ");
    fflush(stdin);
    scanf("%c",&op);
    if(op=='n') return;
    remove("orders.txt");
    readd();
    system("cls");
    printf("\nHistory deleted successfully. Exiting Program...\n");
    writee();
    delay(1);
    exit(0);
}

//Backend Functions --------------------------------

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void delay_print(char *str)
{
    for (char *p = str; *p; p++) {
        putchar(*p);
        fflush(stdout);
        usleep(13500);
    }
    putchar('\n');
}

void readd() {
    int f=0;
  FILE * fp = fopen("orders.txt", "r");
  if (fp == NULL) {
    fp = fopen("orders.txt", "w");
    fclose(fp);
  }
  ordernum = fread(s, sizeof(struct order), 500, fp);
  fclose(fp);
  fp = fopen("passwords.txt", "r");
  if (fp == NULL) {
    fp = fopen("passwords.txt", "w");
    printf("Set Admin Password: ");
    scanf("%s",p[2].pass);
    printf("Set Waiter Password: ");
    scanf("%s",p[0].pass);
    printf("Set Chef Password: ");
    scanf("%s",p[1].pass);
    fclose(fp);
    f=1;
  }
  if(f==0) fread(p, sizeof(struct passwords), 3, fp);
  fclose(fp);
}

void writee() {
  FILE * fp = fopen("orders.txt", "w");
  if (fp == NULL) {
    printf("Error");
    exit(1);
  }
  fwrite(s, sizeof(struct order), ordernum, fp);
  fclose(fp);
  fp = fopen("passwords.txt", "w");
  if (fp == NULL) {
    printf("Error");
    exit(1);
  }
  fwrite(p, sizeof(struct passwords), 3, fp);
  fclose(fp);
}

