A simple template linked list. 
List is singly linked and utilizes "smart nodes": Nodes that do most of the work in the list's methods as opposed to having the list itself executing it's method by using temporary nodes to iterate through the list.

This list supports the following methods:
prepend()   //Puts node at the head of list.
append()    //Puts node at the tail of list
remove()    //Removes a node
search()    //Searches list for node with appropriate data value.
size()      //Returns the number of elements in the list
print()     //Prints contents of the list to console in order starting from the Head
toString()  //returns the contents of the list as a string in the same order as print()
pop()       //returns a node's value, then deletes the node
