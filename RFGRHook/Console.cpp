#include "Console.h"
#include "Vehicles.h"

bool Console::Enabled;
bool Console::CommandsInitialized;

int* Console::Width = (int*)(Addr(0x01D07F2C));
int* Console::Height = (int*)(Addr(0x01D07F30));
bool* Console::Open = (bool*)(Addr(0x01CE77B8));
const char* Console::String = (const char*)(Addr(0x01CDC440));
int* Console::CommandRunning = (int*)(Addr(0x01CDA4F4));

void Console::CommandAdd(Command* Cmd, const char* CommandName, const char* HelpInfo, int CommandType, void* FuncAddr) {
	((void(__thiscall*)(Command*, const char*, const char*, int, void*))Addr(0x005C4E10))(Cmd, CommandName, HelpInfo, CommandType, FuncAddr);
}

void Console::CommandInsert(Dict* Entry) {
	((void(__cdecl*)(Dict*))Addr(0x00866A30))(Entry);
}

char Console::GetArg(unsigned int Type, int Optional) {
	return ((char(__cdecl*)(unsigned int, int))Addr(0x005AF3F0))(Type, Optional);
}

void Console::CreateCommand(const char* Name, const char* Description, int Type, uintptr_t CallAddr, bool ASLR) {
	Command* Cmd = new Command;
	Dict* CmdDict = new Dict;
	CmdDict->Prev = 0;
	CmdDict->Def = Cmd;
	CmdDict->Word = Name;
	CommandAdd(Cmd, Name, Description, Type, ASLR ? Addr(CallAddr) : (void*)CallAddr);
	CommandInsert(CmdDict);
}

void Console::SetupCommands() {
	CreateCommand("Havok_use_single_step", "Description for Havok_use_single_step", 2, 0x0080DE50);
	CreateCommand("Print_item_list", "Prints a list of all the items to a text file", 3, 0x00809890);
	CreateCommand("R_stitch_batching_toggle", "Description for R_stitch_batching_toggle", 3, 0x0091B080);
	CreateCommand("Rl_clb_lod", "Description for Rl_clb_lod", 1, 0x004BAD90);
	CreateCommand("Rl_shadow_map_mode", "Description for Rl_shadow_map_mode", 1, 0x004C8710);
	CreateCommand("Rl_shadow_map_type", "Description for Rl_shadow_map_type", 1, 0x004C7840);
	CreateCommand("TOD_light_on_off", "Description for TOD_light_on_off", 2, 0x007C52B0);
	CreateCommand("Test_assert_handling", "Description for Test_assert_handling", 3, 0x0089AC20);
	CreateCommand("Test_crash_handling", "Description for Test_crash_handling", 3, 0x0089AC10);
	CreateCommand("Test_text_scale", "Description for Test_text_scale", 3, 0x008C6DD0);
	CreateCommand("Wind_dir_wind", "Description for Wind_dir_wind", 3, 0x00BECBC0);
	CreateCommand("activities_enable", "Description for activities_enable", 2, 0x00B1F910);
	CreateCommand("activity_start", "Description for activity_start", 1, 0x007AF760);
	CreateCommand("add_hud_message", "Description for add_hud_message", 1, 0x008E8100);
	CreateCommand("add_passenger", "Description for add_passenger", 3, 0x00ACC930);
	CreateCommand("add_secondary_hud_message", "Description for add_secondary_hud_message", 1, 0x008E81A0);
	CreateCommand("add_secondary_hud_message_special", "Description for add_secondary_hud_message_special", 1, 0x008E8240);
	CreateCommand("ai_continuous_attack_tweak", "Description for ai_continuous_attack_tweak", 1, 0x005F42C0);
	CreateCommand("air_bomb_reload", "Description for air_bomb_reload", 3, 0x00772750);
	CreateCommand("air_bomb_start", "Description for air_bomb_start", 1, 0x007726D0);
	CreateCommand("area_defense_start", "Description for area_defense_start", 3, 0x007A8930);
	CreateCommand("autosave_now", "Description for autosave_now", 3, 0x007C1C00);
	CreateCommand("birds_eye_cam", "Description for birds_eye_cam", 0, 0x006CAE70);
	CreateCommand("blast_decal", "Description for blast_decal", 3, 0x0074EE80);
	CreateCommand("blood_decal", "Description for blood_decal", 3, 0x0074C410);
	CreateCommand("blood_pool", "Description for blood_pool", 3, 0x006E16B0);
	CreateCommand("cam_config", "Description for cam_config", 1, 0x006CAB20);
	CreateCommand("cam_fov", "Description for cam_fov", 2, 0x006CAE00);
	CreateCommand("cam_heading_stop_time", "Description for cam_heading_stop_time", 2, 0x006C4350);
	CreateCommand("camera_first_person", "Description for camera_first_person", 0, 0x006D1570);
	CreateCommand("camera_invert_x", "Description for camera_invert_x", 0, 0x006C8B00);
	CreateCommand("camera_invert_y", "Description for camera_invert_y", 0, 0x006C8A10);
	CreateCommand("camera_smoothing_factor", "Description for camera_smoothing_factor", 2, 0x006C8970);
	CreateCommand("camera_third_person", "Description for camera_third_person", 0, 0x006D4AC0);
	CreateCommand("camera_third_person_offset", "Description for camera_third_person_offset", 4, 0x006C7030);
	CreateCommand("camera_third_person_offset_close", "Description for camera_third_person_offset_close", 4, 0x006C70C0);
	CreateCommand("camera_third_person_offset_scope", "Description for camera_third_person_offset_scope", 4, 0x006C7150);
	CreateCommand("camera_third_person_offset_sprint", "Description for camera_third_person_offset_sprint", 4, 0x006C71E0);
	CreateCommand("camera_turret_smooth_damp", "Description for camera_turret_smooth_damp", 2, 0x006C88B0);
	CreateCommand("camera_turret_smooth_strength", "Description for camera_turret_smooth_strength", 2, 0x006C8910);
	CreateCommand("civilian_morale_change", "Description for civilian_morale_change", 1, 0x007AFBE0);
	CreateCommand("clear_debris", "Description for clear_debris", 3, 0x00A624F0);
	CreateCommand("complete_mission", "Description for complete_mission", 3, 0x007B09F0);
	CreateCommand("complete_missions", "Description for complete_missions", 3, 0x007B09A0);
	CreateCommand("console_close", "Description for console_close", 3, 0x005BE150);
	CreateCommand("console_set_bg_color", "Description for console_set_bg_color", 1, 0x005BE180);
	CreateCommand("cutscene_play", "Description for cutscene_play", 3, 0x0070DE60);
	CreateCommand("decal_info_reload", "Description for decal_info_reload", 3, 0x007F2F80);
	CreateCommand("destruction_status", "Description for destruction_status", 3, 0x009528B0);
	CreateCommand("detonate_charges", "Description for detonate_charges", 3, 0x00ACD980);
	CreateCommand("detonate_mines", "Description for detonate_mines", 3, 0x00A94F90);
	CreateCommand("difficulty_level", "Description for difficulty_level", 1, 0x00772C80);
	CreateCommand("display_tool_tip", "Description for display_tool_tip", 1, 0x008EB700);
	CreateCommand("drop_backpack", "Description for drop_backpack", 3, 0x009AFB80);
	CreateCommand("drop_item", "Description for drop_item", 3, 0x00A63870);
	CreateCommand("drop_ped", "Description for drop_ped", 3, 0x00A32E60);
	CreateCommand("drop_squad", "Description for drop_squad", 3, 0x007B5210);
	CreateCommand("dump_dynamic_mem_stats", "Description for dump_dynamic_mem_stats", 3, 0x005BC860);
	CreateCommand("dump_dynamic_mem_usage", "Description for dump_dynamic_mem_usage", 3, 0x005CB3D0);
	CreateCommand("dump_lua_globals", "Description for dump_lua_globals", 3, 0x00C32330);
	CreateCommand("edf_control_change", "Description for edf_control_change", 2, 0x007B4660);
	CreateCommand("edf_progression_level", "Description for edf_progression_level", 1, 0x0079CF90);
	CreateCommand("effects_list", "Description for effects_list", 3, 0x0074CC90);
	CreateCommand("enable_menu_item", "Description for enable_menu_item", 3, 0x008CB370);
	CreateCommand("explosion", "Description for explosion", 3, 0x006EF560);
	CreateCommand("find_chunk", "Description for find_chunk", 3, 0x0091A130);
	CreateCommand("find_chunk_texture", "Description for find_chunk_texture", 3, 0x0091A240);
	CreateCommand("find_fuel_cell", "Description for find_fuel_cell", 3, 0x00B1F920);
	CreateCommand("force_compact", "Description for force_compact", 3, 0x0091AD20);
	CreateCommand("force_melee_combat_move", "Description for force_melee_combat_move", 3, 0x00A09170);
	CreateCommand("fow_opacity", "Description for fow_opacity", 2, 0x0083F6A0);
	CreateCommand("game_clock_set", "Description for game_clock_set", 1, 0x007CD560);
	CreateCommand("gameaudio_restart", "Description for gameaudio_restart", 3, 0x007BB290);
	CreateCommand("gamelog_dump_crc_maps", "Description for gamelog_dump_crc_maps", 3, 0x00750A70);
	CreateCommand("gamelog_dump_crc_maps_mp", "Description for gamelog_dump_crc_maps_mp", 3, 0x0074F320);
	CreateCommand("gamelog_dump_crc_maps_wc", "Description for gamelog_dump_crc_maps_wc", 3, 0x0074F4D0);
	CreateCommand("get_my_ip", "Description for get_my_ip", 3, 0x005D1990);
	CreateCommand("glare_free_all", "Description for glare_free_all", 3, 0x006E8670);
	CreateCommand("glares_toggle", "Description for glares_toggle", 3, 0x006E21C0);
	CreateCommand("glass_impact", "Description for glass_impact", 3, 0x006E3610);
	CreateCommand("global_progression_level", "Description for global_progression_level", 2, 0x0079CEE0);
	CreateCommand("handbook_unlock", "Description for handbook_unlock", 3, 0x00857090);
	CreateCommand("handbook_unlock_all", "Description for handbook_unlock_all", 3, 0x008688B0);
	CreateCommand("handbook_unlock_bftp", "Description for handbook_unlock_bftp", 3, 0x008570C0);
	CreateCommand("havok_bpo_counts", "Description for havok_bpo_counts", 3, 0x0091CDF0);
	CreateCommand("havok_mem", "Description for havok_mem", 3, 0x00829490);
	CreateCommand("hide_loading_screen", "Description for hide_loading_screen", 3, 0x008EFB40);
	CreateCommand("high_resolution_weapons", "Description for high_resolution_weapons", 3, 0x00A63B80);
	CreateCommand("hudtimer_pause", "Description for hudtimer_pause", 3, 0x007CD980);
	CreateCommand("hudtimer_stop", "Description for hudtimer_stop", 3, 0x007CD940);
	CreateCommand("hudtimer_unpause", "Description for hudtimer_unpause", 3, 0x007CD9C0);
	CreateCommand("i_killed_me", "Description for i_killed_me", 3, 0x009AC1E0);
	CreateCommand("jetter_rocket_delay", "Description for jetter_rocket_delay", 2, 0x00BD91D0);
	CreateCommand("kill_all_effects", "Description for kill_all_effects", 3, 0x007480A0);
	CreateCommand("letterbox", "Description for letterbox", 3, 0x008A6920);
	CreateCommand("level", "Loads a level", 3, 0x008896C0);
	CreateCommand("level_single", "Loads a level (does not work in multiplayer)", 3, 0x008897D0);
	CreateCommand("liberate_district", "Description for liberate_district", 3, 0x007B0A80);
	CreateCommand("load_balance_explosion_pct", "Description for load_balance_explosion_pct", 1, 0x00711900);
	CreateCommand("load_dlc_level", "Description for load_dlc_level", 3, 0x007CB6C0);
	CreateCommand("load_script", "Loads a given script file", 3, 0x00B402B0);
	CreateCommand("localize_set_language", "Description for localize_set_language", 3, 0x008F16C0);
	CreateCommand("lod_level", "Description for lod_level", 1, 0x00A13C80);
	CreateCommand("lower_alert_level", "Description for lower_alert_level", 3, 0x006FB670);
	CreateCommand("make_courier_stuck", "Description for make_courier_stuck", 3, 0x00796F80);
	CreateCommand("marauder_progression_level", "Description for marauder_progression_level", 1, 0x0079D000);
	CreateCommand("max_explosion_unique_id", "Description for max_explosion_unique_id", 3, 0x006E2040);
	CreateCommand("max_weapon_unique_id", "Description for max_weapon_unique_id", 3, 0x00BD9E40);
	CreateCommand("mission_set_enabled", "Description for mission_set_enabled", 3, 0x00AB3CB0);
	CreateCommand("mission_start", "Starts a provided mission", 3, 0x007AF660);
	CreateCommand("mission_status", "Description for mission_status", 3, 0x00774970);
	CreateCommand("morale_test_mission_unlock", "Description for morale_test_mission_unlock", 3, 0x008940E0);
	CreateCommand("mouse_cap", "Description for mouse_cap", 2, 0x006F8870);
	CreateCommand("mouse_sensitivity", "Changes the mouse sensitivity", 2, 0x005B7770);
	CreateCommand("mp_alter_xp", "Alters your XP in multiplayer", 1, 0x00987140);
	CreateCommand("mp_auto_launch_force_next_state", "Description for mp_auto_launch_force_next_state", 3, 0x0097B6D0);
	CreateCommand("mp_auto_launch_set_timer", "Description for mp_auto_launch_set_timer", 1, 0x0097B6F0);
	CreateCommand("mp_badge_reload_table", "Description for mp_badge_reload_table", 3, 0x009F0530);
	CreateCommand("mp_badge_set", "Description for mp_badge_set", 1, 0x009AC050);
	CreateCommand("mp_channel", "Description for mp_channel", 3, 0x00942EC0);
	CreateCommand("mp_display_bandwidth_settings", "Description for mp_display_bandwidth_settings", 3, 0x009475B0);
	CreateCommand("mp_lag", "Description for mp_lag", 1, 0x005BCB90);
	CreateCommand("mp_lag_bad", "Description for mp_lag_bad", 3, 0x005BCE90);
	CreateCommand("mp_lag_good", "Description for mp_lag_good", 3, 0x005BD030);
	CreateCommand("mp_lag_max", "Description for mp_lag_max", 1, 0x005BCC50);
	CreateCommand("mp_lag_med", "Description for mp_lag_med", 3, 0x005BCFA0);
	CreateCommand("mp_lag_min", "Description for mp_lag_min", 1, 0x005BCC00);
	CreateCommand("mp_lag_none", "Description for mp_lag_none", 3, 0x005BD0C0);
	CreateCommand("mp_lag_streak", "Description for mp_lag_streak", 1, 0x005BCE50);
	CreateCommand("mp_lag_tcr", "Description for mp_lag_tcr", 3, 0x005BCF20);
	CreateCommand("mp_laginfo", "Description for mp_laginfo", 3, 0x005BCE40);
	CreateCommand("mp_list_players", "Description for mp_list_players", 3, 0x009973C0);
	CreateCommand("mp_lobby_team_assignments_reset", "Description for mp_lobby_team_assignments_reset", 3, 0x009C5C70);
	CreateCommand("mp_long_name_all", "Description for mp_long_name_all", 3, 0x00997490);
	CreateCommand("mp_long_name_local", "Description for mp_long_name_local", 3, 0x0097ADB0);
	CreateCommand("mp_loss", "Description for mp_loss", 1, 0x005BCCA0);
	CreateCommand("mp_loss_max", "Description for mp_loss_max", 1, 0x005BCDD0);
	CreateCommand("mp_loss_min", "Description for mp_loss_min", 1, 0x005BCD60);
	CreateCommand("mp_override_stored_qos", "Description for mp_override_stored_qos", 1, 0x0098FE40);
	CreateCommand("mp_qos_info", "Description for mp_qos_info", 3, 0x00972A40);
	CreateCommand("mp_release_final_timeouts", "Description for mp_release_final_timeouts", 3, 0x00943260);
	CreateCommand("mp_reload_rubberbanding_table", "Description for mp_reload_rubberbanding_table", 3, 0x009842A0);
	CreateCommand("mp_reset_upstreams", "Description for mp_reset_upstreams", 3, 0x0098FDD0);
	CreateCommand("mp_set_bandwidth", "Description for mp_set_bandwidth", 1, 0x009A9470);
	CreateCommand("mp_set_packet_rate", "Description for mp_set_packet_rate", 1, 0x00947650);
	CreateCommand("mp_toggle_fill", "Description for mp_toggle_fill", 3, 0x009729F0);
	CreateCommand("mp_version", "Description for mp_version", 3, 0x0098E3C0);
	CreateCommand("music_limited", "Description for music_limited", 3, 0x007BF960);
	CreateCommand("music_minimum", "Description for music_minimum", 3, 0x007BF870);
	CreateCommand("music_volume", "Description for music_volume", 2, 0x007BF7C0);
	CreateCommand("npc_disarm_all", "Description for npc_disarm_all", 3, 0x00AD5480);
	CreateCommand("objective_highlight_ground_marker_kill", "Description for objective_highlight_ground_marker_kill", 3, 0x00B3E130);
	CreateCommand("play_last_effect", "Description for play_last_effect", 3, 0x007480B0);
	CreateCommand("play_video", "Description for play_video", 3, 0x00BD87A0);
	CreateCommand("player_pratfalls", "Description for player_pratfalls", 3, 0x006F6800);
	CreateCommand("print_to_file", "Prints a list of all the available commands to console_commands.txt", 3, 0x005CBFB0);
	CreateCommand("print_to_tty", "Description for print_to_tty", 3, 0x005C4820);
	CreateCommand("r_camlight", "Description for r_camlight", 3, 0x007C1FA0);
	CreateCommand("r_fog_atmosphere_scale", "Description for r_fog_atmosphere_scale", 2, 0x007C2210);
	CreateCommand("r_fog_density", "Description for r_fog_density", 2, 0x007C20D0);
	CreateCommand("r_fog_density_offset", "Description for r_fog_density_offset", 2, 0x007C2170);
	CreateCommand("r_fog_ground", "Description for r_fog_ground", 2, 0x007C22B0);
	CreateCommand("r_quadtree_reset", "Description for r_quadtree_reset", 3, 0x007C20B0);
	CreateCommand("r_quadtree_set_max_depth", "Description for r_quadtree_set_max_depth", 1, 0x007C2040);
	CreateCommand("r_quadtree_set_size", "Description for r_quadtree_set_size", 2, 0x007C1FC0);
	CreateCommand("r_saturation", "Overwrites the saturation", 2, 0x007C2470);
	CreateCommand("r_show_mem_usage", "Description for r_show_mem_usage", 3, 0x007CF240);
	CreateCommand("r_tint", "Description for r_tint", 3, 0x007C2350);
	CreateCommand("r_ugly_mode", "Enables/disables ugly mode", 0, 0x007C1F50);
	CreateCommand("ragdoll_player", "Description for ragdoll_player", 3, 0x00AD4B10);
	CreateCommand("raise_alert_level", "Description for raise_alert_level", 3, 0x006FB640);
	CreateCommand("reconstructor_passes", "Description for reconstructor_passes", 1, 0x00A1E0E0);
	CreateCommand("refresh_dlc", "Description for refresh_dlc", 3, 0x0089F400);
	CreateCommand("refresh_rasterizer_states", "Description for refresh_rasterizer_states", 3, 0x00516B80);
	CreateCommand("regrow_test", "Description for regrow_test", 3, 0x0071E5E0);
	CreateCommand("reload_backpack_table", "Description for reload_backpack_table", 3, 0x009F1160);
	CreateCommand("reload_camera_view", "Description for reload_camera_view", 3, 0x006D65C0);
	CreateCommand("reload_difficulty_table", "Description for reload_difficulty_table", 3, 0x0075CF70);
	CreateCommand("reload_fsmi", "Description for reload_fsmi", 3, 0x0087A690);
	CreateCommand("reload_glass_table", "Description for reload_glass_table", 3, 0x006E4320);
	CreateCommand("reload_heartbeat", "Description for reload_heartbeat", 3, 0x00855A20);
	CreateCommand("reload_melee_table", "Description for reload_melee_table", 3, 0x00AB5E00);
	CreateCommand("reload_mp_character_table", "Description for reload_mp_character_table", 3, 0x009F0560);
	CreateCommand("reload_shaders", "Description for reload_shaders", 3, 0x004F6230);
	CreateCommand("reload_tod", "Description for reload_tod", 3, 0x007F0000);
	CreateCommand("reload_tweak_table", "Description for reload_tweak_table", 3, 0x007EF170);
	CreateCommand("reload_weapons", "Description for reload_weapons", 3, 0x00BE4090);
	CreateCommand("remote_console", "Description for remote_console", 3, 0x009DBA80);
	CreateCommand("remove_backpack", "Description for remove_backpack", 3, 0x009F10A0);
	CreateCommand("remove_explosives", "Description for remove_explosives", 3, 0x00A71510);
	CreateCommand("reset_tool_tips", "Description for reset_tool_tips", 3, 0x008B2B40);
	CreateCommand("rfg_dynamic_link_dump_info", "Description for rfg_dynamic_link_dump_info", 3, 0x007259C0);
	CreateCommand("rfgm_destruction_uid", "Description for rfgm_destruction_uid", 1, 0x00998680);
	CreateCommand("rfgm_game_handle", "Description for rfgm_game_handle", 1, 0x009BDBC0);
	CreateCommand("rfgm_net_handle", "Description for rfgm_net_handle", 1, 0x009BDB90);
	CreateCommand("riding_shotgun_play_story_section", "Description for riding_shotgun_play_story_section", 1, 0x00799D20);
	CreateCommand("riding_shotgun_start", "Description for riding_shotgun_start", 3, 0x007A96F0);
	CreateCommand("rl_shadow_map_slope_zbias", "Description for rl_shadow_map_slope_zbias", 2, 0x004C8870);
	CreateCommand("rl_shadow_map_world_zbias", "Description for rl_shadow_map_world_zbias", 2, 0x004C87F0);
	CreateCommand("road_set_gps_only", "Description for road_set_gps_only", 3, 0x00AAA120);
	CreateCommand("safehouse_enable", "Description for safehouse_enable", 0, 0x00AB40E0);
	CreateCommand("safehouse_set_visible", "Description for safehouse_set_visible", 0, 0x00A93480);
	CreateCommand("satellite_test", "Initiate a test for the satellite mode", 3, 0x006D4060);
	CreateCommand("satellite_test_stop", "Stop the satellite mode test", 3, 0x006D4140);
	CreateCommand("scheduler", "Description for scheduler", 3, 0x005BD340);
	CreateCommand("script", "Description for script", 3, 0x005D01E0);
	CreateCommand("search", "Look for a command based on key characters", 3, 0x005C55A0);
	CreateCommand("set_camera_bone", "Description for set_camera_bone", 3, 0x006D15E0);
	CreateCommand("set_civilian_morale", "Description for set_civilian_morale", 2, 0x007AABB0);
	CreateCommand("set_player_start", "Description for set_player_start", 0, 0x0091BF90);
	CreateCommand("set_safe_area", "Description for set_safe_area", 3, 0x005208C0);
	CreateCommand("shape_cutter_test", "Description for shape_cutter_test", 3, 0x00737620);
	CreateCommand("shard_fade_dist0", "Description for shard_fade_dist0", 2, 0x00A13B60);
	CreateCommand("shard_fade_dist1", "Description for shard_fade_dist1", 2, 0x00A13BF0);
	CreateCommand("show_district_liberation", "Description for show_district_liberation", 3, 0x00868770);
	CreateCommand("show_kill_message", "Description for show_kill_message", 3, 0x008970E0);
	CreateCommand("show_loaded_chunks", "Description for show_loaded_chunks", 3, 0x00928120);
	CreateCommand("show_loading_screen", "Description for show_loading_screen", 3, 0x00908DB0);
	CreateCommand("show_menu_item", "Description for show_menu_item", 1, 0x008CB410);
	CreateCommand("show_upgrades", "Description for show_upgrades", 3, 0x0084AFC0);
	CreateCommand("show_weapon_cabinet", "Description for show_weapon_cabinet", 3, 0x0084B490);
	CreateCommand("show_zone_navmesh", "Description for show_zone_navmesh", 3, 0x0091D240);
	CreateCommand("snap_tod_light_to_camera", "Description for snap_tod_light_to_camera", 3, 0x007C55C0);
	CreateCommand("sniper_zoom_min", "Description for sniper_zoom_min", 2, 0x006C43B0);
	CreateCommand("sound", "Description for sound", 0, 0x007BB300);
	CreateCommand("sound_play", "Description for sound_play", 3, 0x007BB410);
	CreateCommand("sound_play_3d", "Description for sound_play_3d", 3, 0x007BB600);
	CreateCommand("sound_reset_stats", "Description for sound_reset_stats", 3, 0x007BB2F0);
	CreateCommand("stream_debug", "Description for stream_debug", 3, 0x0091D4F0);
	CreateCommand("stream_radius", "Description for stream_radius", 2, 0x0091D260);
	CreateCommand("stream_radius_terrain", "Description for stream_radius_terrain", 2, 0x0091D390);
	CreateCommand("subtitle_add", "Description for subtitle_add", 3, 0x008F6B90);
	CreateCommand("tank_camera_type", "Description for tank_camera_type", 3, 0x006C4260);
	CreateCommand("tech_level_change", "Description for tech_level_change", 2, 0x00773A60);
	CreateCommand("tech_level_display", "Description for tech_level_display", 3, 0x0079D0D0);
	CreateCommand("tech_level_max_change", "Description for tech_level_max_change", 2, 0x00773BC0);
	CreateCommand("tech_level_max_set", "Description for tech_level_max_set", 2, 0x00773B20);
	CreateCommand("tech_level_set", "Description for tech_level_set", 2, 0x0079D070);
	CreateCommand("test_matfx_on_player", "Description for test_matfx_on_player", 1, 0x006F60C0);
	CreateCommand("test_terrain_cast_shadows", "Description for test_terrain_cast_shadows", 0, 0x0092AAC0);
	CreateCommand("tod_ambient", "Description for tod_ambient", 3, 0x007D9FE0);
	CreateCommand("tod_back_ambient", "Description for tod_back_ambient", 3, 0x007DA590);
	CreateCommand("tod_cloud_horizon_strenghts", "Description for tod_cloud_horizon_strenghts", 3, 0x007DB670);
	CreateCommand("tod_cloud_overhead_strenghts", "Description for tod_cloud_overhead_strenghts", 3, 0x007DBA90);
	CreateCommand("tod_enabled", "Description for tod_enabled", 0, 0x007C55F0);
	CreateCommand("tod_fog_atmosphere_scale", "Description for tod_fog_atmosphere_scale", 2, 0x007DB250);
	CreateCommand("tod_fog_color", "Description for tod_fog_color", 3, 0x007DAB40);
	CreateCommand("tod_fog_density", "Description for tod_fog_density", 2, 0x007DB3B0);
	CreateCommand("tod_fog_density_offset", "Description for tod_fog_density_offset", 2, 0x007DB510);
	CreateCommand("tod_fog_ground", "Description for tod_fog_ground", 2, 0x007DB0F0);
	CreateCommand("tod_light_angles", "Description for tod_light_angles", 3, 0x007C54C0);
	CreateCommand("tod_light_color", "Description for tod_light_color", 3, 0x007D9AF0);
	CreateCommand("toggle_subtitle_name", "Description for toggle_subtitle_name", 3, 0x008A17B0);
	CreateCommand("turret_reload", "Description for turret_reload", 3, 0x00A20600);
	CreateCommand("tweak_table", "Description for tweak_table", 3, 0x007EB230);
	CreateCommand("ui_kill_all_msgbox", "Description for ui_kill_all_msgbox", 3, 0x008F0450);
	CreateCommand("ui_msgbox_test", "Description for ui_msgbox_test", 3, 0x008A1B60);
	CreateCommand("use_attack", "Description for use_attack", 3, 0x00A09210);
	CreateCommand("vai", "Description for vai", 3, 0x00BD5900);
	CreateCommand("validate_client_movers", "Description for validate_client_movers", 3, 0x009C5220);
	CreateCommand("validate_mp_announce", "Description for validate_mp_announce", 3, 0x0094ED40);
	CreateCommand("vehicle_bomb", "Description for vehicle_bomb", 3, 0x00B96B40);
	CreateCommand("vehicle_camera_type", "Description for vehicle_camera_type", 3, 0x006C4170);
	CreateCommand("vehicle_max_speed", "Description for vehicle_max_speed", 2, 0x00B63190);
	CreateCommand("vehicle_slots", "Description for vehicle_slots", 3, 0x00B6CF80);
	CreateCommand("vehicle_stop", "Description for vehicle_stop", 3, 0x00BCF490);
	CreateCommand("vfx_step_emitter_next", "Description for vfx_step_emitter_next", 3, 0x005D18B0);
	CreateCommand("vfx_step_emitter_prev", "Description for vfx_step_emitter_prev", 3, 0x005D18C0);
	CreateCommand("vfx_step_object_next", "Description for vfx_step_object_next", 3, 0x005D1890);
	CreateCommand("vfx_step_object_prev", "Description for vfx_step_object_prev", 3, 0x005D18A0);
	CreateCommand("video_cutscene_play", "Description for video_cutscene_play", 3, 0x0070D9F0);
	CreateCommand("vint_doc_load", "Description for vint_doc_load", 3, 0x00482900);
	CreateCommand("vint_doc_reload", "Description for vint_doc_reload", 3, 0x00482980);
	CreateCommand("vint_doc_reload_all", "Description for vint_doc_reload_all", 3, 0x00482A10);
	CreateCommand("vint_doc_unload", "Description for vint_doc_unload", 3, 0x00481EC0);
	CreateCommand("vint_doc_unload_all", "Description for vint_doc_unload_all", 3, 0x00481F30);
	CreateCommand("wc_change_timer", "Description for wc_change_timer", 3, 0x0075F7F0);
	CreateCommand("wc_give_stat_points", "Description for wc_give_stat_points", 3, 0x0075F820);
	CreateCommand("wc_lock_map", "Description for wc_lock_map", 3, 0x00790EC0);
	CreateCommand("wc_unlock_map", "Description for wc_unlock_map", 3, 0x00776760);
	CreateCommand("wind", "Enables/disables wind", 0, 0x00BECDF0);
	CreateCommand("wind_speed", "Changes the speed of the wind", 2, 0x00BECB20);
	CreateCommand("xray_humans", "Description for xray_humans", 3, 0x006EE7B0);
	CreateCommand("zone_max_wind_speed", "Description for zone_max_wind_speed", 2, 0x00BEC540);
	CreateCommand("zone_min_wind_speed", "Description for zone_min_wind_speed", 2, 0x00BEC490);
	CreateCommand("drop_car", "Usage: drop_car name", 2, (uintptr_t)Vehicles::Spawner, false);
}