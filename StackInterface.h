#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

template<class ItemType>
class StackInterface
{
public:
   /******************************************************************************/
	/* Function:   isEmpty
	/  Inputs:     none
	/  Outputs:    returns true if stack is empty or false if the stack is not empty 
	/             
	/  Purpose:   Check to see it the stack is empty 
	/             
	/******************************************************************************/
   virtual bool isEmpty() const = 0;
   
   /******************************************************************************/
	/* Function:   push
	/  Inputs:     newEntry, the object will be added as a new entry. 
	/  Outputs:    adds a new entry at the top of the stack and returns true 
	/             
	/  Purpose:    inserts an new entry ay the top of the stack 
	/             
	/******************************************************************************/
   virtual bool push(const ItemType& newEntry) = 0;
   
   /******************************************************************************/
	/* Function:   pop
	/  Inputs:     none
	/  Outputs:    returns True if the removal of the top of the stack was completed
   /              and removes top of sctack  
	/             
	/  Purpose:    Removes the top of stack
	/             
	/******************************************************************************/
   virtual bool pop() = 0;

   /******************************************************************************/
	/* Function:   peek
	/  Inputs:     none, makes certain stack is not empty
	/  Outputs:    returns a copy of the top of the stack 
	/             
	/  Purpose:    returns the value on the top of the stack  
	/             
	/******************************************************************************/
   virtual ItemType peek() const = 0;
   
   /** Destroys this stack and frees its assigned memory. */
   virtual ~StackInterface() { }
   
}; // end StackInterface
#endif