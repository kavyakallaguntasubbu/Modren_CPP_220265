#include<iostream>

class ABC
{
private:
    int m_id{0};
    float *m_valuePtr={nullptr};
public:
    
    ABC(int id, float *ptr):m_id{id},m_valuePtr{ptr}{
        
    }
    ABC() = default;
    ABC(const ABC&) = delete;
    ABC(const ABC&& ) = delete;
    ABC & operator = (const ABC &)= delete;
    ABC & operator = ( ABC &&)= delete;

    ~ABC(){
        delete m_valuePtr; // memory leakage prevented

    }

};

template <typename T>
class Wrapper
{
private:
    T * m_ptr;

public:
    Wrapper(T *ptr):m_ptr{ptr}{

    }
    ~Wrapper(){
        delete m_ptr;
    }
};

void Magic(){
   Wrapper<ABC>wr_obj {{ new ABC(111,new float(200.0f))} };
}

int main(){

    Magic();
//    ABC *c1 { new ABC(111,new float(200.0f))};//uniform initialization ------ {}

}

/*
    1)Main calls Magic
    2)in magic function we create wr_obj (stackmemory)
    3)wr_obj stores the address of the heap allocated ABC object
    4)wr_obj goes out of scope at the end of Mgic function . since wr_obj
    is a stack allocated variable , it will get auto destructed .
    destructor of Wrapper
    5)Wrapper class destructor will call delete on the stored pointer
    for ABC . which will indirectly also delete it.

///////////////////////////////////////////////////////////////////////////////

    memory -----> box [memory will be shared]{box is called : shared_pointer}

    memory -------> box [memory will NEVER SHARED ]{box is called : unique_pointer}

    memory -------> box [memory will stalked ]{box is called : reference_wrapper}

    functions/ callables -------> box {box is called : function_wrapper}


    reference -------> box {box is called : reference_wrapper}

KO
    

*/