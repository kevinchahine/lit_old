#include "pch.h"
#include "MessageBase.h"

using namespace std;

string lit::MessageBase::serialize() const
{
    string str;

    str.resize(sizeof(m_scene.waitTime) + sizeof(rgb) * m_scene.size());

    memcpy(&str[0], m_scene.data(), sizeof(rgb) * m_scene.size());

    return str;
}

void lit::MessageBase::parse(const string& str)
{
    const size_t N_BYTES = (str.size() - 2) / sizeof(rgb);
    m_scene.resize(N_BYTES);

    // first 2-bytes waitTime
    const char* p = str.data();
    memcpy(&m_scene.waitTime, p, 2);
    memcpy(m_scene.data(), p, N_BYTES);
}
