# UE5 Networking Multiplayer

Start here:

{% embed url="https://www.youtube.com/watch?v=ef6SeknakeU" %}

## Notes on Custom Lobby
1. Starts in `FirstPersonBP/Maps`. Make a level there.
2. In Content/NetworkBase/NetworkEnums, modify the appropriate enum. Must match level name (for now).
3. The Content/NetworkBase/NetworkBasePlayerController goto NotifyServerStartGame. It calls LoadNewLevel from NetworkBaseGameInstance
4. NetworkBaseGameInstance has a "LoadNewLevel" event. 
5. The LoadNewLevel executes only on the server. It'll take the server's GameStateBase and sets its CurrentActiveLevel
6. Since the NetworkBaseGameState syncs from server to clients automatically (I think)_, it'll change that str variable and call "servertravel <levelname>" a console command on a controller?
