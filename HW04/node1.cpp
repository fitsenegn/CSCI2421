// FILE: node1.cxx
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "node1.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5
{
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
	const node *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    ++answer;

	return answer;
    }

    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
	head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
	node *insert_ptr;

	insert_ptr = new node(entry, previous_ptr->link( ));
	previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
	node *cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
		return cursor;
	return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
	const node *cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
		return cursor;
	return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
	node *cursor;
	size_t i;

	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
	    cursor = cursor->link( );
	return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
	const node *cursor;
	size_t i;

	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
	    cursor = cursor->link( );
	return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
	node *remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->link( );
	delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
	node *remove_ptr;

	remove_ptr = previous_ptr->link( );
	previous_ptr->set_link( remove_ptr->link( ) );
	delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
	while (head_ptr != NULL)
	    list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
	head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list.
	if (source_ptr == NULL)
	    return;

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	source_ptr = source_ptr->link( );
	while (source_ptr != NULL)
	{
	    list_insert(tail_ptr, source_ptr->data( ));
	    tail_ptr = tail_ptr->link( );
	    source_ptr = source_ptr->link( );
	}
    }


/*List all elements from start words to end words.*/
  void list_piece(const node* start_ptr, const node* end_ptr,
                     node*& head_ptr, node*& tail_ptr)
   {
     // Handle the case of the empty list.
     if (start_ptr == NULL)
         return;

     // Make the head node for the newly created list, and put data in it.
     list_head_insert(head_ptr, start_ptr->data( ));
     tail_ptr = head_ptr;

     // Copy the rest of the nodes one at a time, adding at the tail of new list.
     start_ptr = start_ptr->link( );
     while (start_ptr != end_ptr)
     {
         list_insert(tail_ptr, start_ptr->data( ));
         tail_ptr = tail_ptr->link( );
         start_ptr = start_ptr->link( );
     }
         list_insert(tail_ptr, start_ptr->data( ));
         tail_ptr = tail_ptr->link( );
         start_ptr = start_ptr->link( );


   }

   /**Checks if the start node comes before the end node in the associated list
   *\return true if bounds are good, false if bounds are bad.*/
   bool list_bounds(const node* head, const node* start_ptr, const node* end_ptr){
      int startIndex = 0; //initialize to assume fail case
      int endIndex = -1;

      for(int i = 1; i < list_length(head); i++){
        if(list_locate(head, i) == start_ptr){
          startIndex = i;
          i = list_length(head); //skip
          break;
        }
      }

      for(int i = 1; i < list_length(end_ptr); i++){
        if(list_locate(head, i) == end_ptr){
          endIndex = i;
          i = list_length(head); //skip
          break;
        }
      }

      if(startIndex <= endIndex){
        return true;
      }
     return false;
   }


/**Insertion sort for linked list. Each element is isolated and inserted
  *new list at a sorted position. The old list is then set equal to the
  *sorted one.
  \@head_ptr is the head of the list to be sorted
  \@tail_ptr is the tail of the list to be sorted
*/
void list_sort(node*& head_ptr, node*& tail_ptr){
  node* sorted_list = NULL;

  //move through the unsorted list and insert each node sorted into new list
    node* cursor = head_ptr;
    node* next;
  while (cursor->link() != NULL){

       next = cursor->link(); //hold onto next link(link will change)

      // insert current in sorted linked list
      list_sortInsert(sorted_list, cursor);

      //jump to unsorted
      cursor = next;
  }
  list_sortInsert(sorted_list, cursor);

  tail_ptr = cursor;
  head_ptr = sorted_list; //roughly equivalent to a return :P

}





/** Insert the toSort node at the position designated by comparison operators
  \@param head is the head of this list
  \@param toSort is the node to be placed into the list of head*/
void list_sortInsert(node*& head, node* toSort)
{
    node* cursor;
    //If this is a bodyless list or new data is smaller than head,
    //the head is the new node.
    if (head == NULL){ //empty list
        toSort->set_link(head);
        head = toSort;
        return;
    }

    if(head->data() >= toSort->data()){ //data is smaller than head
        toSort->set_link(head);
        head = toSort;
        return;
    }

        cursor = head;

          //push forward until just before insertion
        while((cursor->link()!= NULL)
           && (cursor->link()->data() < toSort->data()))
          {    cursor = cursor->link();    }

        toSort->set_link(cursor->link()); //hang rest on new node
        cursor->set_link(toSort); //hang new node on previous node
    }


}
