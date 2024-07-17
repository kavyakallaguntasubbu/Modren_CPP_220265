/*
execute task in asynchromous mode
 
it is a thread that can also catch a return value so could be used in cpp to execute value returnng functions in a seperate thread as
 
 
*/
 
#include <iostream>
#include <future> //asynchrronous
 
int64_t magic(int32_t num)
{
    return num * num;
}
 
// after creating thread it would capture thr return value in future not immediately
int main()
{
    std::future<int64_t> ans = std::async(&magic, 10);
    std::cout << ans.get(); // get fetches the answer from the asyn thread, if thread is still executing then main will get blocked at this line untill magic function will complte
}
