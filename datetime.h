/*******************************************
* datetime.h is for working with the struct sDate
********************************************/
#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

/****************************************
* void printDate(sDate *)
* prints the full date on the screen
******************************************/
void printDate(sDate *);

/***************************************
* int getDate From String(char*, sDate *)
* Takes the input of the user and converts it
  into a Date struct stored in sDate format
* Parameters:  1. Pointer to begin of String
               2. Pointer of pointer to sDate where
               the converted date is stored
* Result: truth value if date is valid
***************************************/
int getDateFromString(char *, sDate **);

/****************************************
* int isDateValid(sDate *)
* checks if Day Month and Year are valid
  is called by getDateFromString
* Parameters : 1. Pointer to sDate where the Date is stored
* Result: truth value if date is valid
******************************************/
int isDateValid(sDate *);

/****************************************
* int isLeapYear(sDate *)
* checks if Year is leap year
  is called by isDateValid
* Parameters : 1. Pointer to sDate where the Date is stored
* Result: truth value if Year is leap year
******************************************/
int isLeapYear(sDate *);

#endif // DATETIME_H_INCLUDED
