#include "ExecutorImpl.hpp"

#include <new>
#include <memory>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose), fast_mode(false) {}

    Pose ExecutorImpl::Query(void) const noexcept
    {
        return pose;
    }

    void ExecutorImpl::Fast()
    {
        fast_mode = !fast_mode;
    }

    bool ExecutorImpl::IsFast()
    {
        if (fast_mode)
            return true;
        return false;
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        for (const auto cmd : commands)
        {
            std::unique_ptr<ICommand> cmder;
            if (cmd == 'M')
                cmder = std::make_unique<MoveCommand>();
            else if (cmd == 'L')
                cmder = std::make_unique<TurnLeftCommand>();
            else if (cmd == 'R')
                cmder = std::make_unique<TurnRightCommand>();
            else if (cmd == 'F')
                cmder = std::make_unique<FastCommand>();
            if (cmder)
                cmder->DoOperate(*this);
        }
    }

    void ExecutorImpl::Move() noexcept
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

    void ExecutorImpl::TurnLeft() noexcept
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

    void ExecutorImpl::TurnRight() noexcept
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

    /*
        std::nothrow是C++标准库中的一个常量，用于指示在分配内存时不抛出任何异常。
        它是std::nothrow_t类型的实例，通常用在new运算符和std::nothrow命名空间中，
        以请求内存分配器在分配失败时返回一个空指针，而不是抛出std::bad_alloc异常。
    */

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
}