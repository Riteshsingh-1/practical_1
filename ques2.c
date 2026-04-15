#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *str;
    int length;
    printf("Enter maximum length of the string:");
    scanf("%d", &length);

    getchar();
    str = (char *)malloc((length + 1) * sizeof(char));

    if (str == NULL)
    {
        printf("Meemory allocation faied\n");
    }
    printf("Enter the string:");
    fgets(str, length + 1, stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Your Entered string is %s\n", str);

    printf("Length of string is = %d\n", strlen(str));

    free(str);
    return 0;
}