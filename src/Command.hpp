#pragma once
#include "PoseHandler.hpp"

#include <functional>

namespace adas
{
    /***
     * 以下代码使用ICommand作为基类进行各个动作的定义
     */
    // class ICommand
    // {
    // public:
    //     virtual ~ICommand() = default;
    //     virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
    // };

    // class MoveCommand final : public
    // // ICommand 定义一个嵌套类MoveCommand，完成 Move动作(M指令)
    // {
    // public:
    //     // 执行Move动作，需要委托poseHandlerImp&执行器来完成动作
    //     void DoOperate(PoseHandler &poseHandler) const noexcept override
    //     {
    //         if (poseHandler.IsFast())
    //             poseHandler.Move();
    //         poseHandler.Move();
    //     }
    // };

    // class TurnLeftCommand final : public ICommand
    // {
    // public:
    //     void DoOperate(PoseHandler &poseHandler) const noexcept override
    //     {
    //         if (poseHandler.IsFast())
    //             poseHandler.Move();
    //         poseHandler.TurnLeft();
    //     }
    // };

    // class TurnRightCommand final : public ICommand
    // {
    // public:
    //     void DoOperate(PoseHandler &poseHandler) const noexcept override
    //     {
    //         if (poseHandler.IsFast())
    //             poseHandler.Move();
    //         poseHandler.TurnRight();
    //     }
    // };

    // class FastCommand final : public ICommand
    // {
    // public:
    //     void DoOperate(PoseHandler &poseHandler) const noexcept override
    //     {
    //         poseHandler.Fast();
    //     }
    // };

    // class ReverseCommand final : public ICommand
    // {
    //     public:
    //         void DoOperate(PoseHandler &poseHandler) const noexcept override
    //         {
    //             if (poseHandler.IsFast())
    //                 poseHandler.Move();
    //             poseHandler.Reverse();
    //         }
    // };

    /***
     * 以下使用匿名函数和functional库对函数进行定义
     */
    // class MoveCommand final
    // {
    // public:
    //     const std::function<void(PoseHandler &poseHandler)> operate = [](PoseHandler &poseHandler) noexcept
    //     {
    //         if (poseHandler.IsFast())
    //             poseHandler.Move();
    //         poseHandler.Move();
    //     };
    // };

    // class TurnLeftCommand final
    // {
    // public:
    //     const std::function<void(PoseHandler &poseHandler)> operate = [](PoseHandler &poseHandler) noexcept
    //     {
    //         if (poseHandler.IsFast())
    //             poseHandler.Move();
    //         poseHandler.TurnLeft();
    //     };
    // };

    // class TurnRightCommand final
    // {
    // public:
    //     const std::function<void(PoseHandler &poseHandler)> operate = [](PoseHandler &poseHandler) noexcept
    //     {
    //         if (poseHandler.IsFast())
    //             poseHandler.Move();
    //         poseHandler.TurnRight();
    //     };
    // };

    // class FastCommand final
    // {
    // public:
    //     const std::function<void(PoseHandler &poseHandler)> operate = [](PoseHandler &poseHandler) noexcept
    //     {
    //         poseHandler.Fast();
    //     };
    // };

    // class ReverseCommand final
    // {
    // public:
    //     const std::function<void(PoseHandler &poseHandler)> operate = [](PoseHandler &poseHandler) noexcept
    //     {
    //         if (poseHandler.IsFast())
    //             poseHandler.Move();
    //         poseHandler.Reverse();
    //     };
    // };

    /***
     * 以下用操作符重载对各类操作进行定义
     */

    class MoveCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
                poseHandler.Move();
            poseHandler.Move();
        }
    };

    class TurnLeftCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
                poseHandler.Move();
            poseHandler.TurnLeft();
        }
    };

    class TurnRightCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
                poseHandler.Move();
            poseHandler.TurnRight();
        }
    };

    class FastCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Fast();
        }
    };

    class ReverseCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
                poseHandler.Move();
            poseHandler.Reverse();
        }
    };
}
