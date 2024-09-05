#include <stdio.h>
#include <stdlib.h>
#include "addBooks.c"
#include "searchForBook.c"
#include "changeFunction.c"

/*
    When the user tries to display all books of a particular author then the user must have to enter the name of the author:
    Enter the author’s name:
    The E-Library Management System must be also capable of counting all the books available in the library.

*/

int main(){

    int oneOrTwo;
    char title[100];
    char author[100];
    printf("Welcome to Shadow Library!");
    printf("Press 1 if you would like to add a book\nPress 2 to search for a book\n Press 3 to change the data about a book:  ");
    scanf("%d", &oneOrTwo);

    switch(oneOrTwo){
        case 1:

            addBook();//function call 
            break;
        case 2: // if user wants to search for a specific book

            printf("What book are you searching for: ");
            scanf("%c", title);
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // remove line character 

            printf("Who is the author of the book: ");
            scanf("%c", author); 
            fgets(author, sizeof(author), stdin);
            author[strcspn(author, "\n")] = 0; // remove line character 

            searchForBook(title,author);//function call 
            break;

        case 3: // if user wants to change a specific part of the file
        
            printf("What book do you want to change: ");
            scanf("%c", title);
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // remove line character 

            printf("Who is the author of the book: ");
            scanf("%c", author); 
            fgets(author, sizeof(author), stdin);
            author[strcspn(author, "\n")] = 0; // remove line character 
            
            change(title, author); //function call 
            break;
    }
   

    
  
    

    return 0;
}