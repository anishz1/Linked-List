#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert();
void lastinsert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\nChoose Option from the following\n");
        printf("\nl. Insert in begining\n2. Insert at last\n3. Insert item location\n4. Delete from Beginning\n5. Delete from last\n6. Delete item from location\n7. Search\n8. Show List\n9. Exit\n");

        printf("\nEnter your choice: ");
        scanf("\n%d", &choice);  

        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            random_insert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid Choice..");
        }
    }
    return 0;
}
void beginsert()
{
    struct node *newNode;
    int item;
    newNode = (struct node *)malloc(sizeof(struct node *));
    if (newNode == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        newNode->data = item;
        newNode->next = head;
        head = newNode;
        printf("Item inserted");
    }
}
void lastinsert()
{
    struct node *newNode, *temp;
    int item;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        newNode->data = item;
        if (head == NULL)
        {
            newNode->next = NULL;
            head = newNode;
            printf("Item inserted");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
            printf("Item inserted");
        }
    }
}
void random_insert()
{
    int i, loc, item;
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("Enter Value: ");
        scanf("%d", &item);
        newNode->data = item;
        printf("\nEnter the location: ");
        scanf("%d", &loc);
        temp = head;
        for (i = 1; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Item inserted");
    }
}
void begin_delete()
{
    struct node *newNode;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        newNode = head;
        head = newNode->next;
        free(newNode);
        printf("Item deleted from the begining ...\n");
    }
}
void last_delete()
{
    struct node *newNode, *newNodel;
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ..\n");
    }
    else
    {
        newNode = head;
        while (newNode->next != NULL)
        {
            newNodel = newNode;
            newNode = newNode->next;
        }
        newNodel->next = NULL;
        free(newNode);
        printf("Item deleted\n");
    }
}
void random_delete()
{
    struct node *newNode, *newNodel;
    int loc, i;

    printf("\n Enter the location: ");
    scanf("%d", &loc);
    newNode = head;
    for (i = 0; i < loc; i++)
    {
        newNodel = newNode;
        newNode = newNode->next;
        if (newNode == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    newNodel->next = newNode->next;
    free(newNode);
    printf("Item deleted at loc %d", loc);
}
void search()
{
    struct node *newNode;
    int item, i = 0, flag;
    newNode = head;
    if (newNode == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter searching item: ");
        scanf("%d", &item);
        while (newNode != NULL)
        {
            if (newNode->data == item)
            {
                printf("Item found at location %d ", i + 1);
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            i++;
            newNode = newNode->next;
        }
        if (flag == 1)
        {
            printf("Item not found\n");
        }
    }
}
void display()
{
    struct node *newNode;
    newNode = head;
    if (newNode == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nPrinting values while (newNode!=NULL).\n");
        while (newNode != NULL)
        {
            printf("%d\n", newNode->data);
            newNode = newNode->next;
        }
    }
}