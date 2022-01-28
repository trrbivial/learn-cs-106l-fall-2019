#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <cmath>
template<typename T>
class vector {
public:
    using iterator = T*;
    using const_iterator = const T*;
    using reference_t = T&;
    using reference_v = vector&;
    using const_reference_t = const reference_t;
    using const_reference_v = const reference_v;
    using size_type = size_t;
    const size_type init_size = 2;
    
    // constructor
    vector() : use_size(0), allocate_size(init_size) { vec = new T[allocate_size]; }
    vector(size_type n, const T& val = T()) : use_size(n), allocate_size(std::max(2 * n, init_size)) {
        vec = new T[allocate_size]; for(size_type i = 0; i < use_size; i ++ ) vec[i] = val;
    }
    vector(const vector& rhs) : use_size(rhs.size()), allocate_size(std::max(2 * rhs.size(), init_size)) {
        vec = new T[allocate_size]; for(size_type i = 0; i < use_size; i ++ ) vec[i] = rhs[i];
    }
    vector(std::initializer_list<T> init) : use_size(0), allocate_size(std::max(2 * init.size(), init_size)) {
        vec = new T[allocate_size]; for(auto it = init.begin(); it != init.end(); it ++ ) vec[use_size ++] = *it;
    }

    // deconstructor
    ~vector() { delete [] vec; }
    
    // operator []
    reference_t operator[](const size_type& idx) { return vec[idx]; }
    const_reference_t operator[](const size_type& idx) const { return vec[idx]; }
    reference_t at(const size_type& idx) { if(idx >= use_size) throw std::domain_error("at:out of range"); return vec[idx]; }
    const_reference_t at(const size_type& idx) const { if(idx >= use_size) throw std::domain_error("at:out of range"); return vec[idx]; }

    // operator =
    reference_v operator=(const vector& rhs) {
        use_size = rhs.size(); allocate_size = std::max(2 * rhs.size(), init_size);
        delete [] vec; vec = new T[allocate_size];
        for(size_type i = 0; i < use_size; i ++ ) vec[i] = rhs[i];
        return *this;
    }
    reference_v operator=(std::initializer_list<T> init) {
        use_size = 0; allocate_size = std::max(2 * init.size(), init_size);
        delete [] vec; vec = new T[allocate_size];
        for(auto it = init.begin(); it != init.end(); it ++ ) vec[use_size ++] = *it;
        return *this;
    }

    // get_size
    bool empty() const { return use_size == 0; }
    size_type size() const { return use_size; }
    void resize(size_type n) {
        if(use_size >= n) { use_size = n; return; } 
        while(allocate_size < n) enlarge();
        for(size_type i = use_size; i < n; i ++ ) vec[i] = T();
        use_size = n;
    }
    void resize(size_type n, const T& val) {
        if(use_size >= n) { use_size = n; return; }
        while(allocate_size < n) enlarge();
        for(size_type i = use_size; i < n; i ++ ) vec[i] = val;
        use_size = n;
    }

    // begin() and end()
    iterator begin() const { return vec; }
    iterator end() const { return vec + use_size; }
    iterator rbegin() const { return end() - 1; }
    iterator rend() const { return begin() - 1; }

    // functionality
    void clear() {
        use_size = 0; allocate_size = init_size;
        delete [] vec; vec = new T[allocate_size];
    }
    iterator insert(iterator pos, const T& val) {
        size_type p = pos - begin();
        if(use_size == allocate_size) enlarge();
        for(size_type i = use_size; i > p; i -- ) vec[i] = vec[i - 1];
        vec[p] = val; use_size ++;
        return vec + p;
    }
    iterator insert(const size_type& pos, const T& val) {
        if(pos < 0 || pos > use_size) throw std::domain_error("insert:out of range");
        if(use_size == allocate_size) enlarge();
        for(size_type i = use_size; i > pos; i -- ) vec[i] = vec[i - 1];
        vec[pos] = val; use_size ++;
        return vec + pos;
    }
    void push_back(const T& val) {
        insert(end(),val);
    }
    
private:
    size_type allocate_size;
    size_type use_size;
    iterator vec;
    void enlarge() {
        iterator new_vec = new T[ allocate_size *= 2 ];
        for (size_type i = 0; i < use_size; i ++ ) new_vec[i] = vec[i];
        delete [] vec; vec = new_vec;
    }
};

#include <iostream>
template<typename T>
std::ostream& operator<<(std::ostream& oss, const vector<T>& v) {
    oss.put('[');
    char cm[3] = {'\0', ' ', '\0'};
    for(const auto& e : v) { 
        oss << cm << e; cm[0] = ','; 
    }
    return oss << ']';
}
#endif
