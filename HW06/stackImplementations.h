#ifndef STACKIMPLEMENTATIONS_
#define STACKIMPLEMENTATIONS_



template <class ItemType>

class MyStack {
public:
  /** Sees wether this stack is is empty
    \@return True if the stack is empty, or false if note */
  virtual bool isEmpty() = 0;

  /** Adds a new entry to the top of this stack.
  \@post If the operation was succesful, newEntry is at the top of the stack.
  \@param  newEntry The object to be added as a new entry.
  \@return  True if the addition is succesful or false if not */
  virtual bool push(const ItemType& newEntry) = 0;

  /** Removes the top of this stack.
  \@post If the operation was succesful, the top of the stack has been removed.
  \@return True if the removal is succesful or false if not */
  virtual bool pop() = 0;

  /** Returns a copy of the top of this stack.
  \@pre  The stack is not empty.
  \@post  A copy of the top of the stack has been returned, and
      the stack is unchanged.
  \@return  A copy of the top of the stack. */
  virtual ItemType peek() const = 0;

  /** Destroys this stack and frees its assigned memory. */
  virtual ~MyStack() {  }

};



# endif
