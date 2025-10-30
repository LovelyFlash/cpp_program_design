#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose &pose) noexcept : pose(pose), fast_mode(false) {}

    void PoseHandler::Move() noexcept
    {
        if (pose.heading == 'W')
        {
            if (fast_mode)
                --pose.x;
            --pose.x;
        }
        else if (pose.heading == 'E')
        {
            if (fast_mode)
                ++pose.x;
            ++pose.x;
        }
        else if (pose.heading == 'N')
        {
            if (fast_mode)
                ++pose.y;
            ++pose.y;
        }
        else if (pose.heading == 'S')
        {
            if (fast_mode)
                --pose.y;
            --pose.y;
        }
    }

    void PoseHandler::TurnLeft() noexcept
    {
        if (pose.heading == 'W')
        {
            if (fast_mode)
                --pose.x;
            pose.heading = 'S';
        }
        else if (pose.heading == 'S')
        {
            if (fast_mode)
                --pose.y;
            pose.heading = 'E';
        }
        else if (pose.heading == 'E')
        {
            if (fast_mode)
                ++pose.x;
            pose.heading = 'N';
        }
        else if (pose.heading == 'N')
        {
            if (fast_mode)
                ++pose.y;
            pose.heading = 'W';
        }
    }

    void PoseHandler::TurnRight() noexcept
    {
        if (pose.heading == 'W')
        {
            if (fast_mode)
                --pose.x;
            pose.heading = 'N';
        }
        else if (pose.heading == 'S')
        {
            if (fast_mode)
                --pose.y;
            pose.heading = 'W';
        }
        else if (pose.heading == 'E')
        {
            if (fast_mode)
                ++pose.x;
            pose.heading = 'S';
        }
        else if (pose.heading == 'N')
        {
            if (fast_mode)
                ++pose.y;
            pose.heading = 'E';
        }
    }

    void PoseHandler::Fast() noexcept
    {
        fast_mode = !fast_mode;
    }

    bool PoseHandler::IsFast() const noexcept
    {
        if (fast_mode)
            return true;
        return false;
    }

    Pose PoseHandler::Query(void) const noexcept
    {
        return pose;
    }
}