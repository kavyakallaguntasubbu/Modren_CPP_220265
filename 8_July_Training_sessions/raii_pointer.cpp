/*
    Magic                                               Heap
                                                      Employee
    ptr[)X100H] ------------------------------->[101 | kavya | 90000.0f]


    void Magic(){

        Wrapper wr {new Employee(101,"kabya" , 9000);}; // no need to delete manually it get deleted automatiaclly

        if(condition){
            std::cout << wr.get() << "\n";

        }
        else{

            throw MyException("Something is wrong");
        }
    }

    int main(){
        Magic();
        int n1 = 10; // on this line
    }

*/

#include <iostream>
#include <list>
#include<memory>

void CreateData(std::shared_ptr<int[]> data)
{

    data[0] = 10;
    data[1] = 20;
}

void CaluculateTotal(std::shared_ptr<int[]> data, int size)
{

    float total{0.0f};

    for (int i = 0; i < size; i++)
    {
        total += data[i];
    }
    std::cout << "Total is" << total << "\n";
}

void PrintFirstElement(std::shared_ptr<int[]> data, int size)
{

    std::cout << data[0] << "\n";
}

int main()
{

   std::shared_ptr<int[]> arr{new int[3]};
    CreateData(arr);
    CaluculateTotal(arr, 3);
    PrintFirstElement(arr, 3);
}
