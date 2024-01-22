#include<stdio.h>
#include<stdlib.h>
#include <string.h> // for strcmp() comparing strings

struct book
{
  int Book_no;
  char Book_name[100];
  char Author_name[100];
  int No_of_pages;
};
//1.Adding book details
void add_book(struct book *book) 
{
  printf("Enter the accession number: ");
  scanf("%d", &book->Book_no);
  printf("Enter the title: ");
  scanf("%s", book->Book_name);
  printf("Enter the author: ");
  scanf("%s", book->Author_name);
  printf("Enter the number of pages: ");
  scanf("%d", &book->No_of_pages);
  printf("\n");
}
//2.Display book details
void display_book(struct book *book) 
{
 /*printf("Book no: %d\n", book->Book_no);
  printf("Title: %s\n", book->Book_name);
  printf("Author: %s\n", book->Author_name);
  printf("No of pages: %d\n", book->No_of_pages);
  printf("\n");*/
  
  printf("  %d         %s          %s            %d\n",book->Book_no,book->Book_name,book->Author_name,book->No_of_pages);
}


//3.BOOK OF GIVEN AUTHOR
void list_books_by_author(struct book *books, int a, char *author) 
{
  for (int i = 0; i < a; i++) 
  {
    if (strcmp(books[i].Author_name, author) == 0) 
     {
      printf("Book name:%s \n",books[i].Book_name);
     }
  }
}
//4.LIST THE TITLE OF SPECIFIED BOOK
void list_title_of_specified_book(struct book *books, int a, char *title) {
  for (int i = 0; i < a; i++) 
  {
    if (strcmp(books[i].Book_name, title) == 0) 
      {
      printf("Book no:       Title:       Author:      No of pages:\n");
      display_book(&books[i]);
     }
  }
}
//5.COUNT NUMBER OF BOOKS

//6.TO LIST THE BOOK IN THE ORDER OF ACCESSION NUMBER
void list_books_in_order_of_accession_number(struct book *books, int a) 
{
  int i, j;
  struct book temp;

  for (i = 0; i < a-1; i++) 
  {
    for (j = i + 1; j < a; j++) 
    {
      if (books[i].Book_no > books[j].Book_no) 
      {
        temp = books[i];
        books[i] = books[j];
        books[j] = temp;
      }
    }
  }
  printf("Book no:       Title:       Author:      No of pages:\n");
  for (i = 0; i < a; i++) 
  {
      display_book(&books[i]);
  }
  
}
int main()
{
  int ch,n,length;
  int a=0;
  struct book *books;
  books = (struct book *)malloc(n * sizeof(struct book));
  char author[100], title[100];
      
  // menu driven program
  printf("***MENU CHOICE***\n");
  printf("PRESS 1.TO ADD BOOK DETAILS\n");
  printf("PRESS 2.TO DISPLAY BOOK DETAILS\n");
  printf("PRESS 3.TO DISPLAY BOOK OF GIVEN AUTHOR\n");
  printf("PRESS 4.TO LIST THE TITLE OF SPECIFIED BOOK\n");
  printf("PRESS 5.TO COUNT NUMBER OF BOOKS\n");
  printf("PRESS 6.TO LIST THE BOOK IN THE ORDER OF ACCESSION NUMBER\n");
  printf("PRESS 7.EXIT\n");
  while(1)
 {
  printf("Enter option: ");
  scanf("%d",&ch);
  //switch case
  switch(ch)
  {
    case 1:
     printf("How many books you want to add: ");
     scanf("%d",&n);
     for (int i = 0; i < n; i++) 
     {
       add_book(&books[a]);
       a++;
     }
     break;
    case 2:
     length = a;
     printf("           DISPLAYING BOOK DETAILS\n");
     printf("Book no:       Title:       Author:      No of pages:\n");
     for (int i = 0; i < length; i++) 
     {
      display_book(&books[i]);
     }
     break;
    case 3:
     printf("Enter the author: ");
     scanf("%s", author);
     list_books_by_author(books, a, author);
     break;
    case 4:
     printf("Enter the title: ");
     scanf("%s", title);
     list_title_of_specified_book(books,a,title);
     break;
    case 5:
     printf("Total no.of books:%d \n",a);
     break;
    case 6:
     list_books_in_order_of_accession_number(books,a);
     break;
    case 7:
     printf("Exiting..\n");
     free(books); // Free the allocated memory before exiting
     return 0;
    default:
     printf("invalid choice\n");
  }
 }
 
 return 0;
}
     
     
     
     
     
     
