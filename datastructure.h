/*******************************************
* datastructure.h contains all new data types
********************************************/

#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

#define MAXPLAYER 23


/************************************
* sDate data type for creating Dates
***********************************/
typedef struct
{
   int Day;
   int Month;
   int Year;
} sDate;

/************************************
* sPlayer contains infos about the player
***********************************/
typedef struct
{
   char *Name;
   sDate *Birthday;
   int ShirtNumber;
   int GoalNumber;
} sPlayer;

/************************************
* sTeam contains infos about the team
***********************************/
typedef struct sD
{
   char *Name;
   char *Trainer;
   int NumberOfPlayers;
   sPlayer Players[MAXPLAYER];
   struct sD *Next;
   struct sD *Prew;
} sTeam;

//Initialized in teams.c
extern sTeam *FirstTeam;
extern sTeam *LastTeam;


#endif // DATASTRUCTURE_H_INCLUDED

