/***************************************************************************
 *   Copyright (C) 2016 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H

#include "linear_list.h"

template<class T>
class Single_Linked_list;

template< class T >
class List_single_node {
 friend class Single_Linked_list<T>;
 private:
	T _value;
	List_single_node<T> * _pNext;
};




template< class T >
class Single_Linked_list : public Linear_list<T, List_single_node<T>*>{
 public:
	typedef typename Linear_list<T, List_single_node<T>*>::value_type value_type;
	typedef typename Linear_list<T, List_single_node<T>*>::position position;

	// costruttori
	Single_Linked_list();
	Single_Linked_list(int);
	// costruttore per copia
	Single_Linked_list(const Single_Linked_list<T>& );
	//distruttore
	~Single_Linked_list();

	// operatori
	void create();
	bool empty() const;
	value_type read(position) const;
	void write(const value_type &, position);
	position begin() const;
	position last() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void insert(const value_type &, position);
	void erase(position);
	int size() const {
		return _length;
	};

	// sovraccarico di operatori
	Single_Linked_list<T>& operator=(const Single_Linked_list<T>&); // the assignment operator
	bool operator==(const Single_Linked_list<T> &) const; // tests two list for equality

 private:
	List_single_node<T> * _pHead;
	int _length; // the length of the list
};

template< class T >
Single_Linked_list< T >::Single_Linked_list() {
	_pHead = new List_single_node<T>;
	_pHead->_pNext = _pHead;
	_length = 0;
}


template< class T >
Single_Linked_list< T >::Single_Linked_list(const Single_Linked_list<T>& L) {
  _length = 0;

	_pHead = new List_single_node<T>;
	_pHead->_pNext = _pHead;

	if (!L.empty()){
		position p = L.begin();
		for (int i=0;i<L.size();i++){
			insert(L.read(p), last());
			p = L.next(p);
		}
	}
}


template< class T >
Single_Linked_list< T >::~Single_Linked_list(){
	while(!empty())
		erase(begin());
	delete _pHead;
}

template< class T >
void Single_Linked_list< T >::create(){
	if (empty())
			_length = 0;
}

template< class T >
bool Single_Linked_list< T >::empty() const {
	return(_pHead == _pHead->_pNext);
}

template< class T >
typename Single_Linked_list< T >::position
Single_Linked_list< T >::begin() const {
	return (_pHead->_pNext);
}

template< class T >
typename Single_Linked_list< T >::position
Single_Linked_list< T >::last() const {
	position p=begin();
	while (!end(p))
		p=next(p);
	return p;
}


template< class T >
typename Single_Linked_list< T >::position
Single_Linked_list< T >::next(position p) const {
	return(p->_pNext);
}

template< class T >
typename Single_Linked_list< T >::position Single_Linked_list< T >::previous(position p) const {
  position prev=begin();
	while (!end(prev) && next(prev)!=p)
    prev=next(prev);
	return prev;
}

template< class T >
bool Single_Linked_list< T >::end(position p) const {
	return(p == _pHead);
}

template< class T >
typename Single_Linked_list< T >::value_type
Single_Linked_list< T >::read(position p) const {
	if (!end(p))
		return(p->_value);
}

template< class T >
void Single_Linked_list< T >::write(const value_type &a, position p) {
	if (!end(p))
    p->_value = a;
}

template< class T >
void Single_Linked_list< T >::insert(const value_type &a, position p){
	position t = new List_single_node<T>;
	t->_value = a;

	t->_pNext = p;
  position prev=previous(p);
	prev->_pNext = t;

	_length++;
}

template< class T >
void Single_Linked_list< T >::erase(position p){
	if (!empty() && !end(p)){
		position prev=previous(p);
		prev->_pNext = p->_pNext;
		delete p;
	}
}


template<class T>
Single_Linked_list<T>& Single_Linked_list<T>::operator=(const Single_Linked_list<T>& L){
	if (this != &L){
		_length = 0;

		_pHead = new List_single_node<T>;
		_pHead->_pNext = _pHead;

		if (!L.empty()){
      position p = L.begin();
			for (int i=0;i<L.size();i++) {
				insert(L.read(p), last());
				p = L.next(p);
			}
		}
	}
	return *this;
}


template<class T>
bool Single_Linked_list<T>::operator==(const Single_Linked_list<T> &L) const{
	if (L.size() != _length)
		return false;
	position p, pL;
	p = begin();
	pL = L.begin();
	while (!end(p)){
		if (p->_value != pL->_value)
			return false;
		p = p->_pNext;
		pL = pL->_pNext;
	}
	return true;
}


#endif // _SINGLE_LINKED_LIST_H
