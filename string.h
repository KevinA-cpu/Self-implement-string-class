#pragma once
#include<iostream>
#include<iterator>
#include<windows.h>

class string
{
private:
	//==================================Member types==================================
	char* str;
	size_t len;
	size_t _capacity;
	std::allocator<char> alloc;
	//==================================Member types==================================
public:
	//==================================Iterator Classes==================================
	class iterator: public std::iterator<std::random_access_iterator_tag, char>
	{	private:
			char* ptr;
		public:
			iterator() : ptr(nullptr) {}
			iterator(char* ptr) :ptr(ptr) {}
			iterator(const iterator& it) :ptr(it.ptr) {}
			iterator& operator++() { ++ptr; return *this; }
			iterator operator++(int) { iterator tmp(*this); ++ptr; return tmp; }
			iterator& operator--() { --ptr; return *this; }
			iterator operator--(int) { iterator tmp(*this); --ptr; return tmp; }
			iterator& operator+=(int n) { ptr += n; return *this; }
			iterator& operator-=(int n) { ptr -= n; return *this; }
			iterator operator+(int n) { iterator tmp(*this); tmp += n; return tmp; }
			iterator operator-(int n) { iterator tmp(*this); tmp -= n; return tmp; }
			char& operator*() { return *ptr; }
			char& operator[](int n) { return *(ptr + n); }
			bool operator==(const iterator& it) { return ptr == it.ptr; }
			bool operator!=(const iterator& it) { return ptr != it.ptr; }
			bool operator<(const iterator& it) { return ptr < it.ptr; }
			bool operator>(const iterator& it) { return ptr > it.ptr; }
			bool operator<=(const iterator& it) { return ptr <= it.ptr; }
			bool operator>=(const iterator& it) { return ptr >= it.ptr; }
			int operator-(const iterator& it) { return ptr - it.ptr; }
	};

	class reverse_iterator: public std::iterator<std::random_access_iterator_tag, char>
	{	private:
			char* ptr;
		public:
			reverse_iterator() : ptr(nullptr) {}
			reverse_iterator(char* ptr) :ptr(ptr) {}
			reverse_iterator(const reverse_iterator& it) :ptr(it.ptr) {}
			reverse_iterator& operator++() { --ptr; return *this; }
			reverse_iterator operator++(int) { reverse_iterator tmp(*this); --ptr; return tmp; }
			reverse_iterator& operator--() { ++ptr; return *this; }
			reverse_iterator operator--(int) { reverse_iterator tmp(*this); ++ptr; return tmp; }
			reverse_iterator& operator+=(int n) { ptr -= n; return *this; }
			reverse_iterator& operator-=(int n) { ptr += n; return *this; }
			reverse_iterator operator+(int n) { reverse_iterator tmp(*this); tmp += n; return tmp; }
			reverse_iterator operator-(int n) { reverse_iterator tmp(*this); tmp -= n; return tmp; }
			char& operator*() { return *ptr; }
			char& operator[](int n) { return *(ptr - n); }
			bool operator==(const reverse_iterator& it) { return ptr == it.ptr; }
			bool operator!=(const reverse_iterator& it) { return ptr != it.ptr; }
			bool operator<(const reverse_iterator& it) { return ptr > it.ptr; }
			bool operator>(const reverse_iterator& it) { return ptr < it.ptr; }
			bool operator<=(const reverse_iterator& it) { return ptr >= it.ptr; }
			bool operator>=(const reverse_iterator& it) { return ptr <= it.ptr; }
			int operator-(const reverse_iterator& it) { return ptr - it.ptr; }
	};

	class const_iterator: public std::iterator<std::random_access_iterator_tag, char>
	{	private:
			const char* ptr;
		public:
			const_iterator() : ptr(nullptr) {}
			const_iterator(const char* ptr) :ptr(ptr) {}
			const_iterator(const const_iterator& it) :ptr(it.ptr) {}
			const_iterator& operator++() { ++ptr; return *this; }
			const_iterator operator++(int) { const_iterator tmp(*this); ++ptr; return tmp; }
			const_iterator& operator--() { --ptr; return *this; }
			const_iterator operator--(int) { const_iterator tmp(*this); --ptr; return tmp; }
			const_iterator& operator+=(int n) { ptr += n; return *this; }
			const_iterator& operator-=(int n) { ptr -= n; return *this; }
			const_iterator operator+(int n) { const_iterator tmp(*this); tmp += n; return tmp; }
			const_iterator operator-(int n) { const_iterator tmp(*this); tmp -= n; return tmp; }
			const char& operator*() { return *ptr; }
			const char& operator[](int n) { return *(ptr + n); }
			bool operator==(const const_iterator& it) { return ptr == it.ptr; }
			bool operator!=(const const_iterator& it) { return ptr != it.ptr; }
			bool operator<(const const_iterator& it) { return ptr < it.ptr; }
			bool operator>(const const_iterator& it) { return ptr > it.ptr; }
			bool operator<=(const const_iterator& it) { return ptr <= it.ptr; }
			bool operator>=(const const_iterator& it) { return ptr >= it.ptr; }
			int operator-(const const_iterator& it) { return ptr - it.ptr; }
	};

	class const_reverse_iterator: public std::iterator<std::random_access_iterator_tag, char>
	{	private:
			const char* ptr;
		public:
			const_reverse_iterator() : ptr(nullptr) {}
			const_reverse_iterator(const char* ptr) :ptr(ptr) {}
			const_reverse_iterator(const const_reverse_iterator& it) :ptr(it.ptr) {}
			const_reverse_iterator& operator++() { --ptr; return *this; }
			const_reverse_iterator operator++(int) { const_reverse_iterator tmp(*this); --ptr; return tmp; }
			const_reverse_iterator& operator--() { ++ptr; return *this; }
			const_reverse_iterator operator--(int) { const_reverse_iterator tmp(*this); ++ptr; return tmp; }
			const_reverse_iterator& operator+=(int n) { ptr -= n; return *this; }
			const_reverse_iterator& operator-=(int n) { ptr += n; return *this; }
			const_reverse_iterator operator+(int n) { const_reverse_iterator tmp(*this); tmp += n; return tmp; }
			const_reverse_iterator operator-(int n) { const_reverse_iterator tmp(*this); tmp -= n; return tmp; }
			const char& operator*() { return *ptr; }
			const char& operator[](int n) { return *(ptr - n); }
			bool operator==(const const_reverse_iterator& it) { return ptr == it.ptr; }
			bool operator!=(const const_reverse_iterator& it) { return ptr != it.ptr; }
			bool operator<(const const_reverse_iterator& it) { return ptr > it.ptr; }
			bool operator>(const const_reverse_iterator& it) { return ptr < it.ptr; }
			bool operator<=(const const_reverse_iterator& it) { return ptr >= it.ptr; }
			bool operator>=(const const_reverse_iterator& it) { return ptr <= it.ptr; }
			int operator-(const const_reverse_iterator& it) { return ptr - it.ptr; }
	};
	//==================================Iterator Classes==================================

	//==================================Member functions==================================
	
	//==================================Construtctors/Destructor/operator(=)==================================

	//-----------------------constructors----------------------
	string();
	string(const string&);
	string(const string&, size_t, size_t);
	string(const char*);
	string(const char*, size_t);
	string(size_t, char);
	string(int, char);
	string(int,int);
	template<class InputIterator>
	string(InputIterator i1, InputIterator i2){
		size_t len_ = i2 - i1;
		str = new char[len_ + 1];
		for (size_t i = 0; i < len_; i++)
			str[i] = *(i1 + i);
		str[len_] = '\0';
		len = len_;
		_capacity = len_;
	}
	string(char);
	string(std::initializer_list<char>);
	string(string&&) noexcept;
	//-----------------------constructors----------------------
	
	~string();
	
	//-----------------------operator=----------------------
	string& operator=(const string&);
	string& operator=(const char*);
	string& operator=(char);
	string& operator=(std::initializer_list<char>);
	string& operator=(string&&) noexcept;
	//-----------------------operator=----------------------

	//==================================Construtctors/Destructor/operator(=)==================================

	//==================================Iterators==================================
	//iterator 
	iterator begin() noexcept { return iterator(str); }
	iterator begin() const noexcept { return iterator(str); }

	//iterator end
	iterator end() noexcept{ return iterator(str + len); }
	iterator end() const noexcept{ return iterator(str + len); }

	//reverse_iterator
	reverse_iterator rbegin() noexcept { return reverse_iterator(str + len - 1); }
	reverse_iterator rbegin() const noexcept { return reverse_iterator(str + len - 1); }

	//reverse_iterator 
	reverse_iterator rend() noexcept { return reverse_iterator(str - 1); }
	reverse_iterator rend() const noexcept { return reverse_iterator(str - 1); }

	//const_iterator
	const_iterator cbegin() const noexcept { return const_iterator(str); }
	const_iterator cend() const noexcept { return const_iterator(str + len); }

	//const_reverse_iterator 
	const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(str + len - 1); }
	const_reverse_iterator crend() const noexcept { return const_reverse_iterator(str - 1); }
	//==================================Iterators==================================


	//==================================Capacity==================================
	size_t size() const noexcept { return sizeof(char) * (len+1); }
	size_t length() const noexcept { return len; }
	size_t max_size() const noexcept { 
		MEMORYSTATUSEX statex;
		statex.dwLength = sizeof(statex);
		GlobalMemoryStatusEx(&statex);
		return sizeof(char)  * statex.ullTotalPhys; 
	}
	void resize(size_t n, char c);
	void resize(size_t n);
	size_t capacity() const noexcept { return sizeof(char) * (_capacity); }
	void reserve(size_t n = 0);
	void clear() noexcept { len = 0; }
	bool empty() const noexcept { return len == 0; }
	void shrink_to_fit() noexcept { _capacity = len; }
	//==================================Capacity==================================

	//==================================Element Access==================================
	char& operator[](size_t);
	char operator[](size_t) const;

	const char& at(size_t) const;
    char& back();
	char& front();
	//==================================Element Access==================================
	
	//==================================Modifiers==================================

	//-----------------------operator+=----------------------
	string& operator+=(const string&);
	string& operator+=(const char*);
	string& operator+=(char);
	string& operator+=(std::initializer_list<char>);
	//-----------------------operator+=-----------------------

	//-----------------------append-----------------------
	string& append(const string&);
	string& append (const string&, size_t, size_t);
	string& append (const char*);
	string& append (const char*, size_t);
	string& append (size_t, char);
	string& append (int, int);
	template <class InputIterator>
	string& append(InputIterator first, InputIterator last){
		size_t n = last - first;
		if (n > 0) {
			if (len + n > _capacity) {
				reserve(len + n);
			}
			for (size_t i = 0; i < n; i++) {
				str[len + i] = *(first + i);
			}
			len += n;
		}
		return *this;
	}
	string& append (std::initializer_list<char>);
	//-----------------------append-----------------------
	void push_back(char);
	//-----------------------assign-----------------------
	string& assign(const string&);
	string& assign(const string&, size_t, size_t);
	string& assign(const char*);
	string& assign(const char*, size_t);
	string& assign(size_t, char);
	string& assign(int, int);
	string& assign(int, char);
	template <class InputIterator>
	string& assign(InputIterator first, InputIterator last){
		size_t n = last - first;
		if (n > 0) {
			if (n > _capacity) {
				reserve(n);
			}
			for (size_t i = 0; i < n; i++) {
				str[i] = *(first + i);
			}
			len = n;
		}
		return *this;
	}
	string& assign (std::initializer_list<char>);
	string& assign(string&&) noexcept;
	//-----------------------assign-----------------------

	//-----------------------insert-----------------------
	string& insert(size_t, const string&);
	string& insert(size_t, const string&, size_t, size_t);
	string& insert(size_t, const char*);
	string& insert(size_t, const char*, size_t);
	string& insert(size_t, size_t, char);
	iterator insert(const_iterator, size_t, char);
	iterator insert(const_iterator, char);
	iterator insert(iterator, size_t, char);
	iterator insert(iterator, char);
	template <class InputIterator>
	iterator insert(iterator p, InputIterator first, InputIterator last){
		size_t n = last - first;
		size_t pos = p - begin();
		if (n > 0) {
			if (n > _capacity) {
				reserve(n);
			}
			for(size_t i = len; i >= pos; i--)
        			str[i + n] = str[i];
			for (size_t i = 0; i < n; i++) {
				str[pos + i] = *(first + i);
			}
			str[len + n] = '\0';
			len += n;
		}
		return p;
	}
	string& insert(size_t, std::initializer_list<char>);
	string& insert(const_iterator, std::initializer_list<char>);
	//-----------------------insert-----------------------

	//-----------------------erase-----------------------
	string& erase(size_t,size_t);
	string& erase(size_t);
	iterator erase(iterator);
	iterator erase(iterator, iterator);
	//-----------------------erase-----------------------

	//-----------------------replace-----------------------
	string& replace(size_t, size_t, const string&);
	string& replace(iterator, iterator,const string&);
	string& replace(size_t, size_t, const string&, size_t, size_t);
	string& replace(size_t, size_t,const char*);
	string& replace(iterator, iterator, const char*);
	string& replace(size_t, size_t, const char*, size_t);
	string& replace(iterator, iterator, const char*, size_t);
	string& replace(size_t, size_t, size_t, char);
	string& replace(iterator, iterator, size_t, char);
	template <class InputIterator>
	string& replace(iterator i1, iterator i2, InputIterator first, InputIterator last){
		size_t n = last - first;
		if (n > 0) {
			if (n > _capacity) {
				reserve(n);
			}
			erase(i1, i2);
			insert(i1, first, last);
		}
		return *this;
	}
	//-----------------------replace-----------------------
	void swap(string&);
	void pop_back();
	//==================================Modifiers==================================

	//==================================String operations==================================
	const char* c_str() const noexcept { return str; }
	const char* data() const noexcept { return str; }

	std::allocator<char> get_allocator() const noexcept{return alloc;}
	size_t copy(char*, size_t, size_t) const;

	//-----------------------find-----------------------
	size_t find(const string&, size_t) const noexcept;
	size_t find(const char*, size_t) const;
	size_t find(const char*, size_t, size_t) const;
	size_t find(char, size_t) const noexcept;
	size_t find(const string&) const noexcept;
	size_t find(const char*) const noexcept;
	//-----------------------find-----------------------

	//-----------------------rfind-----------------------
	size_t rfind(const string&, size_t) const noexcept;
	size_t rfind(const char*, size_t) const;
	size_t rfind(const char*, size_t, size_t) const;
	size_t rfind(char, size_t) const noexcept;
	size_t rfind(const string&) const noexcept;
	//-----------------------rfind-----------------------

	//-----------------------find_first_of-----------------------
	size_t find_first_of(const string&, size_t) const noexcept;
	size_t find_first_of(const char*, size_t) const;
	size_t find_first_of(const char*, size_t, size_t) const;
	size_t find_first_of(char, size_t) const noexcept;
	size_t find_first_of(const string&) const noexcept;
	//-----------------------find_first_of-----------------------

	//-----------------------find_last_of-----------------------
	size_t find_last_of(const string&, size_t) const noexcept;
	size_t find_last_of(const char*, size_t) const;
	size_t find_last_of(const char*, size_t, size_t) const;
	size_t find_last_of(char, size_t) const noexcept;
	size_t find_last_of(const string&) const noexcept;
	//-----------------------find_last_of-----------------------

	//-----------------------find_first_not_of-----------------------
	size_t find_first_not_of(const string&, size_t) const noexcept;
	size_t find_first_not_of(const char*, size_t) const;
	size_t find_first_not_of(const char*, size_t, size_t) const;
	size_t find_first_not_of(char, size_t) const noexcept;
	size_t find_first_not_of(const string&) const noexcept;
	//-----------------------find_first_not_of-----------------------

	//-----------------------find_last_not_of-----------------------
	size_t find_last_not_of(const string&, size_t) const noexcept;
	size_t find_last_not_of(const char*, size_t) const;
	size_t find_last_not_of(const char*, size_t, size_t) const;
	size_t find_last_not_of(char, size_t) const noexcept;
	size_t find_last_not_of(const string&) const noexcept;
	//-----------------------find_last_not_of-----------------------

	//-----------------------substr-----------------------
	string substr(size_t, size_t) const;
	string substr(size_t) const;
	//-----------------------substr-----------------------

	//-----------------------compare-----------------------
	int compare(const string&) const noexcept;
	int compare(size_t, size_t, const string&) const;
	int compare(size_t, size_t, const string&, size_t, size_t) const;
	int compare(const char*) const;
	int compare(size_t, size_t, const char*) const;
	int compare(size_t, size_t, const char*, size_t) const;
	//-----------------------compare-----------------------

	//==================================String operations==================================
	
	//==================================Member constants==================================
	static const size_t npos = -1;
	//==================================Member constants==================================

	//==================================Non-member function overloads==================================

	//-----------------------operator+-----------------------
	friend string operator+(const string&, const string&);
	friend string operator+(string&&,string&&);
	friend string operator+(string&&, const string&);
	friend string operator+(const string&, string&&);
	friend string operator+(const string&, const char*);
	friend string operator+(string&&, const char*);
	friend string operator+(const char*, const string&);
	friend string operator+(const char*, string&&);
	friend string operator+(const string&, char);
	friend string operator+(string&&, char);
	friend string operator+(char, const string&);
	friend string operator+(char, string&&);
	//-----------------------operator+-----------------------

	//-----------------------relational operators-----------------------
	//==
	friend bool operator==(const string&, const string&);
	friend bool operator==(const char*, const string&);
	friend bool operator==(const string&, const char*);
	//!=
	friend bool operator!=(const string&, const string&);
	friend bool operator!=(const char*, const string&);
	friend bool operator!=(const string&, const char*);
	//<
	friend bool operator<(const string&, const string&);
	friend bool operator<(const char*, const string&);
	friend bool operator<(const string&, const char*);
	//>
	friend bool operator>(const string&, const string&);
	friend bool operator>(const char*, const string&);
	friend bool operator>(const string&, const char*);
	//<=
	friend bool operator<=(const string&, const string&);
	friend bool operator<=(const char*, const string&);
	friend bool operator<=(const string&, const char*);
	//>=
	friend bool operator>=(const string&, const string&);
	friend bool operator>=(const char*, const string&);
	friend bool operator>=(const string&, const char*);
	//-----------------------relational operators-----------------------
	friend void swap(string&, string&);

	friend std::istream& operator>>(std::istream& is, string& s);
	friend std::ostream& operator<<(std::ostream& os, const string& s);

	friend std::istream& getline(std::istream&, string&, char);
	friend std::istream& getline(std::istream&&, string&, char);
	friend std::istream& getline(std::istream&, string&);
	friend std::istream& getline(std::istream&&, string&);
	//==================================Non-member function overloads==================================
	
	//==================================Member functions==================================
};

