/*******************************************
* includes functions that can be called by the
* menu regarding Teams and Players
********************************************/

//#ifndef TEAMS_H_INCLUDED
//#define TEAMS_H_INCLUDED
/****************************************
* void createTeam()
* Asks the User to input Data like Name of Team
* Calls createPlayer()
****************************************/
void createTeam();

/****************************************
* void createPlayer()
* Gets called by createTeam()
* Asks the User to input Data for One Player like Name
****************************************/
void createPlayer();

/*******************************************
* void deleteTeam()
* lists all teams and lets the user select a team to delete
********************************************/
void deleteTeam();

/*******************************************
* not finished yet
********************************************/
void deletePlayer();

/*******************************************
* not finished yet
********************************************/
void searchPlayer();

/*******************************************
* void sortTeams()
* lists possible sort functions and lets the user selcet one
********************************************/
void sortTeams();

/****************************************
* void listTeams()
* Dispalys all Teams with the Players in the Console
* Calls listOneTeam()
****************************************/
void listTeams();

/*******************************************
* void freeTeams()
* frees all allocated storage
********************************************/
void freeTeams();

//#endif // TEAMS_H_INCLUDED
