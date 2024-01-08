#pragma once
#include <common.h>
#include <d3d12.h>
#include <dxgi1_4.h>

namespace uknowncheats
{
	class render
	{
	public:
		render() = default;
		~render() = default;

		bool initialize();
		HRESULT render_window(IDXGISwapChain3* dxgiSwapChain, const UINT syncInterval, UINT flags);

		void* present_func;
		void* execute_command_list_func;
		uint64_t* swapchain_vtable = nullptr;
		DWORD_PTR* context_vtable = nullptr;
		DWORD_PTR* device_vtable = nullptr;
		WNDPROC m_wnd_proc = nullptr;
		ID3D12CommandQueue* d3d12CommandQueue = nullptr;

		typedef HRESULT(__stdcall* present_t)(IDXGISwapChain* dx_swapchain, UINT sync_interval, UINT flags);
		present_t original_present = nullptr;

	private:
		void init_imgui();

		bool m_rendering_initialized = false;

		ID3D12Device* m_device = nullptr;
		HWND m_window = nullptr;
	};

	inline render g_render;
}