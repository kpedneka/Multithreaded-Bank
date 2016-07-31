#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bank.h"
/*
struct BankAcct_
{
  int status;
  char* owner;
  float balance;
  int inSession; //0 is true, 1 is false
};
*/
 //typedef struct BankAcct_* BankAcct;


//BankAcct AllAccounts [20];
//should be a pointer to an array of pointers (size 20)
 //struct BankAcct_** AllAccounts = (struct BankAcct_**)malloc(sizeof(struct BankAcct_*)*20);


//this function creates a new bank account
//cannot be called by a user in a session
//can only be called by someone not in a session


int open(char* name, struct BankAcct_** AllAccounts)
{
  
  int i = 0;
  for(i = 0; i<20; i++)
    {
      if(AllAccounts[i]==NULL)
	{
	  struct BankAcct_* ba = (struct BankAcct_*)malloc(sizeof(struct BankAcct_));
	  ba->owner = (char *)malloc(sizeof(strlen(name))+1);
	  strcpy(ba->owner, name);
	  ba->balance = 0.00;
	  ba->inSession = 1; //0 means true
	  AllAccounts[i] = ba;
	  printf("SUCCESS: Account: %s Opened Succesfully\n",AllAccounts[i]->owner);
	  return 0;
	}
    }

  printf("FAIL: Accounts all Filled\n");
  return 1;
  
}

//this function sets flag for inSession
//indicates that an account is currently
//being used
/** 1 ACCOUNT CAN ONLY HAVE 1 SESSION **/
int start(char* name, struct BankAcct_** AllAccounts)
{
  int i = 0;
  for(i = 0; i<20; i++){
    if(AllAccounts[i]!=NULL && strcmp(AllAccounts[i]->owner,name)==0){
      if(AllAccounts[i]->inSession == 0){
	printf("FAIL: Account: %s Already in Session\n",AllAccounts[i]->owner);
	return 1;
      }
      else{
	AllAccounts[i]->inSession = 0;
	printf("SUCCESS: Account: %s Started Succesfully\n", AllAccounts[i]->owner);
	return 0;
      }
    }
  }
  
  printf("FAIL: Accounts does not Exist\n");
  return 1;

}


//changes the balance of an account
//return 0 if successful, 1 if not
/** CAN ONLY BE CALLED IF INSESSION FLAG IS TRUE **/
int credit(char* name, float amount, struct BankAcct_** AllAccounts)
{
  int i = 0;
  for(i = 0; i<20; i++){
    if(AllAccounts[i]!=NULL && strcmp(AllAccounts[i]->owner,name)==0){
      if(AllAccounts[i]->inSession == 0){
	AllAccounts[i]->balance+=amount;
	printf("SUCCESS: Account: %s credited %f for total: %f\n", AllAccounts[i]->owner,amount,AllAccounts[i]->balance);
	return 0;
      }
      else{
	printf("FAIL: Account: %s Started NOT in Session\n", AllAccounts[i]->owner);
	return 1;
      }
    }
  }
  
  printf("FAIL: Accounts does not Exist\n");
  return 1;
  
}

//changes the balance of an account
//return 0 if successful, 1 if not
/** CAN ONLY BE CALLED IF INSESSION FLAG IS TRUE **/
int debit(char* name, float amount, struct BankAcct_** AllAccounts)
{
  int i = 0;
  for(i = 0; i<20; i++){
    if(AllAccounts[i]!=NULL && strcmp(AllAccounts[i]->owner,name)==0){
      if(AllAccounts[i]->inSession == 0){
	AllAccounts[i]->balance-=amount;
	printf("SUCCESS: Account: %s credited %f for total: %f\n", AllAccounts[i]->owner,amount,AllAccounts[i]->balance);
	return 0;
      }
      else{
	printf("FAIL: Account: %s Started NOT in Session\n", AllAccounts[i]->owner);
	return 1;
      }
    }
  }
  
  printf("FAIL: Accounts does not Exist\n");
  return 1;

}

/** CAN ONLY BE CALLED IF INSESSION FLAG IS TRUE **/
int finish(char* name, struct BankAcct_** AllAccounts)
{
  int i = 0;
  for(i = 0; i<20; i++){
    if(AllAccounts[i]!=NULL && strcmp(AllAccounts[i]->owner,name)==0){
      if(AllAccounts[i]->inSession == 0){
	AllAccounts[i]->inSession = 1;
	printf("SUCCESS: Account: %s NOW  NOT in Session\n", AllAccounts[i]->owner);
	return 0;
      }
      else{
	printf("FAIL: Account: %s Already NOT in Session\n", AllAccounts[i]->owner);
	return 1;
      }
    }
  }
  
  printf("FAIL: Accounts does not Exist\n");
  return 1;

}

/** CAN ONLY BE CALLED IF INSESSION FLAG IS TRUE **/
struct BankAcct_* balance(struct BankAcct_** AllAccounts, char* name)
{
  struct BankAcct_* temp = NULL;
  int i = 0;
  for(i = 0; i<20; i++){
    if(AllAccounts[i]!=NULL && strcmp(AllAccounts[i]->owner,name)==0){
      printf("SUCCESS: Account %s Found\n",AllAccounts[i]->owner);
      temp = AllAccounts[i];
      return temp;
    }
  }
  
  printf("FAIL: Accounts does not Exist\n");
  return temp;
  
}

/** CAN ONLY BE CALLED IF INSESSION FLAG IS TRUE **/
int myexit(char* name)
{

  /** COMPLAIN IF ba NOT IN SESSION **/

  return 0;
}

/*
int main(int argc, char **argv)
{
  intialize(); 
  BankAcct ba = open("Kunal");

  printf("suh dude\nsize of struct BankAcct_ is : %ld\n", sizeof(struct BankAcct_));

  free(ba->owner);
  free(ba);
  return 0;
}
*/
