#include <iostream>
#include <thread>
#include <mutex>
#include <list>

using ThreadContainer = std::list<std::thread>;

class bankOperations
{
private:
    int32_t m_amout{1000};
    std::mutex mt;

public:
    bankOperations(const bankOperations &) = delete;
    bankOperations(bankOperations &&) = delete;
    bankOperations &operator=(const bankOperations &) = delete;
    bankOperations &operator=(bankOperations &) = delete;
    bankOperations() = default;
    bankOperations(int amount) : m_amout{amount} {}
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
};
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
    bankOperations b1{6000};
    ThreadContainer threads{}; // blank list if threads
    CreateThreads(threads, b1);
    JoinThreads(threads);
    DisplayAmount(b1);
}
