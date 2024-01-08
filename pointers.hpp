#pragma once
#include <common.h>

namespace uknowncheats
{
	class pointers
	{
	public:
		explicit pointers() = default;
		~pointers() = default;

		void scan_patterns();
		uintptr_t steam_overlay_present;
		uintptr_t some_other_pointer;
		int some_function();
		void another_function();
		float yet_another_function();
		bool is_cheat_active;
		char cheat_name[20];
		void print_debug_info();
		int calculate_checksum(const char* data);
		void log_error(const char* error_message);
		void set_cheat_active(bool active);
		int get_player_score(int player_id);
		// Add more member functions and variables as needed
	private:
		// Add private member variables and functions if needed
	};

	inline pointers g_pointers;
}