#ifndef CMSC257_P2SUPPORT_INCLUDED
#define CMSC257_P2SUPPORT_INCLUDED

#define MAILBOX_SIZE 2000
#define ADDRESS_SIZE 50
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
//Replace e@mail.com with your VCU email below
#define user_email "williamsda3@vcu.edu"
//add other define Macros as needed

typedef struct Email 
{
  char sender[ADDRESS_SIZE];
  char receiver[ADDRESS_SIZE];
  char subject[SUBJECT_SIZE];
  char body[BODY_SIZE];
  int ID;

   struct sent_date  
  {
    int month;
    int day;
    int year;
  }sentDate;
  
  //add other struct members as needed
  //consider adding a nested struct here
}Email;

 struct Mailbox
{
  int size;
  Email* emails;
  //add other sruct members as needed
};

///////////////////////////////////////////////////////////////////////////////
// This is a sample comment for the initialize function
// You should include a similar comment for each function declared within the 
// 	.h file
//
// Function     : initialize
// Description  : Initializes the database for CMSC257 project #2 by manually 
//                entering the records using create_email function
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void

void initialize(struct Mailbox *ib);



// Function     : display_inbox_menu
// Description  : Displays the menu for the email inbox 
//             
// Inputs       : struct Mailbox* ib - pointer to the database
// Outputs      : void
void display_inbox_menu(struct Mailbox *ib);




// Function     : create_email
// Description  : Creates an  instance of an email with the Sender, Receiver, Subject, as well as the date. The inbox is also delegated
//             
// Inputs       : struct Mailbox* ib - pointer to the database, char* aSender - the email of the sender, char* aReceiver - the email of the receiver, 
//                char* body - the contents of the email's body, int month - the numeric value of the email's month, int day - the numeric value of the email's day. int year - the year the email was sent
// Outputs      : void
void create_email(char* aSender, char* aReceiver, char* aSubject, char* body, int month, int day, int year, struct Mailbox* inBox);




// Function     : show_inbox
// Description  : Displays the menu for the email options for the inbox 
//             
// Inputs       : struct Mailbox* ib - pointer to the database
// Outputs      : void
void show_inbox(struct Mailbox* ib);




// Function     : show_inbox_by_ID
// Description  : Displays the information and contents of the email for the specified email ID
//             
// Inputs       : struct Mailbox* ib - pointer to the database
// Outputs      : void
void show_inbox_by_id(struct Mailbox* ib);






// Function     : sort_by_sender
// Description  : Sorts the emails list lexiogrphically by the sender's email address
//             
// Inputs       : struct Mailbox* ib - pointer to the database
// Outputs      : void
void sort_by_sender(struct Mailbox* ib);





// Function     : sort_by_ID
// Description  : Sorts the emails list by the sender's ID (lowest to highest)
//             
// Inputs       : struct Mailbox* ib - pointer to the database
// Outputs      : void
void sort_by_ID(struct Mailbox* ib);


// Function     : search_by_keyword
// Description  : Displays the occurences of the searched Keyword
//             
// Inputs       : struct Mailbox* ib - pointer to the database
// Outputs      : void
void search_by_keyword(struct Mailbox* ib);






// Function     : delete
// Description  : 
//             
// Inputs       : struct Mailbox* ib - pointer to the database
// Outputs      : void
void delete(struct Mailbox* ib);





// Function     : display_menu
// Description  : displays the menu with the option chioces
//             
// Inputs       : struct Mailbox* ib - pointer to the database
// Outputs      : void
void display_menu(struct Mailbox* ib);




#endif // CMSC257_P2SUPPORT_INCLUDED
