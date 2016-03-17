#include "item.h"


/****************************************************************************
**Function: Item constructor
**Description: sets name of item
**Parameters:string name1
**Pre-Conditions: -
**Post-Conditions: Items can be acquired
******************************************************************************/
Item::Item(string name1)
{
	
	name = name1;



}



/****************************************************************************
**Function:Item default constructor
**Description: -
**Parameters:-
**Pre-Conditions:-
**Post-Conditions:-
******************************************************************************/
Item::Item()
{


}



/****************************************************************************
**Function:getName
**Description: Returns name of item
**Parameters:-
**Pre-Conditions: Item needs to exist
**Post-Conditions: Item can be manipulated
******************************************************************************/
string Item::getName()
{

	return name;


}