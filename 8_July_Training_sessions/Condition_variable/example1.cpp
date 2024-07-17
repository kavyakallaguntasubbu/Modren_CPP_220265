/*
    calculate square for 10 numbers

    10 std::thread object to compute square of number of each

    5 operations are to be performed . all are independent (order of execution is not important).
    Executr all 5 parallely

        a ) one std::thread for ech operation
        b) one async thread for each operation
        c) mix of std::thread and std::async

        (all functions returning a value need to be executed via std::async, other via std::thread)

    use case3)

        [producer-consumer problem]

        f1(product) --------> data will be generated

        f2(consumer) ---------> processing data onlu after data is generated


        example : sensor detects collision and deployment of airbags!!!

        program to call emergency()

*/

#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>

std::mutex mt;
int32_t value{0};
std::condition_variable cv;
bool m_inputReceived{false};

void Producer()
{

    while (!m_inputReceived)
    {
        std::cin >> value;
        if (value > 5)
        {
            m_inputReceived = true;
        }
    }
    // data is produces
    // 1) user inputs has been accepted
    // 2) input must be above 5

    // send a signal
    std::lock_guard<std::mutex> lk{mt}; // is a wrapper to lock and unlock the function at end
    cv.notify_one(); // send a signal!
}

void Consumer()
{
    // waiting for signal
    std::unique_lock<std::mutex> ul{mt};

    cv.wait(ul, []
            { return m_inputReceived; });
    // this value cannot be computed before producer gives signal!!
    std::cout << "Value squared is :" << value * value << "\n";
}

int main()
{

    // will lunch producer
    std::thread t1{&Producer};

    std::thread t2{&Consumer};

    std::cout << "Main continous chilling!" << std::endl;
    // will lunch consumer
    t1.join();
    t2.join();

}

/*
    3 persepectives

    Main Function
    --------------
    a) I created t1 thread (producer)
    b) I created t2 thread (consumer)
    c) first cout
    d) second cout
    e) t1 join
    f) t2 join
    g) good bye cout
    h) terminate app!

    Producer perspective :
     a) Executed a loop . In the loop till m_input_received is true :
        a1) took a input

*/
