#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <iostream>

namespace ft
{
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_acces_iterator_tag : public bidirectional_iterator_tag {};

    template < class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
    struct iterator
    {
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
    };

    template < class Iterator >
    struct iterator_traits
    {
        typedef typename Iterator::difference_type   difference_type;
        typedef typename Iterator::value_type        value_type;
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template < class T >
    struct iterator_traits<T*>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template < class T >
    struct iterator_traits<const T*>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    ///////////////////////////////////////////////////////////
    //////////////////// Iterator : Vector ////////////////////
    ///////////////////////////////////////////////////////////

    template < class T >
    class Itvec
    {
        public:
            // ------------------- Member types ------------------- //
            typedef typename ft::iterator_traits<T*>::iterator_category   iterator_category;
            typedef typename ft::iterator_traits<T*>::value_type          value_type;
            typedef typename ft::iterator_traits<T*>::difference_type     difference_type;
            typedef typename ft::iterator_traits<T*>::pointer             pointer;
            typedef typename ft::iterator_traits<T*>::reference           reference;

            // ------------------- Member functions : Constructors / Destructor ------------------- //
            Itvec(pointer ptr = nullptr): _ptr(ptr) {}
            ~Itvec() { _ptr = nullptr; }
            template < class U >
            Itvec& operator=(const Itvec<U>& copy)
            {
                if (this != &copy)
                    this->_ptr = copy._ptr;
                return (*this);
            } 

            // ------------------- Member functions ------------------- //
            reference operator*() const { return (*this->_ptr); }
            pointer operator->() const { return (this->_ptr); }
            Itvec& operator++() { this->_ptr++; return (*this); }
            Itvec operator++(int) { Itvec tmp = *this; ++(*this); return (tmp); }
            Itvec& operator+=(difference_type n) { this->_ptr += n; return (*this); }
            Itvec operator+(difference_type n) const { Itvec tmp = *this; return (tmp += n); }
            Itvec& operator-=(difference_type n) { this->_ptr -= n; return (*this); }
            Itvec operator-(difference_type n) const { Itvec tmp = *this; return (tmp -= n); }
            Itvec& operator--() { this->_ptr--; return (*this); }
            Itvec  operator--(int) { Itvec tmp = *this; --(*this); return (tmp); }
            reference operator[](difference_type n) const { return *(this->_ptr + n); }

            pointer getPtr() const { return (this->_ptr); }

        private:
            pointer _ptr;
    };

	// -------------------- Itvec non-member functions -------------------- //
    template < class T >
    bool operator==(const ft::Itvec<T>& lhs, const ft::Itvec<T>& rhs) { return (lhs.getPtr() == rhs.getPtr()); }
    template < class T >
    bool operator!=(const ft::Itvec<T>& lhs, const ft::Itvec<T>& rhs) { return (lhs.getPtr() != rhs.getPtr()); }
    template < class T >
    bool operator<(const ft::Itvec<T>& lhs, const ft::Itvec<T>& rhs) { return (lhs.getPtr() < rhs.getPtr()); }
    template < class T >
    bool operator<=(const ft::Itvec<T>& lhs, const ft::Itvec<T>& rhs) { return (lhs.getPtr() <= rhs.getPtr()); }
    template < class T >
    bool operator>(const ft::Itvec<T>& lhs, const ft::Itvec<T>& rhs) { return (lhs.getPtr() > rhs.getPtr()); }
    template < class T >
    bool operator>=(const ft::Itvec<T>& lhs, const ft::Itvec<T>& rhs) { return (lhs.getPtr() >= rhs.getPtr()); }

    ///////////////////////////////////////////////////////////
    //////////////////// Iterator : Map ///////////////////////
    ///////////////////////////////////////////////////////////

	template < class T >
    class Itmap
    {
        public:
            //------------------- Member types -------------------//
            typedef typename ft::iterator_traits<T*>::iterator_category   iterator_category;
            typedef typename ft::iterator_traits<T*>::value_type          value_type;
            typedef typename ft::iterator_traits<T*>::difference_type     difference_type;
            typedef typename ft::iterator_traits<T*>::pointer             pointer;
            typedef typename ft::iterator_traits<T*>::reference           reference;

            //------------------- Member functions : Constructors / Destructor -------------------//
            Itmap(pointer ptr = nullptr): _ptr(ptr) {}
            ~Itmap() { _ptr = nullptr; }
            template < class U >
            Itmap& operator=(const Itmap<U>& copy)                  ////// template maybe not necessary
            {
                if (this != &copy)
                    this->_ptr = copy._ptr;
                return (*this);
            } 

            //------------------- Member functions -------------------//
            reference operator*() const { return (*this->_ptr); }
            pointer operator->() const { return (this->_ptr); }
            Itmap& operator++() { this->_ptr++; return (*this); }
            Itmap operator++(int) { Itmap tmp = *this; ++(*this); return (tmp); }
            Itmap& operator+=(difference_type n) { this->_ptr += n; return (*this); }
            Itmap operator+(difference_type n) const { Itmap tmp = *this; return (tmp += n); }
            Itmap& operator-=(difference_type n) { this->_ptr -= n; return (*this); }
            Itmap operator-(difference_type n) const { Itmap tmp = *this; return (tmp -= n); }
            Itmap& operator--() { this->_ptr--; return (*this); }
            Itmap  operator--(int) { Itmap tmp = *this; --(*this); return (tmp); }
            reference operator[](difference_type n) const { return *(this->_ptr + n); }

            pointer getPtr() const { return (this->_ptr); }

        private:
            pointer _ptr;
    };
	//-------------------- Itmap non-member functions --------------------//
    template < class T >
    bool operator==(const ft::Itmap<T>& lhs, const ft::Itmap<T>& rhs) { return (lhs.getPtr() == rhs.getPtr()); }
    template < class T >
    bool operator!=(const ft::Itmap<T>& lhs, const ft::Itmap<T>& rhs) { return (lhs.getPtr() != rhs.getPtr()); }
    template < class T >
    bool operator<(const ft::Itmap<T>& lhs, const ft::Itmap<T>& rhs) { return (lhs.getPtr() < rhs.getPtr()); }
    template < class T >
    bool operator<=(const ft::Itmap<T>& lhs, const ft::Itmap<T>& rhs) { return (lhs.getPtr() <= rhs.getPtr()); }
    template < class T >
    bool operator>(const ft::Itmap<T>& lhs, const ft::Itmap<T>& rhs) { return (lhs.getPtr() > rhs.getPtr()); }
    template < class T >
    bool operator>=(const ft::Itmap<T>& lhs, const ft::Itmap<T>& rhs) { return (lhs.getPtr() >= rhs.getPtr()); }

    ///////////////////////////////////////////////////////////
    //////////////////// Reverse Iterator /////////////////////
    ///////////////////////////////////////////////////////////

    template < class Iterator >
    class reverse_iterator
    {
        public:
            // ------------------- Member types ------------------- //
            typedef Iterator                                                    iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type          value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
            typedef typename ft::iterator_traits<Iterator>::reference           reference;

            // ------------------- Member functions : Constructors + operator = ------------------- //
            reverse_iterator(): current() {}
            explicit reverse_iterator(iterator_type x): current(x) {}
            template < class U >
            reverse_iterator(const reverse_iterator<U>& copy): current(copy.current) {}
            template < class U >
            reverse_iterator& operator=(const reverse_iterator<U>& copy)
            {
                if (this != &copy)
                    this->current = copy.current;
                return (*this);
            }

            // ------------------- Member functions ------------------- //
            reference operator*() const { Iterator tmp = this->current; return *--tmp; }
            pointer operator->() const { return &(reverse_iterator::operator*()); }
            reference operator[](difference_type n) const { return (this->base()[-n-1]); }
            iterator_type base() const { return (Iterator(this->current)); }
            reverse_iterator& operator++() { this->current--; return (*this); }
            reverse_iterator& operator--() { this->current++; return (*this); }
            reverse_iterator operator++(int) { reverse_iterator temp = *this; this->current--; return temp; }
            reverse_iterator operator--(int) { reverse_iterator temp = *this; this->current++; return temp; }
            reverse_iterator operator+(difference_type n) const { return reverse_iterator(current - n); }
            reverse_iterator operator-(difference_type n) const { return reverse_iterator(current + n); }
            reverse_iterator& operator+=(difference_type n) { this->current -= n; return (*this); }
            reverse_iterator& operator-=(difference_type n) { this->current += n; return (*this); }

        protected:
            iterator_type current;
    };

    // ------------------- Reverse iterator non-member functions ------------------- //
    template < class Iterator >
    bool operator==(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); }
    template < class Iterator >
    bool operator!=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }
    template < class Iterator >
    bool operator<(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); }
    template < class Iterator >
    bool operator<=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); }
    template < class Iterator >
    bool operator>(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return (lhs.base() < rhs.base()); }
    template < class Iterator >
    bool operator>=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); }

    template < class Iterator >
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it) { return (reverse_iterator<Iterator>(it.base() - n)); }
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (rhs.base() - lhs.base()); }

}

#endif