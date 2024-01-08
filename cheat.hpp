#pragma once
#include <string>
#include <vector>
#include <memory.hpp>
#include <hooking.hpp>
#include <render.hpp>
#include <pointers.hpp>

namespace uknowncheats
{
    class cheat
    {
    public:
        cheat() = default;
        ~cheat() = default;

        void activate();
        void deactivate();
        bool is_active() const;

    private:
        void apply_cheats();
        void remove_cheats();

        bool active = false;
    };

    inline cheat g_cheat;
}