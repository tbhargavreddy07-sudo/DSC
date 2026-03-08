/*creating a structure called item */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct itemlist
{
    char itemName[30];
    float price;
    int qty;
}itlist;/*aka*/


void insert_item(itlist [],int);//inserts at an ascending order
void change_price(itlist [],int);//change the price
int delete_item(itlist [],int);//deletes the item based on position given by user
void display_items(itlist [],int);//displays items

int main()
{
   itlist itl [100];
   int choice;
   int i = -1;
    do{
    printf("\n\n\tWelome to inventory manager");
    printf("\n\t1.insert an item");
    printf("\n\t2.change the price of an item");
    printf("\n\t3.delete an item");
    printf("\n\t4.display items");
    printf("\n\t5.exit");
    printf("\nselect choice(1-5)\n\n");  
    scanf("%d",&choice);
    
    
        switch (choice)
        {
        case 1:
        i++;
        insert_item(itl,i);break;
        case 2:
        change_price(itl,i);break;
        case 3:
        int del = delete_item(itl,i);
                if (del == 1)
                {
                    i--;
                }
        break;
        case 4:
        display_items(itl,i);break;
        default:
            break;
        }
    }
    while (choice != 5);
    
} 



void insert_item(itlist itl [],int i)
{
    if(i > 100)
    {
        printf("***The shelves are full***");
    }
    else{

        printf("\n\tEnter the name of the item:");
        scanf("%s",itl[i].itemName);
        printf("\n\tEnter the price the of %s:",itl[i].itemName);
        scanf("%f",&itl[i].price);

    }

}

void change_price(itlist itl [],int i)
{
    char tempName [30];
    if (i == -1)
    {
        printf("***No items in the inventory***");
        return;
    }

    printf("\n\tEnter the name of the item:");
    scanf("%s",tempName);
    for(int j = 0;j <= i;j++)
    {
       
        if(strcmp(itl[j].itemName,tempName)==0)
        {
            float tempprice;

            printf("\n\tEnter the new price the of %s:",tempName);
            scanf("%f",&tempprice);
            itl[j].price = tempprice;
            return;
        }
    }
    printf("***Name Not found***");
    return;
    
}
int delete_item(itlist itl[],int i)
{
    if(i == -1 )
    {
        printf("***No items to delete***");
        return 0;
    }
        char tempname[30];
        printf("\n\tEnter the item you want to delete (item name)");
        scanf("%s",tempname);
     for(int j = 0;j <= i;j++)
    {
       
        if(strcmp(itl[j].itemName,tempname)==0)
        {
            for (int k = i; k < j; j--)
            {
                itl[k] = itl[k+1];
            }
            
            return 1;
        }
    }
    printf("***Name Not found***");
    return 0;


}
void display_items(itlist itl [],int i)
{
        if (i == -1)
    {
        printf("***No items in the inventory***");
        return;
    }
    printf("%-3s %-20s %-5s","No.","Name","Price");
    for (int j = 0; j <= i; j++)
    {
        printf("\n%-3d %-20s %.2f",j+1,itl[j].itemName,itl[j].price);
    }
    
}