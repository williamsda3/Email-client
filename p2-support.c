////////////////////////////////////////////////////////////////////////
//
// File           : p2-support.c
// Description    : Creating a E-mail client using structs. Fall 2022
// Author         : David Williams
// Date           : 11/11/2022

// Add necessary include statements (I added for you!) *thank you!
#include "p2-support.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////
// Function Definitions
// //////////////////////////////////////////

void initialize(struct Mailbox *ib)
{
  // allocate memory for 2000 emails
  ib->emails = malloc(sizeof(Email) * MAILBOX_SIZE);
  ib->size = 0;

  create_email("asonmez@mail.com", user_email, "Welcome to your inbox.",
               "Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.",
               11, 20, 2020, ib);
  create_email("mmartinez@mail.com", user_email, "Padding out your inbox.",
               "Yet another email just to pad out your inbox, have fun!",
               11, 30, 2020, ib);
  create_email("dboyle@mail.com", user_email, "3rd email!",
               "Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!",
               12, 2, 2020, ib);
  create_email("cbluer@mail.com", user_email, "4th email!",
               "Content of fourth email. More coding, more fun!",
               12, 8, 2020, ib);
  create_email("cboyle@mail.com", user_email, "5th email!",
               "Content of fifth email. Coding is fun-tastic!",
               12, 18, 2020, ib);
  create_email("sblack@mail.com", user_email, "6th email!",
               "Content of sixth email. Coding is fun-tastic!",
               1, 1, 2021, ib);
  create_email("sblack@mail.com", user_email, "7th email!",
               "Body of seventh email. Coding is fun-tastic!",
               1, 5, 2021, ib);
  create_email("sblack@mail.com", user_email, "8th email!",
               "Body of eighth email. Coding is fun-tastic!",
               2, 15, 2021, ib);
  create_email("sblack@mail.com", user_email, "9th email!",
               "Body of ninth email. Coding is fun-tastic!",
               2, 25, 2021, ib);
  create_email("dboyle@mail.com", user_email, "Last email!",
               "Body of tenth email. Coding is fun-tastic!",
               3, 15, 2021, ib);
}

void display_inbox_menu(struct Mailbox *ib)
{

  int i;

  while (1)
  {

    display_menu(ib);

    scanf("%d", &i);
    switch (i)
    {
    case 1:
      show_inbox(ib);

      break;

    case 2:

      show_inbox_by_id(ib);

      break;

    case 3:

      sort_by_sender(ib);

      break;

    case 4:

      sort_by_ID(ib);

      break;

    case 5:

      search_by_keyword(ib);

      break;

    case 6:

      delete (ib);

      break;

    case 7:
      printf("Exiting e-mail client - Good Bye!\n");
      free(ib->emails);
      return 0;
      break;
    default:
      printf("Unrecognized option, please try again\n");
      // free(ib);
    }
  }
}
void create_email(char *aSender, char *aReceiver, char *aSubject, char *body, int aMonth, int aDay, int aYear, struct Mailbox *inBox)
{

  strcpy(inBox->emails[inBox->size].sender, aSender);
  strcpy(inBox->emails[inBox->size].receiver, aReceiver);
  strcpy(inBox->emails[inBox->size].subject, aSubject);
  strcpy(inBox->emails[inBox->size].body, body);

  inBox->emails[inBox->size].sentDate.month = aMonth;
  inBox->emails[inBox->size].sentDate.day = aDay;
  inBox->emails[inBox->size].sentDate.year = aYear;
  inBox->emails[inBox->size].ID = inBox->size;

  inBox->size++;
};

void show_inbox(struct Mailbox *ib)
{
  printf("\n");
  int j;
  printf("ID   SENDER--------------  MM/DD/YYYY  SUBJECT--------\n");
  printf("--   --------------------  --/--/----  ---------------\n");
  for (j = 0; j < ib->size; j++)
  {
    char send[21];
    char sub[16];
    strncpy(send, ib->emails[j].sender, 20);
    strncpy(sub, ib->emails[j].subject, 15);

    printf("%02d - %-20s- %02d/%02d/%04d - %s\n", ib->emails[j].ID, send, ib->emails[j].sentDate.month, ib->emails[j].sentDate.day, ib->emails[j].sentDate.year, sub);
  }
}

void show_inbox_by_id(struct Mailbox *ib)
{
  printf("\n");
  int idChoice;
  printf("Enter the ID of the email you want to read:\n");
  scanf("%d", &idChoice);
  // printf("\n");
  printf("%s - %s\n", ib->emails[idChoice].sender, ib->emails[idChoice].subject);
  printf("Email Received on:  %02d/%02d/%04d\n\n", ib->emails[idChoice].sentDate.month, ib->emails[idChoice].sentDate.day, ib->emails[idChoice].sentDate.year);
  printf("%-20s\n", ib->emails[idChoice].body);
}

void sort_by_sender(struct Mailbox *ib)
{
  printf("\n");
  int k;
  int l;
  for (k = 0; k < ib->size; ++k)
  {
    for (l = k + 1; l < ib->size; ++l)
    {
      if (strcmp(ib->emails[k].sender, ib->emails[l].sender) > 0)
      {
        // strcpy(temp, ib->emails[k].sender);
        struct Email temp = ib->emails[k];
        ib->emails[k] = ib->emails[l];
        ib->emails[l] = temp;
      }
    }
  }
}

void sort_by_ID(struct Mailbox *ib)
{
  printf("\n");
  int m;
  int n;

  for (m = 0; m < ib->size; ++m)
  {
    for (n = m + 1; n < ib->size; ++n)
    {
      if (ib->emails[m].ID > ib->emails[n].ID)
      {

        int idTemp = ib->emails[m].ID;
        struct Email temp2 = ib->emails[m];
        ib->emails[m].ID = ib->emails[n].ID;
        ib->emails[m] = ib->emails[n];
        ib->emails[n].ID = idTemp;
        ib->emails[n] = temp2;
      }
    }
  }
}

void search_by_keyword(struct Mailbox *ib)
{
  printf("\n");
  int o;
  char key[11];
  printf("Enter the keyword that you are searching for:\n");
  scanf("%s", key);
  printf("\n");

  printf("ID   SENDER--------------  MM/DD/YYYY  SUBJECT--------\n");
  printf("--   --------------------  --/--/----  ---------------\n");

  for (o = 0; o < ib->size; o++)
  {
    char *tempSend = strstr(ib->emails[o].sender, key);
    char *tempSub = strstr(ib->emails[o].subject, key);
    char *tempBody = strstr(ib->emails[o].body, key);
    if (tempSend || tempBody || tempSub)
    {

      printf("%02d - %-20s- %02d/%02d/%04d - %s\n", ib->emails[o].ID, ib->emails[o].sender, ib->emails[o].sentDate.month, ib->emails[o].sentDate.day, ib->emails[o].sentDate.year, ib->emails[o].subject);
    }
  }
}

void delete (struct Mailbox *ib)
{
  printf("\n");
  int del;
  int p;
  int q;
  int r;
  printf("Enter the ID of the e-mail you want to delete:\n");

  scanf("%d", &del);
  //  printf("\n");
  for (p = 0; p < ib->size; p++)
  {
    if (ib->emails[p].ID == del)
    {

      for (q = p; q < ib->size - 1; q++)
      {

        ib->emails[q] = ib->emails[q + 1];
      }
      ib->size--;
    }
  }
  printf("Email with ID = %d is deleted\n", del);
}

void display_menu(struct Mailbox *ib)
{
  printf("\n");
  printf("***************   %s Inbox   ***************\n", user_email);
  printf("***************   Total Inbox: %04d           ***************\n\n", ib->size);
  printf("1. Show Inbox\n");
  printf("2. Show Email by ID\n");
  printf("3. Sort Inbox by Sender\n");
  printf("4. Sort Inbox by ID\n");
  printf("5. Search Inbox by Keyword\n");
  printf("6. Delete\n");
  printf("7. Exit Inbox\n\n");
}
