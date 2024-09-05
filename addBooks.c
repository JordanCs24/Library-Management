#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> //Allows the isDigit()
#define BUFFER_SIZE 1000

    //This source file/function gets the books TITLE, 
    //AUTHOR, PAGE COUNT, & PRICE

struct books{
    int pages,price;
    char title[50],author[50],genre[50];  
    };
    
void readFile(FILE * fp){
    char ch;

    do{
        ch = fgetc(fp);
        putchar(ch);
    } while (ch != EOF);
}

void addBook(){
    
    //declares the varies variables needed to run the function 
    struct books book;
    char dataToAppend[1000];

    //Creates a file to add a new book
    FILE *fp;

    printf("\nTitle of Book: ");
    scanf("%c", book.title); //This is needed in order for the file to be opened and created
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = 0; // remove line character 
    

    
    fp = fopen(book.title,"a"); //The file is named after the title of the book

    //return Null if the file isn't able to be opened
    if (fp == NULL){
        printf("\nUnable to open '%s' file\n", book.title);
        printf("Please check whether file exists and you have written privilege.\n");
        exit(EXIT_FAILURE);
    }

    // Adding the data needed for the book
    printf("\nEnter Author name: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = 0; // Remove newline character

    printf("\nEnter pages #: ");
    scanf("%d", &book.pages);

    printf("\n Enter price $: ");
    scanf("%d", &book.price);

    printf("\nEnter book genre: ");
    scanf("%c",book.genre);
    fgets(book.genre, sizeof(book.genre), stdin);
    book.author[strcspn(book.author, "\n")] = 0; // Allows for it to be spaces in the string

    fflush(stdin);
    fgets(dataToAppend, 1000, stdin);
//------------------------------------------------------

    /* Append data to file */
    snprintf(dataToAppend, sizeof(dataToAppend), "Title: %s\nAuthor: %s\nPages: %d\nPrice: %d\nGenre: %s\n",
            book.title, book.author, book.pages, book.price, book.genre);
    
    fputs(dataToAppend, fp);

    /* Reopens file in read mode to print file contents */
    fp = freopen(book.title, "r", fp);

    printf("\nSuccessfully appended data to file. \n");
    printf("Changed file contents: \n\n");
    readFile(fp);


    fclose(fp);
}