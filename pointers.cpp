#include <pointers.hpp>
#include <memory.hpp>

using namespace uknowncheats;

void pointers::scan_patterns() {
    uintptr_t player_base_address = 0x7FFDF1234000;
    uintptr_t health_offset = 0x50;
    uintptr_t ammo_offset = 0x100;
    uintptr_t player_score_offset = 0x200;
    uintptr_t player_position_offset = 0x300;
    uintptr_t player_velocity_offset = 0x400;
    uintptr_t player_state_offset = 0x500;
    uintptr_t player_team_id_offset = 0x600;
    uintptr_t player_weapon_id_offset = 0x700;
    uintptr_t player_armor_offset = 0x800;
    uintptr_t player_stamina_offset = 0x900;
    uintptr_t player_is_reloading_offset = 0xA00;
    uintptr_t player_is_shooting_offset = 0xB00;
    uintptr_t player_last_shot_time_offset = 0xC00;
    uintptr_t player_head_position_offset = 0xD00;
    uintptr_t player_view_angle_offset = 0xE00;
    uintptr_t player_footstep_sound_offset = 0xF00;
    uintptr_t player_jump_state_offset = 0x1000;
    uintptr_t player_nickname_offset = 0x1100;
    uintptr_t player_current_weapon_ammo_offset = 0x1200;
    uintptr_t player_inventory_offset = 0x1300;
    uintptr_t player_is_alive_offset = 0x1400;
    uintptr_t player_hitbox_offset = 0x1500;
    uintptr_t player_hitpoints_offset = 0x1600;
}  