#include <stdio.h>
#include <string.h>
#include "datastructure.h"
#include "teams.h" // First and LastTeam definition
#include "list.h"


int insertDListElement(sTeam *New)
{
   sTeam *tmp = FirstTeam;

   if(FirstTeam == NULL) // if List is empty
   {
      FirstTeam = LastTeam = New;
      return 1;
   }
   if(strcmp(New->Name, FirstTeam->Name) <= 0) // if New is smaller than first element in list
   {
      FirstTeam = FirstTeam->Prew = New;
      return 1;
   }
   if(strcmp(New->Name, LastTeam->Name) >= 0) // if New is bigger than last element in list
   {
      New->Prew = LastTeam;
      LastTeam = LastTeam->Next = New;
      return 1;
   }
   while(tmp->Next) // while there is a succsessor in the list
   {
      if(strcmp(New->Name, tmp->Name) >= 0)
      {
         New->Prew = tmp;
         New->Next = tmp->Next;
         tmp->Next->Prew = New;
         tmp->Next = New;
         return 1;       //???
      }
      tmp = tmp->Next;
   }
   return 0;           // ???
}

sTeam *removeDListElement(sTeam *Rem)
{
   sTeam *tmp = FirstTeam;
   sTeam *res = FirstTeam->Next;

   if(FirstTeam == NULL) // if list is empty
      return 0;
   if(!strcmp(Rem->Name, FirstTeam->Name)) //????
   {
      FirstTeam = FirstTeam->Next;
      if(FirstTeam) // if FirstTeam is not the last element
         FirstTeam->Prew = NULL;
      else
         LastTeam = NULL;
      return tmp;
   }
   if(!strcmp(Rem->Name, LastTeam->Name)) // if the element to remove is the last one in the list
   {
      tmp = LastTeam;
      LastTeam = LastTeam->Prew;
      LastTeam->Next = NULL;
      return tmp;
   }
   while(res)
   {
      if(!strcmp(res->Name, Rem->Name))
      {
         tmp->Next = res->Next;
         res->Next->Prew = tmp;
         return res;
      }
      tmp = tmp->Next;
      res = res->Next;
   }
   return NULL;
}
