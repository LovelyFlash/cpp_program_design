#include "CmderFactory.hpp"

namespace adas
{
    CmderList CmderFactory::GetCmders(const std::string &commands) const noexcept
    {
        CmderList cmderList;
        for (const auto cmd : commands)
        {
            const auto cmder = cmderMap.find(cmd);

            if (cmder != cmderMap.end())
                cmderList.push_back(cmder->second);
        }
        return cmderList;
    }
}