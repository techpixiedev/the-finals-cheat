#include <hooking.hpp>
#include <render.hpp>
#include <pointers.hpp>

using namespace uknowncheats;

void(*execute_command_lists_o)(ID3D12CommandQueue*, UINT, ID3D12CommandList*);
void hk_execute_command_lists(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists) {
    if (!g_render.d3d12CommandQueue)
        g_render.d3d12CommandQueue = queue;

    execute_command_lists_o(queue, NumCommandLists, ppCommandLists);
}

HRESULT intercept_window_render(IDXGISwapChain3* swapchain_ptr, const UINT sync_interval, UINT flags) {
    return g_render.render_window(swapchain_ptr, sync_interval, flags);
}

void hooking::hook_present() {
    MH_Initialize();

    MH_CreateHook((void*)g_render.present_func, &intercept_window_render, reinterpret_cast<void**>(&g_render.original_present));
    MH_CreateHook((void*)g_render.execute_command_list_func, &hk_execute_command_lists, reinterpret_cast<void**>(&execute_command_lists_o));
    //MH_CreateHook((void*)g_render.swapchain_vtable[8], &intercept_window_render, reinterpret_cast<void**>(&g_render.original_present));
    MH_EnableHook(MH_ALL_HOOKS);
}

// Additional hooking logic can be added here
void hooking::hook_other_functions() {
    // Example of hooking another function
    // MH_CreateHook((void*)g_pointers.some_other_pointer, &some_other_hook_function, reinterpret_cast<void**>(&original_some_other_function));
    // MH_EnableHook((void*)g_pointers.some_other_pointer);
}

// This function could be a placeholder for a hook that you might want to implement later
void some_other_hook_function() {
    // Code for the hook goes here
}

// Original function pointer for the some_other_hook_function
void(*original_some_other_function)();

// More hooking functions and logic can be implemented as needed