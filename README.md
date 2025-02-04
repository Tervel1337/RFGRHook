# Red Faction Guerrilla Re-Mars-tered Hook
### **⚠️ WARNING: This ONLY works on the GOG version of the game! Steam support might come later down the road. ⚠️**

The aim of this project is to restore some of the game's debug functionality. Most notably, it restores all of the ~300 or so uninitialized console commands (and the console itself), which is only possible thanks to the debugging symbols available for the game, otherwise the command names would've had to be guessed. There are additional features as well.

### Keybinds
- **~/tilde** to open the console. It works the same way the console does in every other Volition game.
- **F1** - Toggle slew mode (freecam)
- **F2** - Hide the HUD
- **F3** - Pause the game (you can still move the camera while in slew)
- **F4** - Toggle the fog (kinda useless but the game heavily relies on fog so it's fun to see the map without it)
- **F5** - Teleport the player to the camera’s current position (useful for going out of bounds)

### Additional Features
- **Vehicle Spawner** - Since the original vehicle spawner is long gone, I've made a custom one which is added as a regular console command (drop_car). Refer to the vehicle names in the .xtbl to spawn vehicles.
- **Slew** - Unfortunately slew is super outdated and the default bindings are horrible, however if you play with a controller they're updated here to be modern (RT/LT to go up/down and LB/RB have been swapped around to make sense. I've also restored the mouse and keyboard controls for slew which the game disables on boot normally.
- **Intro & Legal Disclaimers Skip** - They're automatically going to get skipped, at some point I might make it configurable but if you're modding the game you're likely already tired of them.

### Installation
 - Download the latest release and extract it to your game folder
 - Get the x86 version of [ThirteenAG's Ultimate ASI Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader) and extract it to your game folder as well (or you can alternatively use a DLL injector of your choice)

### Credits

- Help: [ermaccer](https://github.com/ermaccer), [jas0n098](https://github.com/jas0n098)
- Silent: [ModUtils](https://github.com/CookiePLMonster/ModUtils)
- TsudaKageyu: [MinHook](https://github.com/TsudaKageyu/minhook)
