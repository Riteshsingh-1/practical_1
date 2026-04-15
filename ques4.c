#include <stdio.h>
#include <stdlib.h>

struct Patient
{
    int Patient_ID;
    char Name[50];
    int age;
    char Disease[75];
    int Consultation_fee;
};

void PatientDetails(struct Patient *p, int n)
{
    printf("\n=== Patient Details ===\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nPatient ID: %d", p[i].Patient_ID);
        printf("\nPatient Name: %s", p[i].Name);
        printf("\nPatient Age: %d", p[i].age);
        printf("\nDisease: %s", p[i].Disease);
        printf("\nConsultation Fee: %d\n", p[i].Consultation_fee);
    }
}

void searchPatient(struct Patient *p, int n, int key)
{
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (p[i].Patient_ID == key)
        {
            printf("\nPatient Found!");
            printf("\nName: %s", p[i].Name);
            printf("\nAge: %d", p[i].age);
            printf("\nDisease: %s", p[i].Disease);
            printf("\nConsultation Fee: %d\n", p[i].Consultation_fee);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nPatient not found!");
}

int main()
{
    int n;

    printf("Enter number of patients: ");
    scanf("%d", &n);

    struct Patient *p = malloc(n * sizeof(struct Patient));

    if (p == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details of patient %d\n", i + 1);

        printf("Patient ID: ");
        scanf("%d", &p[i].Patient_ID);

        printf("Name: ");
        scanf("%s", p[i].Name);

        printf("Age: ");
        scanf("%d", &p[i].age);

        printf("Disease: ");
        scanf("%s", p[i].Disease);

        printf("Consultation Fee: ");
        scanf("%d", &p[i].Consultation_fee);
    }

    PatientDetails(p, n);

    int searchID;
    printf("\nEnter Patient ID to search: ");
    scanf("%d", &searchID);

    searchPatient(p, n, searchID);

    free(p);

    return 0;
}
