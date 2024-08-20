#include <stdio.h>
struct rec
{
    int stdno;
    struct name
    {
        char first[20];
        char mid[20];
        char last[20];
    };
    char class[20];

    struct sem
    {

        struct sub
        {
            char n[20];
            int marks;

            ;
        } c[4];
    } s[2];
};

int main()
{
    int a;
    printf("enter no of students");
    scanf("%d", &a) struct rec[a];

    for (int b = 0; b < a; b++)
    {

        printf("enter student no");
        scanf("%d", &rec[b].stdno);
        printf("enter name");
        scanf("%s%s%s", &rec[b].name.first, &rec[b].name.mid, &rec[b].name.last);
        printf("enter class");
        scanf("%s", &rec[b].class);
        printf(" enter sem 1 subjects:");
        for (int i = 0; i < 4; i++)
        {
            printf("enter subject name");
            scanf("%s", &rec[b].s[0].sub[i].n);
            printf("enter marks");
            scanf("%d", &rec[b].s[0].c[i].marks);
        }

        return 0;
    }