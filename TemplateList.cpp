/*
 *     Author : The Alex Camejo
 *     Last Modifed : Decemeber 17 , 2013 5:09PM EST
 *     Description: A simple template link list that
 *                  utilizes "smart nodes" to complete
 *                  list methods.Tested using CATCH
 *                  Unit Testing Framework (includes not included)
 */


#ifndef _TEMPLATELIST_CPP_
#define _TEMPLATELIST_CPP_
#include "TemplateList.h"
#include  <string>
//==========================PREPEND======================

template <class T>
void TLinkedList<T> :: prepend(T value){
  listSize++;                            // Increments list size since a node is added to the list                  
  node * temp = new node(value);
  temp->next = head;
  head = temp;
}

//==========================REMOVE================================

template <class T>
void TLinkedList<T> :: remove(T value){
  node * check = search(value); //Searches to be sure the value is in the list; If it isn't, or list is empty, search will give correct outputs.
  if(check){                    // If the value was found in the list
    listSize--;                 // Value will be removed; list size is smaller.
    if(head->data == value){
      node * temp = head;
      head = head->next;
      delete head;
      return;
    }
    else{
       head->remove(value);
    }
  }
  else{                     // Value not found or list empty
    return;                 // Do nothing
  }
}



template <class T>
void TLinkedList<T> :: node :: remove(T value ){
  if(next-> data == value){
    node * temp = next;
    next = next->next;
    delete temp;
    return;
  }
  else{
    return next -> remove(value);
  }
}

//==============SIZE=====================
template <class T>
int TLinkedList<T> :: size(){
  return listSize;
}


//============PRINT======================

template <class T>
void TLinkedList<T> :: print(){
  if(!head){
    std::cout << "Error: List is empty" << std::endl;
    return;
  }
  else{
    head->print();
  }
}

template <class T>
void TLinkedList<T> :: node :: print(){
  if(!next){
    std::cout << data << std::endl;
    return;
  }
  else{
    std::cout << data << " : " ;
    next->print();
    return;
  }
}

//============APPEND====================
template <class T>
void TLinkedList<T> :: append(T value){
  if(!head){
    prepend(value);   //If list is empty, simply prepend the value.
    return;
  }
  else{
    listSize++;
    head->append(value);
  }
}

template <class T>
void  TLinkedList<T> :: node :: append(T value){
  if(next){                         //If there is a node ahead of this node
    next->append(value);            //call append on next node until there is no more nodes in the list(Meaning this node is last node)
  }
  else{
    node * temp = new node(value);
    next = temp;
    return;
  }
}
    
//==============SEARCH===================
template <class T>
typename TLinkedList<T>::node * TLinkedList<T> :: search(T value){
   if(!head){
    std::cerr << "Error: List is empty" << std::endl;
    return NULL;
  }
  if(head->data == value){  //If head's data is the value searched for
    return head;     
  }
  else{
    return head->search(value);
  }
 
}

template <class T>
typename TLinkedList<T>::node * TLinkedList<T> :: node :: search(T value){
  if(data == value){
    return this;
  }
  if(!next){
    std::cerr << "Error: Value not in list" << std::endl;
    return NULL;
  }
  else{
    return next->search(value);
  }
}


//===========TOSTRING=============
template <class T>
std::string TLinkedList<T> :: toString(){
  if(!head){
    std::cout << "Error : List is empty" << std::endl;
  }
  else{
    std::string output;
    return head->toString(output);
  }
}

template <>   
std::string TLinkedList<int> :: node :: toString(std::string output){   //This toString used if class T == int
  if(!next){
    output = output + std::to_string(data);
    return output;
  }
  else{
    output = output + std::to_string(data) + " : "; 
    return next->toString(output);
  }
  
}

template<class T>
std::string TLinkedList<T> :: node :: toString(std::string output){       //This toString used if class T != int
  if(!next){
    output = output + data;
    return output;
  }
  else{
    output = output + data + " : ";
    return next->toString(output);
  }
}

//=================POP=================

template <class T>
typename TLinkedList<T> :: node *  TLinkedList<T> :: pop(T value){
  remove(value);
  node * returnNode = new node(value);   //Safe to make : Value already confirmed to be in list.
  return returnNode;
  
 }

#endif //_TEMPLATELIST_CPP_
