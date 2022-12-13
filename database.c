#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "datetime.h"
#include "list.h"
#include "teams.h"
#include "tools.h"
#include "database.h"

void saveTeam(sTeam *, FILE*);
void savePlayer(sTeam*, int, FILE*);
void loadTeam(FILE *, char *);
void loadPlayer(FILE *, char *, sTeam *);

int save()
{
   FILE* File = NULL;
   File = fopen(FILENAME, "w"); //FILENAME defined in database.h
   if(File)
   {
      fprintf(File, "<Daten>\n");
      sTeam *currentTeam = FirstTeam;
     while(currentTeam)
     {
         saveTeam(currentTeam, File);
         currentTeam = currentTeam->Next;
     }
      fprintf(File, "</Daten>\n");
      fclose(File);
      return 1;
   }
   else
      return 0;
}

void saveTeam(sTeam *current_team, FILE* File)
{
   int player_index;

   fprintf(File, "   <Team>\n");
   fprintf(File, "      <Name>%s</Name>\n", current_team->Name);
   if(current_team->Trainer) //because Trainer input not mendatory
      fprintf(File, "      <Trainer>%s</Trainer>\n", current_team->Trainer);
   for(player_index = 0; player_index < current_team->NumberOfPlayers; player_index++)
     savePlayer(current_team, player_index, File);
   fprintf(File, "   </Team>\n");
}

void savePlayer(sTeam *current_team, int player_index, FILE* File)
{
   sPlayer *current_player = current_team->Players + player_index;
   sDate *bd = current_player->Birthday;

   fprintf(File, "      <Player>\n");
   fprintf(File, "         <Name>%s</Name>\n", current_player->Name);
   if(current_player->Birthday)  //because Birthday input not mendatory
      fprintf(File, "         <Birthday>%02i.%02i.%04i</Birthday>\n", bd->Day, bd->Month, bd->Year);
   fprintf(File, "         <TricotNr>%i</TricotNr>\n", current_player->ShirtNumber);
   fprintf(File, "         <Goals>%i</Goals>\n", current_player->GoalNumber);
   fprintf(File, "      </Player>\n");
}

int load()
{
   char Row[101];
   char *Row_begin = NULL;

   FILE *File = fopen(FILENAME, "r");
   if(File)
   {
      do
      {
         fscanf(File, "%100[^\n]\n", Row);   //why is the second \n so important???
         Row_begin = Row;
         while((*Row_begin == ' ' || *Row_begin == 9)) //to ignore Tabs and space at the beginning of a row
               Row_begin++;
         if(!strncmp(Row_begin, "<Team>", 6))        //strncmp returns 0 if string is found
         {
            loadTeam(File, Row);
         }
         if(feof(File)) //to test of end of file
            break;
      }while(strncmp(Row_begin, "</Daten>", 8));
      fclose(File);
      return 1;
   }
   else
      return 0;
}


void loadTeam(FILE *File, char *Row)
{
   char *Row_begin = NULL;
   int len;
   sTeam *currentTeam = calloc(1, sizeof(sTeam));

   if(currentTeam)
   {
      currentTeam->Name = NULL;
      currentTeam->Trainer = NULL;
      do
      {
         fscanf(File, "%100[^\n]\n", Row);
         Row_begin = Row;
         while((*Row_begin == ' ' || *Row_begin == 9)) //to ignore Tabs and space at the beginning of a row
            Row_begin++;
         if(!strncmp(Row_begin, "<Name>", 6) && !currentTeam->Name) // Only changing the Name of the Team when it is a 0 Pointer is necessary because else a name tag of a player can be read as Name tag for team
         {
            len = strlen(Row_begin + 6) - 7; //to get lenght of the row -<Name> and <\Name>
            if(!strncmp(Row_begin + 6 + len, "</Name>", 7)) //To test for the end tag
            {
               currentTeam->Name = calloc(len + 1, sizeof(char)); // +1 for \0 at the end
               if(currentTeam->Name)
                  strncpy(currentTeam->Name, Row_begin + 6, len);
            }
         }
         if(!strncmp(Row_begin, "<Trainer>", 9))
         {
            len = strlen(Row_begin + 9) - 10; //to get lenght of the row -<Name> and <\Name>
            if(!strncmp(Row_begin + 9 + len, "</Trainer>", 10)) //To test for the end tag
            {
               currentTeam->Trainer = calloc(len + 1, sizeof(char)); // +1 for \0 at the end
               if(currentTeam->Trainer)
                  strncpy(currentTeam->Trainer, Row_begin + 9, len);
            }
         }
         if(!strncmp(Row_begin, "<Player>", 9) && (currentTeam->NumberOfPlayers < MAXPLAYER))
         {
            loadPlayer(File, Row, currentTeam);
            currentTeam->NumberOfPlayers++;
         }
         if(feof(File)) //to test of end of file
         break;
      }while(strncmp(Row_begin, "</Team>", 7));
      if(!insertDListElement(currentTeam))
      {
         printf("Mannschaft %s konnte nicht angelegt werden \n", currentTeam->Name);
         waitForEnter();
      }
   }
}

void loadPlayer(FILE *File, char *Row, sTeam *currentTeam)
{
   sPlayer *current_player = currentTeam->Players + currentTeam->NumberOfPlayers;
   char *Row_begin = NULL;
   int len;
   current_player->GoalNumber = 0;  //setting default values if the file does not contain these infos
   current_player->ShirtNumber = 0;
   current_player->Birthday = NULL;

   do
   {
      fscanf(File, "%100[^\n]\n", Row);
      Row_begin = Row;
      while((*Row_begin == ' ' || *Row_begin == 9)) //to ignore Tabs and space at the beginning of a row
         Row_begin++;
      if(!strncmp(Row_begin, "<Name>", 6))
      {
         len = strlen(Row_begin + 6) - 7; //to get length of the row -<Name> and <\Name>
         if(!strncmp(Row_begin + 6 + len, "</Name>", 7)) //To test for the end tag
         {
            current_player->Name = calloc(len + 1, sizeof(char)); // +1 for \0 at the end
            if(current_player->Name)
               strncpy(current_player->Name, Row_begin + 6, len);
         }
      }
      if(!strncmp(Row_begin, "<Birthday>", 10))
      {
         len = strlen(Row_begin + 10) - 11;
         if(!strncmp(Row_begin + 10 + len, "</Birthday>", 11))
         {
            getDateFromString(Row_begin + 10, &(current_player->Birthday));
         }
      }
       if(!strncmp(Row_begin, "<TricotNr>", 10))
      {
         len = strlen(Row_begin + 10) - 11;
         if(!strncmp(Row_begin + 10 + len, "</TricotNr>", 11))
            current_player->ShirtNumber = atoi(Row_begin + 10);
      }
      if(!strncmp(Row_begin, "<Goals>", 7))
      {
         len = strlen(Row_begin + 7) - 8;
         if(!strncmp(Row_begin + 7 + len, "</Goals>", 8))
            current_player->GoalNumber = atoi(Row_begin + 7);
      }
      if(feof(File)) //to test of end of file
      break;
   }while(strncmp(Row_begin, "</Player>", 9));
}
