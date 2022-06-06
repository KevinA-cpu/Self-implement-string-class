#include"string.h"
//==================================Constructors/Destructor/operator(=)==================================

//-----------------------constructors----------------------
string::string()
{   
    str = new char[1];
    str[0] = '\0';
    len = 0;
    _capacity = len;
}

string::string(const string& s)
{
    str = new char[s.len + 1];
    for(size_t i = 0;i< s.len;i++)
        str[i] = s.str[i];
    len = s.len;
    _capacity = s.capacity();
    str[len] = '\0';
}

string::string(const string& s, size_t pos, size_t n = npos)
{
    if(pos > s.len)
        throw "out of range";
    if(pos + n > s.len)
        n = s.len - pos;
    str = new char[n + 1];
    for(size_t i = 0;i< n;i++)
        str[i] = s.str[pos + i];
    len = n;
    _capacity = s.capacity();
    str[len] = '\0';
}

string::string(const char* c){
    if(c){
        size_t n = 0;
        while(c[n] != '\0')
            n++;
        len = n;
        str = new char[n + 1];
        for(size_t j = 0; j < n; j++)
            str[j] = c[j];
        str[n] = '\0';
        _capacity = len;
    }
    else
    {
        str = new char[1];
        str[0] = '\0';
        len = 0;
        _capacity = len;
    }
}

string::string(const char* c, size_t n)
{
    if(n > 0)
    {
        str = new char[n + 1];
        for(size_t i = 0;i< n;i++)
            str[i] = c[i];
        len = n;
        _capacity = len;
        str[len] = '\0';
    }
    else
    {
        str = new char[1];
        str[0] = '\0';
        len = 0;
        _capacity = len;
    }
}

string::string(size_t n, char c)
{
    str = new char[n + 1];
    for(size_t i = 0;i< n;i++)
        str[i] = c;
    len = n;
    _capacity = len;
    str[len] = '\0';
}

string::string(int n, char c)
{
    str = new char[n + 1];
    for(size_t i = 0; i < n; i++)
        str[i] = c;
    str[n] = '\0';
    len = n;
    _capacity = len;
}

string::string(int n, int m){
    if(n < 0 || m < 0)
        throw "out of range";
    str = new char[n + 1];
    for(size_t i = 0; i < n; i++)
        str[i] = char(m);
    str[n] = '\0';
    len = n;
    _capacity = len;
}

string::string(std::initializer_list<char> il)
{
    len = il.size();
    str = new char[len + 1];
    for(size_t i = 0; i < len; i++)
        str[i] = *(il.begin() + i);
    str[len] = '\0';
    _capacity = len;
}

string::string(string&& s) noexcept
{
    str = s.str;
    len = s.len;
    _capacity = s.capacity();
    s.str = nullptr;
    s.len = 0;
    s._capacity = 0;
}

string::string(char c){
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
    len = 1;
    _capacity = len;
}

//-----------------------constructors----------------------

string::~string()
{   
    delete[] str;
}

//-----------------------operator=----------------------
string& string::operator=(const string& s)
{
    if(this == &s) return *this;
    delete[] str;

    str = new char[s.len + 1];
    for(size_t i = 0;i< s.len;i++)
        str[i] = s.str[i];
    len = s.length();
    _capacity = s.capacity();
    str[len] = '\0';
    return *this;
}

string& string::operator=(const char* c){
    if(c){
        size_t n = 0;
        while(c[n] != '\0')
            n++;
        len = n;
        delete[] str;
        str = new char[n + 1];
        for(size_t j = 0; j < n; j++)
            str[j] = c[j];
        str[n] = '\0';
        _capacity = len;
    }
    else
    {
        delete[] str;
        str = new char[1];
        str[0] = '\0';
        len = 0;
        _capacity = len;
    }
    return *this;
}

string& string::operator=(char c){
    delete[] str;
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
    len = 1;
    _capacity = len;
    return *this;
}

string& string::operator=(std::initializer_list<char> il)
{
    delete[] str;
    len = il.size();
    str = new char[len + 1];
    for(size_t i = 0; i < len; i++)
        str[i] = *(il.begin() + i);
    str[len] = '\0';
    _capacity = len;
    return *this;
}

string& string::operator=(string&& s) noexcept
{
    if(this == &s) return *this;
    delete[] str;
    str = s.str;
    len = s.len;
    _capacity = s.capacity();
    s.str = nullptr;
    s.len = 0;
    s._capacity = 0;
    return *this;
}
//-----------------------operator=----------------------

//==================================Constructors/Destructor/operator(=)==================================



//==================================Capacity==================================
void string::resize(size_t n, char c)
{
    if(n < len)
    {   
       len = n;
       str[len] = '\0';
    }
    else if(n > len)
    {   
        if(n > _capacity)
        {
            reserve(n);
        }
        for(size_t i = len; i < n; i++)
            str[i] = c;
        str[n] = '\0';
        len = n;
    }
    return;
}

void string::resize(size_t n)
{
    if(n < len)
    {   
        len = n;
        str[len] = '\0';
    }
    else if(n > len)
    {   
        if(n > _capacity)
        {
            reserve(n);
        }
        len = n;
    }
    return;
}

void string::reserve(size_t n)
{
    if(n > _capacity)
    {
        char* temp = new char[n + 1];
        for(size_t i = 0; i < len; i++)
            temp[i] = str[i];
        delete[] str;
        str = temp;
        _capacity = n;
    }
    return;
}
//==================================Capacity==================================

//==================================Element Access==================================
char& string::operator[](size_t i)
{   
    if (i >= len)
        throw "out of range";
    return str[i];
}

char string::operator[](size_t i) const
{
    if (i >= len)
        throw "out of range";
    return str[i];
}

const char& string::at(size_t i) const
{
    if (i >= len)
        throw "out of range";
    return str[i];
}

char& string::back()
{
    if(len == 0)
        throw "out of range";
    return str[len - 1];
}

char& string::front()
{
    if(len == 0)
        throw "out of range";
    return str[0];
}
//==================================Element Access==================================

//==================================Modifiers==================================

//-----------------------operator+=-----------------------
string& string::operator+=(const string& s)
{

    if (_capacity < len + s.len + 1){
        reserve(2*(len + s.len) + 1);
    }
    for(int i = 0;i< s.len;i++)
        str[len + i] = s.str[i];
    str[len + s.len] = '\0';
    len += s.len;
    return *this;
}

string& string::operator+=(const char* c)
{
    if(c)
    {
        size_t n = 0;
        while(c[n] != '\0')
            n++;
        if (_capacity < len + n + 1){
            reserve(2*(len + n) + 1);
        }
        for(size_t i = 0;i< n;i++)
            str[len + i] = c[i];
        str[len + n] = '\0';
        len += n;
    }
    return *this;
}

string& string::operator+=(char c)
{
    if (_capacity < len + 2){
        reserve(2*(len + 1) + 1);
    }
    str[len] = c;
    str[len + 1] = '\0';
    len++;
    return *this;
}

string& string::operator+=(std::initializer_list<char> li)
{
    if (_capacity < len + li.size() + 1){
        reserve(2*(len + li.size()) + 1);
    }
    for(auto i = li.begin(); i != li.end(); i++)
        str[len + (i - li.begin())] = *i;
    str[len + li.size()] = '\0';
    len += li.size();
    return *this;
}
//-----------------------operator+=-----------------------

//-----------------------append-----------------------
string& string::append(const string& s)
{
    if (_capacity < len + s.len + 1){
        reserve(2*(len + s.len) + 1);
    }
    for(int i = 0;i< s.len;i++)
        str[len + i] = s.str[i];
    str[len + s.len] = '\0';
    len += s.len;
    return *this;
}

string& string::append(const string& str, size_t subpos, size_t sublen = npos){
    if(subpos > str.len || subpos + sublen > str.len || sublen < 0 || sublen > str.len - subpos)
        throw "out of range";
    if(sublen == npos)
        sublen = str.len - subpos;
    if(_capacity < len + sublen + 1){
        reserve(2*(len + sublen) + 1);
    }
    for(int i = 0;i< sublen;i++)
        this->str[len + i] = str.str[subpos + i];
    this->str[len + sublen] = '\0';
    len += sublen;
    return *this;
}

string& string::append(const char* c){
    if(c){
        size_t n = 0;
        while(c[n] != '\0')
            n++;
        if(_capacity < len + n + 1){
            reserve(2*(len + n) + 1);
        }
        for(size_t j = 0; j < n; j++)
            str[len + j] = c[j];
        str[len + n] = '\0';
        len += n;
    }
    return *this;
}

string& string::append(const char* c, size_t n){
    if(c){
        if(_capacity < len + n + 1){
            reserve(2*(len + n) + 1);
        }
        for(size_t j = 0; j < n; j++)
            str[len + j] = c[j];
        str[len + n] = '\0';
        len += n;
    }
    return *this;
}

string& string::append(size_t n, char c){
    if(_capacity < len + n + 1){
        reserve(2*(len + n) + 1);
    }
    for(size_t i = 0; i < n; i++)
        str[len + i] = c;
    str[len + n] = '\0';
    len += n;
    return *this;
}

string& string::append(int n, int m) {
    if(_capacity < len + n + 1){
        reserve(2*(len + n) + 1);
    }
    for(size_t i = 0; i < n; i++)
        str[len + i] = char(m);
    str[len + n] = '\0';
    len += n;
    return *this;
}

string& string::append (std::initializer_list<char> il){
    if(_capacity < len + il.size() + 1){
        reserve(2*(len + il.size()) + 1);
    }
    for(auto i = il.begin(); i != il.end(); i++)
        str[len + i - il.begin()] = *i;
    str[len + il.size()] = '\0';
    len += il.size();
    return *this;
}
//-----------------------append-----------------------

void string::push_back(char c){
    if(_capacity < len + 1){
        reserve(2*(len + 1) + 1);
    }
    str[len] = c;
    str[len + 1] = '\0';
    len++;
    return;
}

//-----------------------assign-----------------------
string& string::assign(const string& s)
{
    if(_capacity < s.len + 1){
        reserve(2*(s.len + 1) + 1);
    }
    for(size_t i = 0; i < s.len; i++)
        str[i] = s.str[i];
    str[s.len] = '\0';
    len = s.len;
    return *this;
}

string& string::assign(const string& s, size_t subpos, size_t sublen = npos){
    if(subpos > s.len || subpos + sublen > s.len || sublen < 0 || sublen > s.len - subpos)
        throw "out of range";
    if(sublen == npos)
        sublen = s.len - subpos;
    if(_capacity < sublen + 1){
        reserve(2*(sublen + 1) + 1);
    }
    for(size_t i = 0; i < sublen; i++)
        str[i] = s.str[subpos + i];
    str[sublen] = '\0';
    len = sublen;
    return *this;
}

string& string::assign(const char* s){
    if(s){
        size_t n = 0;
        while(s[n] != '\0')
            n++;
        if(_capacity < n + 1){
            reserve(2*(n + 1) + 1);
        }
        for(size_t i = 0; i < n; i++)
            str[i] = s[i];
        str[n] = '\0';
        len = n;
    }
    return *this;
}

string& string::assign(const char* s, size_t n){
    if(s){
        if(_capacity < n + 1){
            reserve(2*(n + 1) + 1);
        }
        for(size_t i = 0; i < n; i++)
            str[i] = s[i];
        str[n] = '\0';
        len = n;
    }
    return *this;
}

string& string::assign(size_t n, char c){
    if(_capacity < n + 1){
        reserve(2*(n + 1) + 1);
    }
    for(size_t i = 0; i < n; i++)
        str[i] = c;
    str[n] = '\0';
    len = n;
    return *this;
}

string& string::assign(int n, int m) {
    if(_capacity < n + 1){
        reserve(2*(n + 1) + 1);
    }
    for(size_t i = 0; i < n; i++)
        str[i] = char(m);
    str[n] = '\0';
    len = n;
    return *this;
}

string& string::assign(int n, char c){
    if(_capacity < n + 1){
        reserve(2*(n + 1) + 1);
    }
    for(size_t i = 0; i < n; i++)
        str[i] = c;
    str[n] = '\0';
    len = n;
    return *this;
}

string& string::assign(std::initializer_list<char> il){
    if(_capacity < il.size() + 1){
        reserve(2*(il.size() + 1) + 1);
    }
    for(auto i = il.begin(); i != il.end(); i++)
        str[i - il.begin()] = *i;
    str[il.size()] = '\0';
    len = il.size();
    return *this;
}

string& string::assign(string&& s) noexcept {
    if(this != &s){
        delete[] str;
        str = s.str;
        len = s.len;
        _capacity = s._capacity;
        s.str = nullptr;
        s.len = 0;
        s._capacity = 0;
    }
    return *this;
}
//-----------------------assign-----------------------

//-----------------------insert-----------------------
string& string::insert(size_t pos, const string& s)
{
    if(pos > len)
        throw "out of range";
    if(_capacity < len + s.len + 1){
        reserve(3*(len + s.len + 1) + 1);
    }
    for(size_t i = len; i >= pos && i <= len; i--)
        str[i + s.len] = str[i];
    for(size_t i = 0; i < s.len; i++)
        str[pos + i] = s.str[i];
    str[len + s.len] = '\0';
    len += s.len;
    return *this;
}


string& string::insert(size_t pos, const string& s, size_t subpos, size_t sublen)
{
    if(pos > len || subpos > s.len || subpos + sublen > s.len || sublen < 0 || sublen > s.len - subpos)
        throw "out of range";
    if(_capacity < len + sublen + 1){
        reserve(3*(len + sublen + 1) + 1);
    }
    for(size_t i = len; i >= pos && i <= len; i--)
        str[i + sublen] = str[i];
    for(size_t i = 0; i < sublen; i++)
        str[pos + i] = s.str[subpos + i];
    str[len + sublen] = '\0';
    len += sublen;
    return *this;
}

string& string::insert(size_t pos, const char* s)
{
    if(pos > len){
        throw "out of range";
    }
    if(s){
        size_t n = 0;
        while(s[n] != '\0')
            n++;
        if(_capacity < len + n + 1){
            reserve(3*(len + n + 1) + 1);
        }
        for(size_t i = len; i >= pos && i <= len; i--)
            str[i + n] = str[i];
        for(size_t i = 0; i < n; i++)
            str[pos + i] = s[i];
        str[len + n] = '\0';
        len += n;
    }
    return *this;
}

string& string::insert(size_t pos, const char* s, size_t n)
{
    if(pos > len){
        throw "out of range";
    }
    if(s){
        if(_capacity < len + n + 1){
            reserve(3*(len + n + 1) + 1);
        }
        for(size_t i = len; i >= pos && i <= len; i--)
            str[i + n] = str[i];
        for(size_t i = 0; i < n; i++)
            str[pos + i] = s[i];
        str[len + n] = '\0';
        len += n;
    }
    return *this;
}

string& string::insert(size_t pos, size_t n, char c)
{
    if(pos > len){
        throw "out of range";
    }
    if(_capacity < len + n + 1){
        reserve(3*(len + n + 1) + 1);
    }
    for(size_t i = len; i >= pos && i <= len; i--)
        str[i + n] = str[i];
    for(size_t i = 0; i < n; i++)
        str[pos + i] = c;
    str[len + n] = '\0';
    len += n;
    return *this;
}

string::iterator string::insert(const_iterator p, char c)
{
    if(p == cbegin()){
        insert(0, 1, c);
        return begin();
    }
    if(p == cend()){
        insert(len, 1, c);
        return end();
    }
    size_t pos = p - cbegin();
    insert(pos, 1, c);
    return begin() + pos;
}

string::iterator string::insert(const_iterator p, size_t n, char c)
{
    if(p == cbegin()){
        insert(0, n, c);
        return begin();
    }
    if(p == cend()){
        insert(len, n, c);
        return end();
    }
    size_t pos = p - cbegin();
    insert(pos, n, c);
    return begin() + pos;
}

string::iterator string::insert(iterator p, char c)
{
    if(p == begin()){
        insert(0, 1, c);
        return begin();
    }
    if(p == end()){
        insert(len, 1, c);
        
    }
    size_t pos = p - begin();
    insert(pos, 1, c);
    return begin() + pos;
}

string::iterator string::insert(iterator p, size_t n, char c)
{
    if(p == begin()){
        insert(0, n, c);
        return begin();
    }
    if(p == end()){
        insert(len, n, c);
        return end();
    }
    size_t pos = p - begin();
    insert(pos, n, c);
    return begin() + pos;
}

string& string::insert(size_t pos, std::initializer_list<char> li){
    if(pos > len){
        throw "out of range";
    }
    if(_capacity < len + li.size() + 1){
        reserve(3*(len + li.size() + 1) + 1);
    }
    for(size_t i = len; i >= pos && i <= len; i--)
        str[i + li.size()] = str[i];
    for(size_t i = 0; i < li.size(); i++)
        str[pos + i] = li.begin()[i];
    str[len + li.size()] = '\0';
    len += li.size();
    return *this;
}


string& string::insert(const_iterator p, std::initializer_list<char> li){
  
    if(p == cbegin()){
        insert(0, li);
        return *this;
    }
    if(p == cend()){
        insert(len, li);
        return *this;
    }
    size_t pos = p - cbegin();
    insert(pos, li);
    return *this;
}
//-----------------------insert-----------------------

//-----------------------erase-----------------------
string& string::erase(size_t pos, size_t size = npos){
   
    if(pos > len || size < 0 || pos + size > len){
        throw "out of range";
    }
    if(size == npos){
        size = len - pos;
    }
    for(size_t i = pos; i < len - size; i++)
        str[i] = str[i + size];
    len -= size;
    str[len] = '\0';
    return *this;
}

string& string::erase(size_t pos){
    erase(pos, npos);
    return *this;
}

string::iterator string::erase(iterator p){
    if(p == begin()){
        erase(0,1);
        return begin();
    }
    if(p == end()){
        erase(len,1);
        return end();
    }
    size_t pos = p - begin();
    erase(pos,1);
    return begin() + pos;
}

string::iterator string::erase(iterator first, iterator last){
    if(first == begin()){
        erase(0, last - first);
        return begin();
    }
    if(last == end()){
        erase(first - begin(), last - first);
        return end();
    }
    size_t pos = first - begin();
    size_t len = last - first;
    erase(pos, len);
    return begin() + pos;
}
//-----------------------erase-----------------------

//-----------------------replace-----------------------
string& string::replace(size_t pos, size_t size, const string& s){
    if(pos > len || size < 0 || pos + size > len){
        throw "out of range";
    }
    if(size == npos){
        size = len - pos;
    }
    if(s.len > size){
        if(_capacity < len + s.len - size + 1){
            reserve(3*(len + s.len - size + 1) + 1);
        }
    }
    erase(pos, size);
    insert(pos, s);
    return *this;
}

string& string::replace(iterator first, iterator last, const string& s){
    if(first == begin()){
        replace(0, last - first, s);
        return *this;
    }
    if(last == end()){
        replace(first - begin(), last - first, s);
        return *this;
    }
    size_t pos = first - begin();
    size_t len = last - first;
    replace(pos, len, s);
    return *this;
}

string& string::replace(size_t pos, size_t size, const string& s, size_t subpos, size_t sublen){
    if(pos > len || size < 0 || pos + size > len){
        throw "out of range";
    }
    if(size == npos){
        size = len - pos;
    }
    if(subpos > s.len || sublen < 0 || subpos + sublen > s.len){
        throw "out of range";
    }
    if(size == npos){
        size = len - pos;
    }
    if(s.len > size){
        if(_capacity < len + s.len - size + 1){
            reserve(3*(len + s.len - size + 1) + 1);
        }
    }
    erase(pos, size);
    insert(pos, s, subpos, sublen);
    return *this;
}

string& string::replace(size_t pos, size_t size, const char* s){
    if(pos > len || size < 0 || pos + size > len){
        throw "out of range";
    }
    if(size == npos){
        size = len - pos;
    }
    size_t n = 0;
    while(s[n] != '\0'){
        n++;
    }
    if(n > size){
        if(_capacity < len + n - size + 1){
            reserve(3*(len + n - size + 1) + 1);
        }
    }
    erase(pos, size);
    insert(pos, s);
    return *this;
}

string& string::replace(iterator first, iterator last, const char* s){
    if(first == begin()){
        replace(0, last - first, s);
        return *this;
    }
    if(last == end()){
        replace(first - begin(), last - first, s);
        return *this;
    }
    size_t pos = first - begin();
    size_t len = last - first;
    replace(pos, len, s);
    return *this;
}

string& string::replace(size_t pos, size_t size, const char* s, size_t n){
    if(pos > len || size < 0 || pos + size > len){
        throw "out of range";
    }
    if(size == npos){
        size = len - pos;
    }
    if(n > size){
        if(_capacity < len + n - size + 1){
            reserve(3*(len + n - size + 1) + 1);
        }
    }
    erase(pos, size);
    insert(pos, s, n);
    return *this;
}

string& string::replace(iterator first, iterator last, const char* s, size_t n){
    if(first == begin()){
        replace(0, last - first, s, n);
        return *this;
    }
    if(last == end()){
        replace(first - begin(), last - first, s, n);
        return *this;
    }
    size_t pos = first - begin();
    size_t len = last - first;
    replace(pos, len, s, n);
    return *this;
}

string& string::replace(size_t pos, size_t size, size_t n, char c){
    if(pos > len || size < 0 || pos + size > len){
        throw "out of range";
    }
    if(size == npos){
        size = len - pos;
    }
    if(n > size){
        if(_capacity < len + n - size + 1){
            reserve(3*(len + n - size + 1) + 1);
        }
    }
    erase(pos, size);
    insert(pos, n, c);
    return *this;
}

string& string:: replace(iterator first, iterator last, size_t n, char c){
    if(first == begin()){
        replace(0, last - first, n, c);
        return *this;
    }
    if(last == end()){
        replace(first - begin(), last - first, n, c);
        return *this;
    }
    size_t pos = first - begin();
    size_t len = last - first;
    replace(pos, len, n, c);
    return *this;
}
//-----------------------replace-----------------------
void string::swap(string& s){
    char* tmp = str;
    str = s.str;
    s.str = tmp;
    size_t tmp2 = _capacity;
    _capacity = s._capacity;
    s._capacity = tmp2;
    size_t tmp3 = len;
    len = s.len;
    s.len = tmp3;
    return;
}
void string::pop_back(){
    if(len == 0){
        throw "out of range";
    }
    len--;
    str[len] = '\0';
    return;
}
//==================================Modifiers==================================

//==================================String operations==================================
size_t string::copy(char* s, size_t n, size_t pos = 0) const{
    if(pos > len){
        throw "out of range";
    }
    if(n > len - pos){
        n = len - pos;
    }
    for(size_t i = 0; i < n; i++){
        s[i] = str[pos + i];
    }
    s[n] = '\0';
    return n;
} 

//-----------------------find-----------------------
size_t string::find(const string& s, size_t pos = 0) const noexcept{
    size_t i = pos;
    while(i < len){
        if(str[i] == s[0]){
            size_t j = 1;
            while(j < s.len && str[i + j] == s[j]){
                j++;
            }
            if(j == s.len){
                return i;
            }
        }
        i++;
    }
    return npos;
}

size_t string::find(const char* s, size_t pos =0) const{
    if(pos > len){
        throw "out of range";
    }
    size_t i = pos;
    size_t n = 0;
    while(i < len){
        if(str[i] == s[0]){
            size_t j = 1;
            while(s[j] != '\0' && str[i + j] == s[j]){
                j++;
            }
            if(s[j] == '\0'){
                return i;
            }
        }
        i++;
    }
    return npos;
}

size_t string::find(const char* s, size_t pos, size_t n) const{
    if(pos > len){
        throw "out of range";
    }
    size_t i = pos;
    while(i < len){
        if(str[i] == s[0]){
            size_t j = 1;
            while(j < n && str[i + j] == s[j]){
                j++;
            }
            if(j == n){
                return i;
            }
        }
        i++;
    }
    return npos;
}

size_t string::find(char c, size_t pos = 0) const noexcept{
    size_t i = pos;
    while(i < len){
        if(str[i] == c){
            return i;
        }
        i++;
    }
    return npos;
}

size_t string::find(const string& s) const  noexcept{
    return find(s, 0);
}

size_t string::find(const char* s) const noexcept{
    return find(s, 0);
}
//-----------------------find-----------------------

//-----------------------rfind-----------------------
size_t string::rfind(const string& s, size_t pos = npos) const noexcept{

    if(pos == npos){
        pos = len;
    }
    size_t i = pos;
    while(i > 0){
        if(str[i - 1] == s[0]){
            size_t j = 1;
            while(j < s.len && str[i-1 + j] == s[j]){
                j++;
            }
            if(j == s.len){
                return i - 1;
            }
        }
        i--;
    }
    return npos;
}

size_t string::rfind(const char* s, size_t pos = npos) const{
    if(pos > len){
        throw "out of range";
    }
    if(pos == npos){
        pos = len;
    }
    size_t i = pos;
    while(i > 0){
        if(str[i - 1] == s[0]){
            size_t j = 1;
           
            while(s[j] != '\0' && str[i-1 + j] == s[j]){
                j++;
            }
            if(s[j] == '\0'){
                return i - 1;
            }
        }
        i--;
    }
    return npos;
}

size_t string::rfind(const char* s, size_t pos, size_t n) const{
    if(pos > len){
        throw "out of range";
    }
    if(pos == npos){
        pos = len;
    }
    size_t i = pos;
    while(i > 0){
        if(str[i - 1] == s[0]){
            size_t j = 1;
            while(j < n && str[i-1 + j] == s[j]){
                j++;
            }
            if(j == n){
                return i - 1;
            }
        }
        i--;
    }
    return npos;
}

size_t string::rfind(char c, size_t pos = npos) const noexcept{
    if(pos == npos){
        pos = len;
    }
    size_t i = pos;
    while(i > 0){
        if(str[i - 1] == c){
            return i - 1;
        }
        i--;
    }
    return npos;
}

size_t string::rfind(const string& s) const noexcept{
    return rfind(s, npos);
}
//-----------------------rfind-----------------------

//-----------------------find_first_of-----------------------
size_t string::find_first_of(const string& s, size_t pos = 0) const noexcept{
    size_t i = pos;
    while(i < len){
        size_t j = 0;
        while(j < s.len && str[i] != s[j]){
            j++;
        }
        if(j < s.len){
            return i;
        }
        i++;
    }
    return npos;
}

size_t string::find_first_of(const char* s, size_t pos = 0) const{
    if(pos > len){
        throw "out of range";
    }
    size_t i = pos;
    while(i < len){
        size_t j = 0;
        while(s[j] != '\0' && str[i] != s[j]){
            j++;
        }
        if(s[j] != '\0'){
            return i;
        }
        i++;
    }
    return npos;
}

size_t string::find_first_of(const char* s, size_t pos, size_t n) const{
    if(pos > len){
        throw "out of range";
    }
    size_t i = pos;
    while(i < len){
        size_t j = 0;
        while(j < n && str[i] != s[j]){
            j++;
        }
        if(j < n){
            return i;
        }
        i++;
    }
    return npos;
}

size_t string::find_first_of(char c, size_t pos = 0) const noexcept{
    size_t i = pos;
    while(i < len){
        if(str[i] == c){
            return i;
        }
        i++;
    }
    return npos;
}

size_t string::find_first_of(const string& s) const noexcept{
    return find_first_of(s, 0);
}

//-----------------------find_first_of-----------------------

//-----------------------find_last_of-----------------------
size_t string::find_last_of(const string& s, size_t pos = npos) const noexcept{
    if(pos == npos){
        pos = len;
    }
    size_t i = pos;
    while(i > 0){
        size_t j = 0;
        while(j < s.len && str[i - 1] != s[j]){
            j++;
        }
        if(j < s.len){
            return i - 1;
        }
        i--;
    }
    return npos;
}

size_t string::find_last_of(const char* s, size_t pos = npos) const{
    if(pos > len){
        throw "out of range";
    }
    if(pos == npos){
        pos = len;
    }
    size_t i = pos;
    while(i > 0){
        size_t j = 0;
        while(s[j] != '\0' && str[i - 1] != s[j]){
            j++;
        }
        if(s[j] != '\0'){
            return i - 1;
        }
        i--;
    }
    return npos;
}

size_t string::find_last_of(const char* s, size_t pos, size_t n) const{
    if(pos > len){
        throw "out of range";
    }
    if(pos == npos){
        pos = len;
    }
    size_t i = pos;
    while(i > 0){
        size_t j = 0;
        while(j < n && str[i - 1] != s[j]){
            j++;
        }
        if(j < n){
            return i - 1;
        }
        i--;
    }
    return npos;
}

size_t string::find_last_of(char c, size_t pos = npos) const noexcept{
    if(pos == npos){
        pos = len;
    }
    size_t i = pos;
    while(i > 0){
        if(str[i - 1] == c){
            return i - 1;
        }
        i--;
    }
    return npos;
}


size_t string::find_last_of(const string& s) const noexcept{
    return find_last_of(s, npos);
}
//-----------------------find_last_of-----------------------

//-----------------------find_first_not_of-----------------------
size_t string::find_first_not_of(const string& s, size_t pos = 0) const noexcept{
    size_t i = pos;
    while(i < len){
        size_t j = 0;
        while(j < s.len){
            if(str[i] == s[j]){
              break;
            }
            j++;
        }
        if(j == s.len){
            return i;
        }
        i++;
    }
    return npos;
}

size_t string::find_first_not_of(const char* s, size_t pos = 0) const{
    if(pos > len){
        throw "out of range";
    }
    size_t i = pos;
    while(i < len){
        size_t j = 0;
        while(s[j] != '\0'){
            if(str[i] == s[j]){
                break;
            }
            j++;
        }
        if(s[j] == '\0'){
            return i;
        }
        i++;
    }
    return npos;
}

size_t string::find_first_not_of(const char* s, size_t pos, size_t n) const{
    if(pos > len){
        throw "out of range";
    }
    size_t i = pos;
    while(i < len){
        size_t j = 0;
        while(j < n){
            if(str[i] == s[j]){
                break;
            }
            j++;
        }
        if(j == n){
            return i;
        }
        i++;
    }
    return npos;
}

size_t string::find_first_not_of(char c, size_t pos = 0) const noexcept{
    size_t i = pos;
    while(i < len){
        if(str[i] != c){
            return i;
        }
        i++;
    }
    return npos;
}

size_t string::find_first_not_of(const string& s) const noexcept{
    return find_first_not_of(s, 0);
}
//-----------------------find_first_not_of-----------------------

//-----------------------find_last_not_of-----------------------
size_t string:: find_last_not_of(const string& s, size_t pos = npos) const noexcept{
    if(pos == npos){
        pos = len;
    }
    size_t i = pos;
    while(i > 0){
        size_t j = 0;
        while(j < s.len){
            if(str[i - 1] == s[j]){
                break;
            }
            j++;
        }
        if(j == s.len){
            return i - 1;
        }
        i--;
    }
    return npos;
}

size_t string::find_last_not_of(const char* s, size_t pos = npos) const{
    if(pos > len){
        throw "out of range";
    }
    if(pos == npos){
        pos = len;
    }
    size_t i = pos;
    while(i > 0){
        size_t j = 0;
        while(s[j] != '\0'){
            if(str[i - 1] == s[j]){
                break;
            }
            j++;
        }
        if(s[j] == '\0'){
            return i - 1;
        }
        i--;
    }
    return npos;
}

size_t string::find_last_not_of(const char* s, size_t pos, size_t n) const{
    if(pos > len){
        throw "out of range";
    }
    if(pos == npos){
        pos = len;
    }
    size_t i = pos;
    while(i > 0){
        size_t j = 0;
        while(j < n){
            if(str[i - 1] == s[j]){
                break;
            }
            j++;
        }
        if(j == n){
            return i - 1;
        }
        i--;
    }
    return npos;
}

size_t string::find_last_not_of(char c, size_t pos = npos) const noexcept{
    if(pos == npos){
        pos = len;
    }
    size_t i = pos;
    while(i > 0){
        if(str[i - 1] != c){
            return i - 1;
        }
        i--;
    }
    return npos;
}

size_t string::find_last_not_of(const string& s) const noexcept{
    return find_last_not_of(s, npos);
}

//-----------------------find_last_not_of-----------------------

//-----------------------substr-----------------------
string string::substr(size_t pos = 0, size_t n = npos) const{
    if(pos > len){
        throw "out of range";
    }
    if(n == npos){
        n = len - pos;
    }
    if(pos + n > len){
        throw "out of range";
    }
    string s;
    s.str = new char[n + 1];
    s.len = n;
    s._capacity = n;
    for(size_t i = 0; i < n; i++){
        s.str[i] = str[pos + i];
    }
    s.str[n] = '\0';
    return s;
}

string string::substr(size_t pos) const{
    return substr(pos, npos);
}
//-----------------------substr-----------------------

//-----------------------compare-----------------------
int string::compare(const string& s) const noexcept{
    if(len < s.len){
        return -1;
    }
    if(len > s.len){
        return 1;
    }
    for(size_t i = 0; i < len; i++){
        if(str[i] < s.str[i]){
            return -1;
        }
        if(str[i] > s.str[i]){
            return 1;
        }
    }
    return 0;
}

int string::compare(size_t pos1, size_t n1, const string& s) const{
    if(pos1 > len){
        throw "out of range";
    }
    if(n1 == npos){
        n1 = len - pos1;
    }
    if(pos1 + n1 > len){
        throw "out of range";
    }
    if(n1 > s.len){
        return 1;
    }
    if(n1 < s.len){
        return -1;
    }
    for(size_t i = 0; i < n1; i++){
        if(str[pos1 + i] < s.str[i]){
            return -1;
        }
        if(str[pos1 + i] > s.str[i]){
            return 1;
        }
    }
    return 0;
}

int string::compare(size_t pos1, size_t n1, const string& s, size_t pos2, size_t n2) const{
    if(pos1 > len){
        throw "out of range";
    }
    if(n1 == npos){
        n1 = len - pos1;
    }
    if(pos1 + n1 > len){
        throw "out of range";
    }
    if(pos2 > s.len){
        throw "out of range";
    }
    if(n2 == npos){
        n2 = s.len - pos2;
    }
    if(pos2 + n2 > s.len){
        throw "out of range";
    }
    if(n1 > n2){
        return 1;
    }
    if(n1 < n2){
        return -1;
    }
    for(size_t i = 0; i < n1; i++){
        if(str[pos1 + i] < s.str[pos2 + i]){
            return -1;
        }
        if(str[pos1 + i] > s.str[pos2 + i]){
            return 1;
        }
    }
    return 0;
}

int string::compare(const char* s) const{
    size_t i = 0;
    while(str[i] != '\0'){
        if(str[i] < s[i]){
            return -1;
        }
        if(str[i] > s[i]){
            return 1;
        }
        i++;
    }
    return 0;
}

int string::compare(size_t pos1, size_t n1, const char* s) const{
    if(pos1 > len){
        throw "out of range";
    }
    if(n1 == npos){
        n1 = len - pos1;
    }
    if(pos1 + n1 > len){
        n1 = len;
    }
    size_t i = 0;
    while(i < n1){
        if(str[pos1 + i] < s[i]){
            return -1;
        }
        if(str[pos1 + i] > s[i]){
            return 1;
        }
        i++;
    }
    return 0;
}

int string::compare(size_t pos1, size_t n1, const char* s, size_t n2) const{
    if(pos1 > len){
        throw "out of range";
    }
    if(n1 == npos){
        n1 = len - pos1;
    }
    if(pos1 + n1 > len){
        throw "out of range";
    }
    if(n2 > len){
        throw "out of range";
    }
    if(n1 > n2){
        return 1;
    }
    if(n1 < n2){
        return -1;
    }
    size_t i = 0;
    while(i < n1){
        if(str[pos1 + i] < s[i]){
            return -1;
        }
        if(str[pos1 + i] > s[i]){
            return 1;
        }
        i++;
    }
    return 0;
}

//-----------------------compare-----------------------

//==================================String operations==================================

//==================================Non-member functon overloads==================================

//-----------------------operator+-----------------------
string operator+(const string& s1, const string& s2){
    string s;
    s.len = s1.len + s2.len;
    s._capacity = s.len;
    s.str = new char[s.len+ 1];
    for(size_t i = 0; i < s1.len; i++){
        s.str[i] = s1.str[i];
    }
    for(size_t i = 0; i < s2.len; i++){
        s.str[s1.len + i] = s2.str[i];
    }
    s.str[s.len] = '\0';
    return s;
}

string operator+(string&& s1, string&& s2){
    string s;
    s.len = s1.len + s2.len;
    s._capacity = s.len;
    s.str = new char[s.len + 1];
    for(size_t i = 0; i < s1.len; i++){
        s.str[i] = s1.str[i];
    }
    for(size_t i = 0; i < s2.len; i++){
        s.str[s1.len + i] = s2.str[i];
    }
    s.str[s.len] = '\0';
    return s;
}

string operator+(string&& s1, const string& s2){
    string s;
    s.len = s1.len + s2.len;
    s._capacity = s.len;
    s.str = new char[s.len + 1];
    for(size_t i = 0; i < s1.len; i++){
        s.str[i] = s1.str[i];
    }
    for(size_t i = 0; i < s2.len; i++){
        s.str[s1.len + i] = s2.str[i];
    }
    s.str[s.len] = '\0';
    return s;
}

string operator+(const string& s1, string&& s2){
    string s;
    s.len = s1.len + s2.len;
    s._capacity = s.len;
    s.str = new char[s.len + 1];
    for(size_t i = 0; i < s1.len; i++){
        s.str[i] = s1.str[i];
    }
    for(size_t i = 0; i < s2.len; i++){
        s.str[s1.len + i] = s2.str[i];
    }
    s.str[s.len] = '\0';
    return s;
}

string operator+(const string& s1, const char* s2){
    string s;
    s.len = s1.len + strlen(s2);
    s._capacity = s.len;
    s.str = new char[s.len + 1];
    for(size_t i = 0; i < s1.len; i++){
        s.str[i] = s1.str[i];
    }
    for(size_t i = 0; i < strlen(s2); i++){
        s.str[s1.len + i] = s2[i];
    }
    s.str[s.len] = '\0';
    return s;
}

string operator+(string&& s1, const char* s2){
    string s;
    s.len = s1.len + strlen(s2);
    s._capacity = s.len;
    s.str = new char[s.len + 1];
    for(size_t i = 0; i < s1.len; i++){
        s.str[i] = s1.str[i];
    }
    for(size_t i = 0; i < strlen(s2); i++){
        s.str[s1.len + i] = s2[i];
    }
    s.str[s.len] = '\0';
    return s;
}

string operator+(const char* s1, const string& s2){
    string s;
    s.len = strlen(s1) + s2.len;
    s._capacity = s.len;
    s.str = new char[s.len + 1];
    for(size_t i = 0; i < strlen(s1); i++){
        s.str[i] = s1[i];
    }
    for(size_t i = 0; i < s2.len; i++){
        s.str[strlen(s1) + i] = s2.str[i];
    }
    s.str[s.len] = '\0';
    return s;
}

string operator+(const char* s1, string&& s2){
    string s;
    s.len = strlen(s1) + s2.len;
    s._capacity = s.len;
    s.str = new char[s.len + 1];
    for(size_t i = 0; i < strlen(s1); i++){
        s.str[i] = s1[i];
    }
    for(size_t i = 0; i < s2.len; i++){
        s.str[strlen(s1) + i] = s2.str[i];
    }
    s.str[s.len] = '\0';
    return s;
}

string operator+(const string& s1, char c){
    string s;
    s.len = s1.len + 1;
    s._capacity = s.len;
    s.str = new char[s.len + 1];
    for(size_t i = 0; i < s1.len; i++){
        s.str[i] = s1.str[i];
    }
    s.str[s.len - 1] = c;
    s.str[s.len] = '\0';
    return s;
}

string operator+(string&& s1, char c){
    string s;
    s.len = s1.len + 1;
    s._capacity = s.len;
    s.str = new char[s.len + 1];
    for(size_t i = 0; i < s1.len; i++){
        s.str[i] = s1.str[i];
    }
    s.str[s.len - 1] = c;
    s.str[s.len] = '\0';
    return s;
}

string operator+(char c, const string& s1){
    string s;
    s.len = s1.len + 1;
    s._capacity = s.len;
    s.str = new char[s.len + 1];
    s.str[0] = c;
    for(size_t i = 0; i < s1.len; i++){
        s.str[i + 1] = s1.str[i];
    }
    s.str[s.len] = '\0';
    return s;
}

string operator+(char c, string&& s1){
    string s;
    s.len = s1.len + 1;
    s._capacity = s.len;
    s.str = new char[s.len + 1];
    s.str[0] = c;
    for(size_t i = 0; i < s1.len; i++){
        s.str[i + 1] = s1.str[i];
    }
    s.str[s.len] = '\0';
    return s;
}
//-----------------------operator+-----------------------

//-----------------------relational operators-----------------------
//==
bool operator==(const string& s1, const string& s2){
    if(s1.len != s2.len)
        return false;
    for(size_t i = 0; i < s1.len; i++){
        if(s1.str[i] != s2.str[i])
            return false;
    }
    return true;
}
bool operator==(const char* s1, const string& s2){
    size_t n = 0;
    while(s1[n] != '\0')
        n++;
    if(n != s2.len)
        return false;
    for(size_t i = 0; i < s2.len; i++){
        if(s1[i] != s2.str[i])
            return false;
    }
    return true;
}
bool operator==(const string& s1, const char* s2){
    size_t n = 0;
    while(s2[n] != '\0')
        n++;
    if(n != s1.len)
        return false;
    for(size_t i = 0; i < s1.len; i++){
        if(s1.str[i] != s2[i])
            return false;
    }
    return true;
}
//==
//!=
bool operator!=(const string& s1, const string& s2){
    return !(s1 == s2);
}
bool operator!=(const char* s1, const string& s2){
    return !(s1 == s2);
}
bool operator!=(const string& s1, const char* s2){
    return !(s1 == s2);
}
//!=
//<
bool operator<(const string& s1, const string& s2){
    if(s1.len < s2.len)
        return true;
    else if(s1.len > s2.len)
        return false;
    else{
        for(size_t i = 0; i < s1.len; i++){
            if(s1.str[i] < s2.str[i])
                return true;
            else if(s1.str[i] > s2.str[i])
                return false;
        }
        return false;
    }
}
bool operator<(const char* s1, const string& s2){
    size_t n = 0;
    while(s1[n] != '\0')
        n++;
    if(n < s2.len)
        return true;
    else if(n > s2.len)
        return false;
    else{
        for(size_t i = 0; i < n; i++){
            if(s1[i] < s2.str[i])
                return true;
            else if(s1[i] > s2.str[i])
                return false;
        }
        return false;
    }
}
bool operator<(const string& s1, const char* s2){
    size_t n = 0;
    while(s2[n] != '\0')
        n++;
    if(s1.len < n)
        return true;
    else if(s1.len > n)
        return false;
    else{
        for(size_t i = 0; i < s1.len; i++){
            if(s1.str[i] < s2[i])
                return true;
            else if(s1.str[i] > s2[i])
                return false;
        }
        return false;
    }
}
//<
//>
bool operator>(const string& s1, const string& s2){
    return s2 < s1;
}
bool operator>(const char* s1, const string& s2){
    return s2 < s1;
}
bool operator>(const string& s1, const char* s2){
    return s2 < s1;
}
//>
//<=
bool operator<=(const string& s1, const string& s2){
    return !(s1 > s2)   || s1 == s2;
}
bool operator<=(const char* s1, const string& s2){
    return !(s1 > s2) || s1 == s2;
}
bool operator<=(const string& s1, const char* s2){
    return !(s1 > s2) || s1 == s2;
}
//<=
//>=
bool operator>=(const string& s1, const string& s2){
    return !(s1 < s2) || s1 == s2;
}
bool operator>=(const char* s1, const string& s2){
    return !(s1 < s2) || s1 == s2;
}
bool operator>=(const string& s1, const char* s2){
    return !(s1 < s2) || s1 == s2;
}
//>=
//-----------------------relational operators-----------------------
void swap(string& s1, string& s2){
    string temp = s1;
    s1 = s2;
    s2 = temp;
    return;
}

std::istream& operator>>(std::istream& is,string& s)
{   
   while(1){
   char c = is.get();
   if (c == ' ' || c == '\n')
       break;
   else
         s+=c;
   }
   return is;
} 

std::ostream& operator<<(std::ostream& os, const string& s)
{
    if(s.length() == 0)
        os << "";
    else{
        for (size_t i = 0; i < s.length(); i++)
            os << s[i];
    }
    return os;
}

std::istream& getline(std::istream& is, string& s, char delim){
    while(1){
        char c = is.get();
        if (c == delim)
            break;
        else
            s+=c;
    }
    return is;
}

std::istream& getline(std::istream&& is, string& s, char delim){
    while(1){
        char c = is.get();
        if (c == delim)
            break;
        else
            s+=c;
    }
    return is;
}

std::istream& getline(std::istream& is, string& s)
{
    while(1){
        char c = is.get();
        if (c == '\n')
            break;
        else
            s+=c;
    }
    return is;
}

std::istream& getline(std::istream&& is, string& s)
{
    while(1){
        char c = is.get();
        if (c == '\n')
            break;
        else
            s+=c;
    }
    return is;
}
//==================================Non-member functon overloads==================================