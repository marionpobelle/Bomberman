# Presentation

![bEKhqe](https://github.com/alvina-dr/indecis/assets/112869026/79028da4-c3ca-4623-928c-a57234bb83db)

A remake of the classic Bomberman, playable in local multiplayer.  After launching the game from the main menu, players appear in two different corners of the map. Their objective is to reach the other player and and eliminate them. Both players are able to place bombs on the ground. A bomb will be placed in the last direction taken by the player and will generate a cross-shaped explosion capable of inflicting damage on the opposing player and the destructible walls of the map. The map is made up of a solid part, indestructible yellow walls which define solid boundaries for players, and a number of destructible walls that add a strategic dimension to the game.

![GIF_20-10-2023_14-33-10](https://github.com/alvina-dr/indecis/assets/112869026/b89dc932-e919-486f-80c6-57c88637210f)

![GIF_19-10-2023_21-02-19](https://github.com/alvina-dr/indecis/assets/112869026/c0dc9c17-0bd3-4409-b2b0-293468e586a0)

# Controls

Player 1 (Blue) : Movement uses the ARROW KEYS,  press SHIFT to place a bomb.

Player 2 (Green) : Movement uses Q (left), D (right), Z (top), S (bottom), press E to place a bomb.

# Demo

[Bomberman Trailer](https://www.youtube.com/watch?v=giArnZTPAPo&ab_channel=Alvina)

# Credits

[Alvina Damasio-Razafiarizaka](https://alvina-dr.itch.io/) \n

[Marion Pobelle](https://vitaminexe.itch.io/)

# Development

This game was made by ENJMIN students in a few weeks, as a way to learn C++. The main challenge was that all the graphics had to be shown in the console in ASCII. [Visual Studio](https://visualstudio.microsoft.com/fr/) was used to develop this game.

Class Diagram :

![Class_Diagram](https://github.com/alvina-dr/indecis/assets/112869026/be3aba57-3312-4a79-b30c-ba0ae6d286ea)

# TDL

- [x] MAZE
- - [x] Border sprites
- - [x] File system
- - [x] Tiling system
- - [x] Conversion Grid to Buffer
- - [x] Destructible walls

- [x] PLAYER
- - [x] Movement
- - [x] Sprite
- - [x] Animation
- - [x] Actions (place bomb)
- - [x] Collision

- [x] BOMB
- - [x] Sprite
- - [x] Animation
- - [x] Effect (explosion, animation, damage and distance)
- - [x] Collision

- [x] UI
- - [x] Visuals
- - [x] Main menu
- - [x] In-game indications
- - [x] Health
- - [x] Game over

- [x] MUSIC
- - [x] Main music
- - [x] Placing bomb SE
- - [x] Explosion SE
