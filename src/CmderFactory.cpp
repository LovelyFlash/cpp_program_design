#include "CmderFactory.hpp"

namespace adas
{
    std::list<std::function<void(PoseHandler &poseHandler)>> CmderFactory::GetCmders(const std::string &commands) const noexcept
    {
        std::list<std::function<void(PoseHandler & poseHandler)>> cmderList;
        for (const auto cmd : commands)
        {
            const auto cmder = cmderMap.find(cmd);

            if (cmder != cmderMap.end())
                cmderList.push_back(cmder->second);
        }
        return cmderList;
    }
}