#include <iostream>
#include <thread>
#include <mutex>
#include <list>

using ThreadContainer = std::list<std::thread>;

// Singleton : A class which can be instantiated only once

class bankOperations
{
private:
    int32_t m_amout{1000};
    std::mutex mt;

    // only defined here static variables can't initialize in class
    // static member can only be modified in static classes
    static bankOperations *m_instance;

    bankOperations(const bankOperations &) = delete;
    bankOperations(bankOperations &&) = delete;
    bankOperations &operator=(const bankOperations &) = delete;
    bankOperations &operator=(bankOperations &) = delete;
    bankOperations() = default;

    bankOperations(int amount) : m_amout{amount} {}

public:
    ~bankOperations() {}

    void Deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amout += 10;
            mt.unlock();
        }
    }

    void Withdraw()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amout -= 10;
            mt.unlock();
        }
    }

    int32_t amout() const { return m_amout; }

    void setAmout(const int32_t &amout) { m_amout = amout; }

    /*
        if pointer exists , it means the object of this calss is already present , As per rules
        of singleton patteren , new object cannot be created.
        so, take the amount value given by the user . update it in the existing object retuen this same
        object's pointer to the user

        if pointer is null , it means no object currently exists in the system for this class.
        'so a new instance can be created . Take val provided by user to construct a new object on the
        heap an return its pointer
    */
    static bankOperations *getInstance(int val)
    {
        if (m_instance)
        {
            m_instance->setAmout(val);
            return m_instance;
        }
        else
        {
            m_instance = new bankOperations(val); // constructor called
            return m_instance;
        }
    }
};

// for initialization
bankOperations *bankOperations::m_instance{nullptr};
// data type      <full-name of data member> //init value

// using top-level functions to store threads
void CreateThreads(ThreadContainer &threads, bankOperations &b1)
{
    threads.emplace_back(&bankOperations::Deposit, &b1);
    threads.emplace_back(&bankOperations::Withdraw, &b1);
}
// joing the threads
void JoinThreads(ThreadContainer &threads)
{
    for (std::thread &th : threads)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}

void DisplayAmount(bankOperations &b1)
{
    std::cout << "Final Answers :" << b1.amout() << std::endl;
}

int main()
{
    bankOperations *ptr = bankOperations::getInstance(1000);
    ThreadContainer threads{}; // blank list if threads
    CreateThreads(threads, *ptr);
    JoinThreads(threads);
    DisplayAmount(*ptr);

    delete ptr;
}
