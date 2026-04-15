#include <stdio.h>
#include <stdlib.h>

struct customer
{
    int accno;
    char name[50];
    char type[20];
    float balance;
};

void CustomerDetails(struct customer *c, int n)
{
    int i;

    printf("\nAll customer details:\n");

    for (i = 0; i < n; i++)
    {
        printf("\nAccount no: %d", c[i].accno);
        printf("\nName: %s", c[i].name);
        printf("\nType: %s", c[i].type);
        printf("\nBalance: %.2f\n", c[i].balance);
    }
}

void lowBalance(struct customer *c, int n)
{
    int i;

    printf("\nCustomers with balance below 5000:\n");

    for (i = 0; i < n; i++)
    {
        if (c[i].balance < 5000)
        {
            printf("\nAccount no: %d", c[i].accno);
            printf("\nName: %s", c[i].name);
            printf("\nBalance: %.2f\n", c[i].balance);
        }
    }
}

int main()
{
    int n, i;

    printf("Enter number of customers: ");
    scanf("%d", &n);

    struct customer *c;

    c = (struct customer *)malloc(n * sizeof(struct customer));

    if (c == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of customer %d\n", i + 1);

        printf("Account number: ");
        scanf("%d", &c[i].accno);

        printf("Name: ");
        scanf(" %s", c[i].name);

        printf("Type: ");
        scanf(" %s", c[i].type);

        printf("Balance: ");
        scanf("%f", &c[i].balance);
    }

    CustomerDetails(c, n);
    lowBalance(c, n);

    free(c);

    return 0;
}
