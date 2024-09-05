#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// FIX THE SEARCHFORBOOK FUNCTION

//searching for the book
void searchForBook(char title[100],char author[100]){

    FILE *fp;
    fp = fopen(title,"r");

    if(fp == NULL){
        printf("\nThe title of the book you entered was not found\n");
        printf("\nTry input again");
        
        while(fp == NULL){
            printf("\n--TRY AGAIN--\n");
            printf("\nWhat is the title of the book: ");
            fgets(title, sizeof(title), stdin);
            printf("What is the author of '%s': ",title);
            fgets(author, sizeof(author), stdin);
        }
    }

    freopen(title, "r", fp);

    readFile(fp);


    fclose(fp);
    
}
