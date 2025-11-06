#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose &pose) noexcept : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading)) {}

    void PoseHandler::Move() noexcept
    {
        point += facing->Move();
    }

    void PoseHandler::TurnLeft() noexcept
    {
        facing = &(facing->LeftOne());
    }

    void PoseHandler::TurnRight() noexcept
    {
        facing = &(facing->RightOne());
    }

    void PoseHandler::Reverse(void) noexcept
    {
        facing = &(facing->BackOne());
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