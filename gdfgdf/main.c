#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    /*аргументы dict.txt input.txt output.txt */
char massiv[1024];
char massivnew[1024];
char massiv1[1024];
int r = 0;
char* znaki;
FILE *clear1 =fopen("inputnew.txt", "w");
fprintf(clear1, "%s", "");
fclose(clear1);
FILE *clear2 =fopen(argv[3], "w");
fprintf(clear2, "%s", "");
fclose(clear2);
/*Почистил текстовые файлы*/
FILE *text =fopen(argv[2], "r");
FILE *dict =fopen(argv[1], "r");
FILE *opaa =fopen(argv[3],"a");
FILE *neww =fopen("inputnew.txt", "a");
fgets(massivnew, 1024, text);
char* mass = massivnew;
while(znaki = strtok_r(mass," .,-",&mass))
{
    fprintf(neww, "%s\n", znaki);
}
/*Переписали файл input в файл inputnew без знаков препинания*/
fclose(neww);
FILE *neww2 =fopen("inputnew.txt", "r");

while (!feof(neww2)){
fscanf(neww2, "%s", massiv);
int k = 0;
while (!feof(dict))
{
fscanf(dict, "%s", massiv1);
if (strcmp(massiv, massiv1) == 0){
k = 0;
break;
}
else {
k++;
}
}
if(k!=0) {
fprintf (opaa,"%s\n", massiv);
r++;
}
dict =fopen(argv[1], "r");
}
/*Сравнили файл inputnew и dict и переписали лишние слова в файл output*/
fclose(text);
fclose(neww2);
fclose(dict);
fclose(opaa);
if (r > 0) {printf("%s","Warning");} else {printf("%s","Ok");};
/*Задали условия для выходных данных*/
return 0;
}


