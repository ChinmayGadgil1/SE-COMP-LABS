# include<stdio.h>
# include<string.h>


int main(){

int r=4,c=4;

char mat[r][c];

printf("Enter %d characters:\n",r*c);
for (int i = 0; i < r; i++)
{
    for (int j = 0; j < c; j++)
    {
        scanf("%c", &mat[i][j]);
    }
    
}
printf("\n");
for (int i = 0; i < r; i++)
{
    for (int j = 0; j < c; j++)
    {
        printf("%c", mat[i][j]);
    }
    printf("\n");
}


printf("\nEnter a word to search: ");
char word[r];
scanf("%s", word);

for (int i = 0; i < r; i++)
{   
    int k=0;
    for (int j = 0; j < c; j++)
    {
       if (word[k]==mat[i][j])
       {
        do
        {
           k++;
        } while (word[k]!='\0' && word[k]==mat[i][j]);
        if (k==strlen(word))
        {
            printf("The word %s is found at position (%d,%d)\n",word, i+1, j+1-strlen(word));
            return 0;
        }
        
       }
       
    }
    
}

printf("word not found");
return 1;
}