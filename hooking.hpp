#pragma once
#include <common.h>
#include <MinHook.h>

namespace uknowncheats
{
    class hooking
    {
    public:
        explicit hooking() {
            if (MH_Initialize() != MH_OK) {
                throw std::runtime_error("Failed to initialize MinHook.");
            }
        }

        ~hooking() {
            if (MH_Uninitialize() != MH_OK) {
                // Log or handle the uninitialization error
            }
        }

        template <typename T>
        bool create_hook(LPVOID target, LPVOID detour, T** original) {
            if (MH_CreateHook(target, detour, reinterpret_cast<LPVOID*>(original)) != MH_OK) {
                return false;
            }
            return MH_EnableHook(target) == MH_OK;
        }

        template <typename T>
        bool remove_hook(T* target) {
            return MH_DisableHook(reinterpret_cast<LPVOID>(target)) == MH_OK;
        }

        void hook_present();
        // Add more hooking methods as needed

    private:
        // Add private member variables if needed
    };

    inline hooking g_hooking;
}