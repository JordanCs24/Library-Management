#include <stdio.h>

// fn = file name
// fc = file change 
//Basically what the user wants to change in the file


void change(char fn[100], char fa[100]){
    FILE *fp;
/*
    printf("What file are you looking for: ");
    scanf("%c", fn);
    fgets(fn, sizeof(fn), fp);

*/
    fp = fopen(fn,"r");
    if(fp == NULL){
        printf("\nThe title of the book you entered was not found\n");
        printf("\nTry input again");
        while(fp == NULL){
            printf("\n--TRY AGAIN--\n");
            printf("\nWhat is the title of the book: ");
            fgets(fn, sizeof(fn), stdin);
            printf("\nWhat is the author of '%s': ",fn);
            fgets(fn, sizeof(fn), stdin);
        }
    }

    freopen(fn, "r+", fp);

    int whatToChange;
    printf("\nWhat part of the file do you want to be changed:\nPress 1 for title\npress 2 for author\npress 3 for price\npress 4 for genre ");
    scanf("%d", whatToChange);
    printf("Your input was: %d",whatToChange);



    readFile(fp);


    fclose(fp);
    
}

