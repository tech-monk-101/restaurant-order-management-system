#include "headers.c"

int main() {
    int op;
    system("color f");
    readd();
    do {
        system("cls");
        getch();
        //
        delay_print("/*/ Welcome to Andy's Fast Food Center /*/\n\n");
        printf("* * * * Main Menu * * * *\n");
        printf("*                       *\n");
        printf("*      1. Waiter        *\n*      2. Chef          *\n");
        printf("*      3. Admin         *\n*      4. About         *\n");
        printf("*      5. Exit          *\n");
        printf("*                       *\n");
        printf("* * * * * * * * * * * * *\n\n");
        printf("Select Your Role: ");
        //
        scanf("%d", &op);
        switch (op) {
            case 1: waiter(rear); break;
            case 2: cook(front); break;
            case 3: admin(); break;
            case 4: about(); break;
            case 5: {
                writee();
                exit(0);
            } 
        }
    }while(1);
}

//Waiter Operations-----------------------------------------
void waiter(struct node *rear) {
    char str[10],c;
    printf("\nEntering Waiter mode....\n\n");
    delay(1);
    system("cls");
    printf("Enter Password: ");
    //
    i=0;
    while(i<10)
	{
	    str[i]=getch();
	    c=str[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	str[i]='\0';
	i=0;
    //
    if(strcmp(str, p[0].pass)) {
        printf("Wrong Password. Exiting..\n");
        delay(1);
        system("cls");
        return;
    }
    system("cls");
    int op;
    do {
        system("cls");
        //
        printf("|| Waiter Mode ||\n\n");
        printf("* * * * * * * * * * * * * *\n");
        printf("*                         *\n");
        printf("*  1. Add order           *\n*  2. Display All Orders  *\n");
        printf("*  3. Number of Orders    *\n*  4. Exit                *\n");
        printf("*                         *\n");
        printf("* * * * * * * * * * * * * *\n");
        printf("\nSelect Option: ");
        //
        scanf("%d", &op);
        switch (op) {
            case 1: rear = addorder(rear); break;
            case 2: display(front); break;
            case 3: {
                system("cls");
                printf("Number of Orders Pending = %d\n",numberoforders);
                printf("\nPress any key to continue...\n");
                getch(); 
                break;
            }
            case 4: writee(); return;
        }
    }while(1);
}

struct node* addorder(struct node *rear) {
    start: system("cls");
    if(ordernum == 0) {
        s[ordernum].numofitems = 0;
        s[ordernum].amount = 0;
        s[ordernum].itemcode[0] = 0;
        s[ordernum].itemquantity[0] = 0;
        ordernum++;
        goto start;
    }
    printf("Number of Order Pending: %d\n",numberoforders);
    numberoforders++;
    s[ordernum].numofitems = 0;
    char op = 'y';
    while(op == 'y') {
        s[ordernum].numofitems++;
        int items = s[ordernum].numofitems - 1;
        printf("\n");
        menudisplay();
        printf("\n");
        printf("Enter Item Code: ");
        scanf("%d", &s[ordernum].itemcode[items]);
        printf("Enter Item Quantity: ");
        scanf("%d", &s[ordernum].itemquantity[items]);
        printf("\nAdd More ? [Y/N]: ");
        fflush(stdin);
        scanf("%c", &op);  
    }
    system("cls");
    orderdisplay(ordernum);
    printf("\nTotal Payable Amount: %d\n\n",s[ordernum].amount);
    pay : printf("Confirm Payment[Y/N]: ");
    fflush(stdin);
    scanf("%c", &op);
    if(op == 'y') {
        nn = (struct node *) malloc(sizeof(struct node));
        nn->data=ordernum;
        nn->next = NULL;
        if(rear == NULL) {
            rear = nn;
            front = nn;
        }
        else {
            rear->next = nn;
            rear = nn;
        }
        system("cls");
        printf("Order Placed Successfully. Your Order Number: %d\n",ordernum);
        ordernum++;
        printf("Press any key to continue...\n");
        getch();
        system("cls");
    }
    else if(op == 'n') {
        system("cls");
        printf("Order Cancelled. Exiting...\n");
        numberoforders--;
        delay(1);
        system("cls");
    }
    else {
        printf("Enter Valid Option\n");
        goto pay;
    }
    return rear;
}

void display (struct node *front) {
    
    if(front == NULL) {
        system("cls");
        printf("No Pending Orders\n");
    }
    else {
        system("cls"); 
        printf("Number of Order Pending: %d\n",numberoforders);
        ptr = front;
        printf("Order Number\tNo. of Items\tBill Amount\n");

        while(ptr!=NULL) {
            printf("\t%d\t\t%d\t\t%d\n\n", ptr->data,s[ptr->data].numofitems,s[ptr->data].amount);
            ptr = ptr->next;
        }
    }
    printf("\nPress any key to continue...");
    getch();
}

//Chef operations-------------------------------------------------

void cook() {
    char str[10],c;
    printf("\nEntering Chef mode....\n\n");
    delay(1);
    system("cls");
    printf("Enter Password: ");
     //
    i=0;
    while(i<10)
	{
	    str[i]=getch();
	    c=str[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	str[i]='\0';
	i=0;
    //
    if(strcmp(str, p[1].pass)) {
        printf("Wrong Password. Exiting..\n");
        delay(1);
        system("cls");
        return;
    }
    system("cls");
    int op;
    do {
        system("cls");
        //
        printf("|| Chef Mode ||\n\n");
        printf("* * * * * * * * * * * * * *\n");
        printf("*                         *\n");
        printf("*    1. Pull Order        *\n*    2. Display Orders    *\n");
        printf("*    3. Pending Orders    *\n*    4. Exit              *\n");
        printf("*                         *\n");
        printf("* * * * * * * * * * * * * *\n");
        printf("\nSelect Option: ");
        //
        scanf("%d", &op);
        switch (op) {
            case 1: front = delorder(front); break;
            case 2: display(front); break;
            case 3:  {
                system("cls");
                printf("Number of Orders Pending = %d\n",numberoforders);
                printf("\nPress any key to continue...\n");
                getch();
                break;
            }
            case 4: writee(); return;
        }
    }while(1);
}

struct node* delorder(struct node *front) {
    if(front == NULL) {
        system("cls");
        printf("No Pending Orders\n\n");
        printf("Press any key to continue...\n");
        getch();
        
    }
    else {
        system("cls");
        char op = 'n';
        printf("Number of Order Pending: %d\n\n",numberoforders);
        printf("Order Number: %d\n\n",front->data);
        for(i=0;i<s[front->data].numofitems;i++) {
            printf("%d. ",i+1);
            itemdisplay(s[front->data].itemcode[i]);
            printf(" X %d\n",s[front->data].itemquantity[i]);
        }
        mark : printf("\n\nMark as done ? [Y/N]: ");
        fflush(stdin);
        scanf("%c",&op);
        if(op == 'y') {
            system("cls");
            printf("Order %d Completed Successfully. Exiting...\n",front->data);
            ptr = front;
            front = front->next;
            free(ptr);
            numberoforders--;
            delay(1);
            system("cls");
            return front;
        }
        else if(op == 'n') {
            system("cls");
            return front;
        }
        else {
            printf("\nInvalid Option\n");
            goto mark;
        }
    }
    return front;
}

//admin operations--------------------------------------------

void admin() {
    char str[10],c;
    printf("\nEntering Admin mode....\n\n");
    delay(1);
    system("cls");
    printf("Enter Password: ");
     //
    i=0;
    while(i<10)
	{
	    str[i]=getch();
	    c=str[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	str[i]='\0';
	i=0;
    //
    if(strcmp(str, p[2].pass)) {
        printf("Wrong Password. Exiting..\n");
        delay(1);
        system("cls");
        return;
    }
    system("cls");
    int op;
    do {
        system("cls");
        //
        printf("|~| Admin Mode |~|\n\n");
        printf("* * * * * * * * * * * * * * *\n");
        printf("*                           *\n");
        printf("*   1. View Order History   *\n*   2. Change Passwords     *\n");
        printf("*   3. Clear Order History  *\n*   4. Exit                 *\n");
        printf("*                           *\n");
        printf("* * * * * * * * * * * * * * *\n");
        printf("\nSelect Option: ");
        //
        scanf("%d", &op);
        switch (op) {
            case 1: orderhistory(); break;
            case 2: changepassword(); break;
            case 3: deletehistory(); break;
            case 4: writee(); return;
        }
    }while(1);
} 

void about() {
  system("cls");
  delay_print("--------- Restaurant Order Management System ---------");
  delay_print("Build 2.0");
  delay_print("Copyright (c) All rights reserved. /s");
  delay(1);
  printf("Press any key to continue...\n");
  getch();
}