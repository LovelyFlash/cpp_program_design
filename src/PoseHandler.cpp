#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose &pose) noexcept : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading)) {}

    void PoseHandler::Move() noexcept
    {
        if (fast_mode)
            point += facing->Move();
        point += facing->Move();
    }

    void PoseHandler::TurnLeft() noexcept
    {
        if (fast_mode)
            point += facing->Move();
        facing = &(facing->LeftOne());
    }

    void PoseHandler::TurnRight() noexcept
    {
        if (fast_mode)
            point += facing->Move();
        facing = &(facing->RightOne());
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
        return {point.GetX(), point.GetY(), facing->GetHeading()};
    }
}