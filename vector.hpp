/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:26:53 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/08/18 09:56:46 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace	ft
{
	template <typename vector>
	class vector_Iter
	{
		public:
			typedef vector::value_type	value_type;
			typedef vector::value_type*	pointer_type;
			typedef vector::value_type&	reference_type;
		protected:
			pointer_type	m_ptr;
		public:
			vector_Iter(){}; // Default constructer
			// vector_Iter(pointer_type	ptr) : m_ptr(ptr){};
			vector_Iter(vector_Iter const& Iter) // copy constructer
			{
				*this = Iter;
			};
			vector_Iter& operator=(const vector_Iter& Iter) // copy assignment
			{
				m_ptr = Iter.m_ptr;
				return (*this);
			};
			~vector_Iter(){};
			bool	operator==(const vector_Iter& Iter) const // equality operator
			{
				return(m_ptr==Iter.m_ptr);
			};
			bool	operator!=(const vector_Iter& Iter) const // inquality operator
			{
				return(m_ptr!=Iter.m_ptr);
			};
			reference_type operator*()
			{
				return (*m_ptr);
			};
			pointer_type operator->()
			{
				return(m_ptr);
			};
			vector_Iter& operator++() //pre-increment operator
			{
				m_ptr++;
				return (*this);
			};
			vector_Iter operator++(int) // post-increment operator
			{
				vector_Iter Iter = *this;
				++m_ptr ;
				return (Iter);
			};
			vector_Iter& operator--() // pre-decrement operator
			{
				m_ptr--;
				return (*this);
			};
			vector_Iter operator--(int) //post-decrement operator
			{
				vector_Iter Iter = *this;
				--m_ptr ;
				return (Iter);
			};
			reference_type	operator[](int index) // index operator
			{
				return(*m_ptr[index]);
			};
			bool	operator<(const vector_Iter& Iter) const // smaller-than operator
			{
				return(m_ptr<Iter.m_ptr);
			};
			bool	operator>(const vector_Iter& Iter) const // greater-than operator
			{
				return(m_ptr>Iter.m_ptr);
			};
			bool	operator<=(const vector_Iter& Iter) const //  smaller-than or equal  operator
			{
				return(m_ptr<=Iter.m_ptr);
			};
			bool	operator>=(const vector_Iter& Iter) const // greater-than or equal  operator
			{
				return(m_ptr>=Iter.m_ptr);
			};
			vector_Iter operator+(int n) const
			{
				vector_Iter Iter(*this);
				Iter+= n;
				return (Iter);
			};
			vector_Iter operator-(int n) const
			{
				vector_Iter Iter(*this);
				Iter-= n;
				return (Iter);
			};
			int	operator+(const vector_Iter& Iter)
			{
				int n = this->m_ptr + Iter.m_ptr;
				return (n);
			}
			int	operator-(const vector_Iter& Iter)
			{
				int n = this->m_ptr - Iter.m_ptr;
				return (n);
			}
			vector_Iter& operator+=(int n)
			{
				m_ptr+= n;
				return (*this);
			};
			vector_Iter& operator-=(int n)
			{
				m_ptr-= n;
				return (*this);
			}
	};
		
	template <typename T, typename Alloc = std::allocator<T>>
	class vector
	{
		public:
			typedef T						value_type;
			typedef Alloc					allocator_type;
			typedef T&					reference;
			typedef const T&				const_reference;
			typedef T*					pointer;
			typedef const T*				const_pointer;
			typedef ft::vector_Iter<vector<T>>	iterator;
			typedef size_t					size_type;
		private:
			size_type	_size;
			size_type	_capacity;
			pointer	_data;
			allocator_type	_alloc;
	};	
}
