#include<stdio.h>
#include<string.h>


struct Book{
	char title[20];
	char Author_name[20];
	int publication_year;
	float price;
};


void display_books(struct Book books[], int count){
	
	for(int i=0;i<count;i++){
		printf("Book %d\n", i+1);
		printf("Title: %s\n", books[i].title);
		printf("Author Name: %s\n", books[i].Author_name);
		printf("Publication Year: %d\n", books[i].publication_year);
		printf("Price: %.2f$\n", books[i].price);
	}
}

void search_book_by_title(struct Book book[], int count, char title[20]){
	int book_available = 0;
	
	for(int i=0; i<count; i++){
		if(strcmp(book[i].title, title) == 0){
			book_available = 1;
			printf("\nThe Book is availale ad details are: \n");
			printf("Book %d\n", i+1);
			printf("Title: %s\n", book[i].title);
			printf("Author Name: %s\n", book[i].Author_name);
			printf("Publication Year: %d\n", book[i].publication_year);
			printf("Price: %.2f$\n", book[i].price);
		}		
	}
	
	if(!book_available){
		printf("No book is available by the title '%s'", title);
	}
}


void search_book_by_author(struct Book book[], int count, char author[20]){
	int book_available = 0;
	
	for(int i=0; i<count; i++){
		if(strcmp(book[i].Author_name, author) == 0){
		printf("\nThe Books written by '%s' are : \n", book[i].Author_name);
			book_available = 1;
			printf("Book %d\n", i+1);
			printf("Title: %s\n", book[i].title);
			printf("Author Name: %s\n", book[i].Author_name);
			printf("Publication Year: %d\n", book[i].publication_year);
			printf("Price: %.2f$\n", book[i].price);
		}		
	}
	
	if(!book_available){
		printf("No book is available of the Author '%s'", author);
	}
}



int main(){
	
	struct Book books[3];
	char user_title[20];
	char user_author[20];
	int option;
	
	strcpy(books[0].title, "The Great Gatsby");
    strcpy(books[0].Author_name, "F. Scott Fitzgerald");
    books[0].publication_year = 1925;
    books[0].price = 10.99;

	strcpy(books[1].title, "To Kill a Mocking");
    strcpy(books[1].Author_name, "Harper Lee");
    books[1].publication_year = 1926;
    books[1].price = 10.99;
	
	strcpy(books[2].title, "Harry Potter");
    strcpy(books[2].Author_name, "J.k Rolling");
    books[2].publication_year = 2001;
    books[2].price = 100.99;
	
	
	printf("Welcome to library\n");
	while(1){
		printf("\n1) Display Books\n");
		printf("2) Search By Author Name\n");
		printf("3) Search by Title\n");
		printf("4) Exit\n");
		printf("Enter Your Choice >> ");
		scanf("%d", &option);
		switch(option){
			case 1:	
				display_books(books, 3);
				break;
			case 2:
				printf("Enter The Name Of Author: ");
				gets(user_author);
				fgets(user_author, 20,stdin);
				user_author[strcspn(user_author, "\n")] = 0;
				search_book_by_author(books, 3, user_author);
				break;
			case 3:
				printf("Enter The Title Of Book: ");
				gets(user_title);
				fgets(user_title, 20,stdin);
				user_author[strcspn(user_author, "\n")] = 0;
				search_book_by_title(books, 3, user_title);
				break;
			case 4:
				return 0;
		}
	}
	
	
}