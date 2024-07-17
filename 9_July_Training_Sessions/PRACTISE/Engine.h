#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>
#include"EngineType.h"

class Engine
{
private:
    std::string m_id{""};
    EngineType m_type{EngineType::ALTERNATIVE_FUEL};
    float m_cc{0.0};
    float m_torque{0.0};
    int m_horsePower{0};
public:
    Engine() = default;
    Engine(const Engine &) = delete;
    Engine(Engine &&) = delete;
    Engine &operator=(const Engine &) = delete;
    Engine &operator=(Engine &&) = delete;

    Engine(std::string id, EngineType type , float cc, float torque ,int horsePower);

    ~Engine() = default;

    std::string id() const { return m_id; }
    void setId(const std::string &id) { m_id = id; }

    EngineType type() const { return m_type; }
    void setType(const EngineType &type) { m_type = type; }

    float cc() const { return m_cc; }
    void setCc(float cc) { m_cc = cc; }

    float torque() const { return m_torque; }
    void setTorque(float torque) { m_torque = torque; }

    int horsePower() const { return m_horsePower; }
    void setHorsePower(int horsePower) { m_horsePower = horsePower; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_type: " << int(rhs.m_type)
           << " m_cc: " << rhs.m_cc
           << " m_torque: " << rhs.m_torque
           << " m_horsePower: " << rhs.m_horsePower;
        return os;
    }
};

#endif // ENGINE_H
