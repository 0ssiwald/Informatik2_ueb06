/***************************************
* database.h contains all functions for
loading and saving data to the .xml file
****************************************/
#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#define FILENAME "teams.xml"  // Name of the File were the Teams are stored

/***************************************
* int save()
* Saves all Data to the .xml File FILENAME
* Result: truth value if save was succesfull
***************************************/
int save();


/***************************************
* int load()
* Loads all Data to the .xml File FILENAME
* Result: truth value if load was successfull
***************************************/
int load();

#endif // DATABASE_H_INCLUDED
