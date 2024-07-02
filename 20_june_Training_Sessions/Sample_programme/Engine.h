#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>

class Engine
{
private:
    unsigned int m_id{0};
    unsigned int m_horsepower{0};
    float m_torque{0.0}; 
public:
    Engine()  = default;
    ~Engine() = default;

    Engine(const Engine & other ) = delete;

    Engine &operator = (const Engine & other) = delete;

    Engine(const Engine && other) = delete;

    Engine && operator = (const Engine && other) = delete;

    Engine(unsigned int id , unsigned int horsePower , float torque);

    unsigned int id() const { return m_id; }

    unsigned int horsepower() const { return m_horsepower; }

    float torque() const { return m_torque; }
        
};

#endif // ENGINE_H
