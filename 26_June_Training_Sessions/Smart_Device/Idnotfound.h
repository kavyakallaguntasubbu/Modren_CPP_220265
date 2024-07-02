#ifndef IDNOTFOUND_H
#define IDNOTFOUND_H

#include<stdexcept>
#include<iostream>

class Idnotfound : public std::exception
{
private:
    std::string _msg;
public:
    Idnotfound(std::string msg) {
        this->_msg = msg;
    }
    ~Idnotfound() {}
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    }


};

#endif // IDNOTFOUND_H
