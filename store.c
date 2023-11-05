//Victor Nin
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define a structure to store customer information
typedef struct {
   char name[100];
   char items[100][100];
   int num_items;
   char address[100];
   char phone_num[100];
   float total_spent;
} Customer;


// Function to create a new customer
Customer *create_customer(char *name, char **items, int num_items, char *address, char *phone_num, float total_spent)
{
   Customer *c = malloc(sizeof(Customer));
   strcpy(c->name, name);
   for (int i = 0; i < num_items; i++)
       strcpy(c->items[i], items[i]);
   c->num_items = num_items;
   strcpy(c->address, address);
   strcpy(c->phone_num, phone_num);
   c->total_spent = total_spent;
   return c;
}


// Function to compare two customers by their names and list them alphabetically
int compare_customers(const void *a, const void *b)
{
   Customer *c1 = *(Customer **)a;
   Customer *c2 = *(Customer **)b;
   return strcmp(c1->name, c2->name);
}


// Function to compare two customers by their total spent
int compare_customers_by_spent(const void *a, const void *b)
{
   Customer *c1 = *(Customer **)a;
   Customer *c2 = *(Customer **)b;
   return c1->total_spent > c2->total_spent ? -1 : 1;
}


// Function to compare two customers by their total number of items
int compare_customers_by_items(const void *a, const void *b)
{
   Customer *c1 = *(Customer **)a;
   Customer *c2 = *(Customer **)b;
   return c1->num_items > c2->num_items ? -1 : 1;
}
// Function to print the information for a customer
void print_customer_info(Customer *c)
{
   printf("\nName: %s\n", c->name);
   printf("Items purchased:\n");
   for (int i = 0; i < c->num_items; i++)
       printf("- %s\n", c->items[i]);
   printf("Email Address: %s\n", c->address);
   printf("Phone Number: %s\n", c->phone_num);
   printf("Total spent: $%.2f\n", c->total_spent);
}


void send_coupon(Customer **customers, int num_customers)
{
   // Sort the customers in descending order by their total spent
   qsort(customers, num_customers, sizeof(Customer*), compare_customers_by_spent);


   // Send a coupon to the customer who has spent the most money
   printf("\n\nCongratulations %s! You have earned a $25 coupon for being our top spender. Use code HOLIDAYS at checkout to redeem your discount.\n\n", customers[0]->name);
}


void send_discount(Customer **customers, int num_customers)
{
   // Sort the customers in descending order by their total number of items
   qsort(customers, num_customers, sizeof(Customer*), compare_customers_by_items);


   // Send a discount to the customer who has bought the most items
   printf("\n\nCongratulations %s! You have earned a 30 percent off coupon for being our top brand supporter! Use code SANTA at checkout to redeem your discount.\n\n", customers[0]->name);
}


int main()
{
   // Create an array of customers
   Customer *customers[3];
   customers[0] = create_customer("Frederick Miller", (char*[]){"Shirt", "Pants", "Shoes"}, 3, "FreddyM@gmail,com", "(809)562-3546", 49.99);
   customers[1] = create_customer("Minnie Mouse", (char*[]){"Dress", "Hat"}, 2, "MinnieMouse12@hotmail.com", "(202)337-8920", 59.99);
   customers[2] = create_customer("Bobby Johnson", (char*[]){"Socks", "Shoes"}, 2, "BobbyJJohnson@gwu.edu", "(351)267-4458", 29.99);


   // Print the customers' information in alphabetical order by their names
   qsort(customers, 3, sizeof(Customer*), compare_customers);
   for (int i = 0; i < 3; i++)
       print_customer_info(customers[i]);


 // Send a coupon to the customer who has spent the most money
   send_coupon(customers, 3);


// Send a discount to the customer who has bought the most items
   send_discount(customers, 3);


   return 0;
}
