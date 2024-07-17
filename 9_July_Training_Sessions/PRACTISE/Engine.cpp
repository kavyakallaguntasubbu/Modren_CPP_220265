#include "Engine.h"

Engine::Engine(std::string id, EngineType type, float cc, float torque, int horsePower)
    : m_id{id},m_type{type},m_cc{cc},m_torque{torque},m_horsePower{horsePower}
{
}