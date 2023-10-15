#include<stdio.h>
int main()
{
    char *filename = "test.txt";
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
{

printf("Error opening the file %s, filename");
return -1;

}

for (int i = 0; i <10; i++)
    fprintf(fp, "This is the line #%d\n", i + 1);

    fclose(fp);
    return 0;

}