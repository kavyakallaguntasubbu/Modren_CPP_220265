#include<iostream>

#include<vector>

enum class Rating{
    _5_STAR,
    _4_STAR,
    _3_STAR,
    _2_STAR,
    _1_STAR,
    _NO_STAR,


};

class Car
{
private:
    unsigned int m_ido{0};
    float m_price{0.0f};
    Rating m_safeteyRating{Rating::_NO_STAR};
public:
    Car(unsigned int id,float price):m_ido{id},m_price{price}{

    }

    Car(unsigned int id,float price, Rating rating)
    :Car(id,price) // this used to map the constructor  of Same Class --- Called Constructor Delegation
    {
        m_safeteyRating = rating;
    }
    


    Car() = default;
    Car(const Car &other) = default;
    Car & operator = (const Car & other) = delete;
    Car && operator = (const Car && other) = delete;
    Car(const Car &&other) = delete;
    ~Car()  = default;
};

int main(){

   

   // std::vector<Car>cars{c1,c2}; // cant because copy construcor is disable no ta good practise


    //option 1 :Enable the Copy Constructor
    // Car c1(101,100.0f,Rating::_4_STAR);
    // Car c2(102,1000.0f,Rating::_3_STAR);

    // std::vector<Car>cars{c1,c2}; // we can disable these but not good programme

    //option 2 : Moving Cars (not applicable in this context)
    // we can move the car data in the vector

    //option 3: Create data inside vector directly(emplacing)

    std::vector<Car>cars;

    cars.emplace_back(101,100.0f,Rating::_1_STAR);//taking cars as container and place them in vecor directly using emplace_back
    cars.emplace_back(102,100.0f,Rating::_2_STAR);

    std::cout<<"Number of Elements"<<cars.size();




    // int32_t n1 = 10; //32 bit / 4 bytes memory  for integer
    // int16_t n2 = 20; // 16 bit / 2 bytes memory  for integer
}
