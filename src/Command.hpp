#pragma once
#include "PoseHandler.hpp"

namespace adas
{
    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
    };

    class MoveCommand final : public ICommand // 定义一个嵌套类MoveCommand，完成 Move动作(M指令)
    {
    public:
        // 执行Move动作，需要委托poseHandlerImp&执行器来完成动作
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            poseHandler.Move();
        }
    };

    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            poseHandler.TurnLeft();
        }
    };

    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            poseHandler.TurnRight();
        }
    };

    class FastCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            poseHandler.Fast();
        }
    };

    class ReverseCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
        }
    };
}