#ifndef IDNOTFOND_H
#define IDNOTFOND_H

#include<stdexcept>
#include<iostream>

class IdnotFond : public std::exception
{
private:
    std::string m_msg{""};
public:
    IdnotFond(std::string msg):m_msg{msg}{

    }
    ~IdnotFond() = default;
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return m_msg.c_str();
    }

};

#endif // IDNOTFOND_H
