#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book_info{

    int id;
    char name[50];
    char author[50];
    int quantity;
    int rack;
};

struct login{
    char username[50];
    char password[50];
};

struct Book_info a;

FILE *file;

void headMessage();
void headMessage2();
void Login ();
void MainMenu();
void addBook();
void SearchForABook();
void CheckOutABook();
void ReturnABook();
void RenewABook();
void ManageBookInventory();
void Check_Library_Records();
void Update_Library_Records();
void Change_Username_Password();

int main (){

    headMessage();
    headMessage2();
    printf("\n\n\n");
    Login();

}

void headMessage()
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t----------------------------------------------------------------------------");
    printf("\n\n\n");
}

void headMessage2(){

    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n");

}

void Login (){
    char Username[50];
    char Password[50];
    FILE *lib;
    lib = fopen("LOGIN.txt", "r");
    struct login user;
    printf("Enter your username: ");
    fflush(stdin);
    gets(Username);
    printf("\n\nEnter your password: ");
    fflush(stdin);
    gets(Password);

    while (fread(&user,sizeof(user),1,lib)){
        if (strcmp(Username,user.username)==0 && strcmp(Password,user.password)==0){
            printf("Successful log in....");
                system("cls");
                MainMenu();
}
        else {
            printf("\n\nPlease enter correct Username & Password!! Try again!!\n\n");
            Login();
        }
    }
    fclose(lib);
}

void MainMenu(){

    int Choose;
    
    system("cls");
    headMessage();
    headMessage2();

    printf("\n\nChoose one of the options:\n\n");
    printf("1. Add A New Book\n");
    printf("2. Search For A Book\n");
    printf("3. Check Out A Book\n");
    printf("4. Return Your Book\n");
    printf("5. Renew A Book\n");
    printf("6. Manage Book Inventory\n");
    printf("7. Change Username & Password\n");
    printf("8. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &Choose);
    
    switch (Choose){
        case 1 : addBook();
                break;
        case 2 : SearchForABook();
                break;
        case 3 : CheckOutABook();
                break;
        case 4 : ReturnABook();
                break;
        case 5 : RenewABook(); 
                break;
        case 6 : ManageBookInventory();
                break;
        case 7 : Change_Username_Password();
                break;
        case 8 : exit(0);

        default : printf("\n\nError....WRONG INPUT!!!\n\n");        
    }

}

void SearchForABook(){
    system("cls");
    headMessage();
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  Search                   =");
    printf("\n\t\t\t        =                   For                     =");
    printf("\n\t\t\t        =                    A                      =");
    printf("\n\t\t\t        =                   Book                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n");

    int d,count = 0;

    file = fopen("books.dat","rb");

    printf("\nEnter Book's ISBN: ");
    scanf("%d",&d );

    while(fread(&a, sizeof(a),1,file) == 1){
        if(d == a.id){
            printf("\nThe Book is Found!\n");
            printf("\nBook Title : ");
            puts(a.name);
            printf("\nAuthor : ");
            puts(a.author);
            printf("\nISBN : %d\n",a.id);
            printf("\nQuantity : %d\n",a.quantity);
            printf("\nRack No : %d\n\n",a.rack);

            count = 1;
        }
    }

    if(count ==0){
        printf("\nBook is Not Found ! Try Again !!\n\n");
    }

    system("pause");
    MainMenu(); 
}
  
void addBook()
{
    system( "cls" );
    headMessage();
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                   Add                     =");
    printf("\n\t\t\t        =                    A                      =");
    printf("\n\t\t\t        =                 New Book                  =");
    printf("\n\t\t\t        =                  To The                   =");
    printf("\n\t\t\t        =                 Library                   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n");

    int d,count=0;

     
    file=fopen("books.dat","ab+");

    printf("\nEnter Book's ISBN: ");
    fflush(stdin);
    scanf("%d",&d);

    rewind(file);

    while(fread(&a, sizeof(a),1,file) == 1 ){

    if(d ==a.id){
        printf("\n\n\t\t\t This book is already in the library\n\n");
        count=1;
    }
    }
    if( count == 1){
        printf("\n\nPress any key to continue.....\n");
        fflush(stdin);
        getchar();
        MainMenu();
    }
    a.id = d;

    printf("\nEnter Book's Title: ");
    fflush(stdin);
    gets(a.name);

    printf("\nEnter Author: ");
    fflush(stdin);
    gets(a.author);

    printf("\nEnter Quantity: ");
    fflush(stdin);
    scanf("%d",&a.quantity);

    printf("\nEnter Rack: ");
    fflush(stdin);
    scanf("%d",&a.rack);

    fseek(file,0, SEEK_END);
    fwrite(&a, sizeof(a),1,file);

    fclose(file);

    printf("\n\nThe Book Was Successfully Added!! Thank You :) !!\n\n");

    system("pause");
    MainMenu(); 
}

void CheckOutABook(){
    system("cls");
    headMessage();
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 Check                      =");
    printf("\n\t\t\t        =                  Out                       =");
    printf("\n\t\t\t        =                   A                        =");
    printf("\n\t\t\t        =                  Book                      =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n");

    int library_card_number;
    printf("Enter Your Library Card Number: ");
    scanf("%d", &library_card_number);

    int d,count = 0;

    file = fopen("books.dat","rb");

    printf("\nEnter Book's ISBN: ");
    scanf("%d",&d );

    while(fread(&a, sizeof(a),1,file) == 1){
        if(d == a.id){
            printf("\nBook's Details: !\n");
            printf("\nName : ");
            puts(a.name);
            printf("\nISBN : %d\n",a.id);
            printf("\n\nThanks For Picking Up This Book!! Enjoy Your Day!!\n\n");
            
            count = 1;
        }
    }

    if(count ==0){
        printf("\nYou Have Entered Invalid ISBN! Try Again !!\n\n");
    }
    system("pause");
    MainMenu(); 
}

void ReturnABook(){
    system("cls");
    headMessage();
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                   Return                  =");
    printf("\n\t\t\t        =                    Your                   =");
    printf("\n\t\t\t        =                   Book                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n");

    char return_Date[20],todays_Date[20];
    int d,library_card_number,count = 0;

    printf("Enter Your Library Card Number: ");
    scanf("%d", &library_card_number);

    file = fopen("books.dat","rb");

    printf("\nEnter Book's ISBN: ");
    scanf("%d",&d );

    while(fread(&a, sizeof(a),1,file) == 1){
        if(d == a.id){
            printf("\nEnter Return Date: ");
            fflush(stdin);
            gets(return_Date);
            printf("\nEnter Today's Date: ");
            fflush(stdin);
            gets(todays_Date);
        if (strcmp(todays_Date,return_Date) != 0){
            printf("\nYou Exceeded Due Date. You have to pay late fees.\n\n");
            break;
        }
        else {
            printf("\nThank You For Retuning The Book :)\n");
            break;
        } 
        }
            count = 1;
        }
    if(d != a.id){
        printf("\nYou Have Entered Invalid ISBN! Try Again !!\n\n");
    }
    system("pause");
    MainMenu(); 
}

void RenewABook(){

    system("cls");
    headMessage();
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 Renew                     =");
    printf("\n\t\t\t        =                   A                       =");
    printf("\n\t\t\t        =                  Book                     =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n");

    int library_card_number,book_ISBN;
    printf("Enter Your Library Card's Number: ");
    scanf("%d", &library_card_number);

    int d,count = 0;

    file = fopen("books.dat","rb");

    printf("\nEnter Book's ISBN: ");
    scanf("%d",&d );

    while(fread(&a, sizeof(a),1,file) == 1){
        if(d == a.id){
            printf("\nYour Request To Renew This Following Book Has Been Accepted!!\n");
            printf("\nBook Title : ");
            puts(a.name);
            printf("\nAuthor : ");
            puts(a.author);
            printf("\nISBN : %d\n",a.id);
            printf("\n\nEnjoy Your Book ! :)\n\n");
            break;

            count = 1;
        }
    }

    if(d != a.id){
        printf("\nYou've Entered INVALID ISBN NO !! Try Again !!\n\n");
    }
    system("pause");
    MainMenu();    
}

void ManageBookInventory(){
    system("cls");
    headMessage();
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 Manage                    =");
    printf("\n\t\t\t        =                  Book                     =");
    printf("\n\t\t\t        =                 Inventory                 =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n");
    
    int choose;
    char book_record, Issue_Date[50],lib_title[50],status[50];
    int lib_ISBN, Quantity;
    printf("Choose one of the options:\n\n");
    printf("1. Check Library Records\n");
    printf("2. Enter A New Record\n");
    printf("3. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choose);

    switch (choose){
        case 1 : Check_Library_Records();
                break;
        case 2 : Update_Library_Records();
                break;
        case 3 : exit(0);

        default : printf("\n\nError..WRONG INPUT!!!\n\n");
                break;
    }   
}

void Check_Library_Records(){
    system("cls");
    headMessage();
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 Check                     =");
    printf("\n\t\t\t        =                Library                    =");
    printf("\n\t\t\t        =                 Record                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n");

    char book_record;
    FILE *fp;
    fp = fopen("book_record.txt", "r");
        book_record = fgetc(fp);
    while (book_record != EOF){
        printf("%c", book_record);
        book_record = fgetc(fp);
    }
    printf("\n");

    fclose(fp);
    system("pause");
    MainMenu(); 
}

void Update_Library_Records(){
    system("cls");
    headMessage();
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 Update                    =");
    printf("\n\t\t\t        =                  Book                     =");
    printf("\n\t\t\t        =                 Record                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n");

    char book_record,lib_title[50],Issue_Date[50],status[50];
    int lib_ISBN;

    FILE *fp;
    fp = fopen("book_record.txt", "a");

    printf("Enter Title: ");
    fflush(stdin);
    gets(lib_title);
    printf("\nEnter ISBN: ");
    scanf("%d", &lib_ISBN);
    printf("\nEnter Issue Date: ");
    fflush(stdin);
    gets(Issue_Date);
    printf("\nEnter Status: ");
    fflush(stdin);
    gets(status);
    
    fprintf(fp,"\n%s", lib_title);
    fprintf(fp,"%24d", lib_ISBN);
    fprintf(fp,"%12s", Issue_Date);
    fprintf(fp,"%16s", status);

    printf("\nThe record has been updated!!\n\nThank you :)\n\n");

    fclose(fp);
    system("pause");
    MainMenu(); 
}

void Change_Username_Password (){
    system("cls");
    headMessage();
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 Change                    =");
    printf("\n\t\t\t        =                Username &                 =");
    printf("\n\t\t\t        =                 Password                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n");
    FILE *lib;
    lib = fopen("logIn.txt", "w");
    struct login user;
    printf("\n\nEnter new username : ");
    fflush(stdin);
    gets(user.username);
    printf("\nEnter new password : ");
    fflush(stdin);
    gets(user.password);
    fwrite(&user,sizeof(user),1,lib);
    printf("\n\nUsername & Password Successfully Updated!!\n\nLog In Again.....\n\n");
    fclose(lib);
    Login();
}
