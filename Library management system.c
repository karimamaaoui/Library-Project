//library project
#include<stdio.h>
#include<conio.h>

//book Structure

typedef struct Book {
    char title[20];
    char author[20];
    int page;
    float price;
    }Book;

//Global book type pointer

Book *book;

//Global count variable
int count=0;
// Global variable for dynamic memory allocation
int size;

//Function to add new book
void addBook(){
    system("cls");
    system("color 57");
    printf("\n ************ Add New Book Detail ************");
    printf("\n Enter Book Title : ");
    gets(book[count].title);
    printf("\n Enter Book Author : ");
    gets(book[count].author);
    printf("\n Enter Book Price : ");
    scanf("%f",&book[count].price);
    printf("\n Enter Book Page : ");
    scanf("%d",&book[count].page);
    count++;
}

//Function to show all books record
void showAllBook(){
    int i;
    system("cls");
    system("color 71");
    printf("\t \t \n @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Books Details @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ");
    printf("\n \n \t \t --------------------------------------------------------------------------");
    printf("\n \n \t \t Book Title \t Book Author \t Book Price \t Book Page \t");
    printf("\n \n \t \t --------------------------------------------------------------------------");

    for( i=0; i<count ; i++)
    {
        printf("\n \t\t %s",book[i].title);
        printf("\t\t %s",book[i].author);
        printf("\t\t %f",book[i].price);
        printf("\t\t %d",book[i].page);
    }

}


//Function to search book by title
void searchBook(){
     system("cls");
    system("color DF");

    char btitle[10];
    int i;
    printf("\n Enter book title to be search :");
    gets(btitle);
    for( i=0; i<count ; i++)
    {
        if (stricmp(book[i].title,btitle)==0){
        system("cls");
        printf("\n\n\t \t ************ Books Details ************ \t\t \n\n");
        printf("\n\n\t \t Book Title : %s",book[i].title);
        printf("\n\t \t Book Author : %s",book[i].author);
        printf("\n\t \t Book Price : %f",book[i].price);
        printf("\n\t \t Book Page : %d",book[i].page);
        }
    }
}

//Function to update book by title
void updateBook(){

    char btitle[10];
    int i,j;
    Book temp;
    printf("\n Enter Book To be update :");
    gets(btitle);
    for( i=0; i<count ; i++)
    {
        if (stricmp(book[i].title,btitle)==0){
        system("cls");
        printf("\n\n\t\t ************ Books Details ************");
        printf("\n\n\t \t Book Title : %s",book[i].title);
        printf("\n\t \t Book Author : %s",book[i].author);
        printf("\n\t \t Book Price : %f",book[i].price);
        printf("\n\t \t Book Page : %d\n",book[i].page);

        printf("\n ************ Add New Book Detail ************");
        printf("\n Enter Book Title : ");
        gets(book[i].title);
        printf("\n Enter Book Author : ");
       // fflush(stdin);
        gets(book[i].author);
        printf("\n Enter Book Price : ");
        scanf("%f",&book[i].price);
        printf("\n Enter Book Page : ");
        scanf("%d",&book[i].page);

        }
    }
}

// fct remove book
void removeBook(){
    char btitle[10];
    int i,j;
    Book *temp;
    printf("\n Enter Book title to be remove :");
    gets(btitle);
      for( i=0; i<count ; i++)
        {
            if(stricmp(book[i].title,btitle)==0)
            {

                system("cls");
                printf("\n\n\t \t ************Remove Books Details ************ \t\t \n\n");
                printf("\n\n\t \t Book Title : %s",book[i].title);
                printf("\n\t \t Book Author : %s",book[i].author);
                printf("\n\t \t Book Price : %f",book[i].price);
                printf("\n\t \t Book Page : %d",book[i].page);
                for( j=i; j<count -1 ; j++)
                {
                    book=book+1;
                    count--;
                    return;
                }

            }


        }

}

void main(){

    int choice;
    printf("\n Enter Total No. of books you want to add in library \t");
    scanf("%d",&size);

    // create book array dynamic using size input by user
    book=(Book*) malloc(sizeof(Book)*size);
    do {
        system("cls");
        printf("\n 1.Add Book \n 2. Show All Books \n 3. Search Book \n 4. Update Book \n 5. Remove Book \n 6.exit ");
        printf("\n Enter choice \t");
        scanf("%d",&choice);
        fflush(stdin);

        switch(choice){
        case 1:
            addBook(); // FUNCTION call to add new book
            break;
        case 2:
            showAllBook(); // FUNCTION call to show all book
            break;

        case 3:
            searchBook(); // FUNCTION call to search book
            break;

        case 4:
            updateBook(); // FUNCTION call to update book
            break;

        case 5:
            removeBook(); // FUNCTION call to update book
            break;
        case 6:
            return;

        }
            getch();

      }while(1);

}
