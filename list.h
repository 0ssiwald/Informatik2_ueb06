#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

/****************************************
* int insertDListElement(sTeam *)
* inserts an Element in the double linked list sTeams sorted by Name
* Parameters: 1. Pointer to the element that should be included
* Result: is the element successful included in the List
****************************************/
int insertDListElement(sTeam *);

/****************************************
* sTeam *removeDListElement(sTeam *)
* removes an Element in the double linked list sTeams DOSENT FREE STORAGE!
* Parameters: 1. Pointer to the element that should be removed
* Result: Pointer to the removed Element
****************************************/
sTeam *removeDListElement(sTeam *);

#endif // LIST_H_INCLUDED
