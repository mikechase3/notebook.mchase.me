# Capture The Flag Notes

Eventually I want to redo this and make it into a tutorial. Maybe I will today.

## Assigning Teams on Player State from GameMode

First, make an enum.

<figure><img src="../../../.gitbook/assets/image (7).png" alt=""><figcaption></figcaption></figure>

Second, assign teams.&#x20;

<figure><img src="../../../.gitbook/assets/2024-07-03_10-20.jpg" alt=""><figcaption></figcaption></figure>

The Game Mode has a function `GetGameState()` which contains the `PlayerArray` of all player's `Player State` references in an array. Zero is the server, and if you add another one it gets `1` and `2` and so on. To add more, you can allegedly just set it to `-1` and UE will append it to the end of `PlayerArray`.&#x20;

## Debugging

<figure><img src="../../../.gitbook/assets/image (4).png" alt=""><figcaption></figcaption></figure>

Also - why didn't this print?

<figure><img src="../../../.gitbook/assets/image (5).png" alt=""><figcaption></figcaption></figure>

The succeeded here and didn't print `Hello` in the game mode.

<figure><img src="../../../.gitbook/assets/image (6).png" alt=""><figcaption></figcaption></figure>

## Initial Design

<figure><img src="../../../.gitbook/assets/CTF Assets.png" alt=""><figcaption></figcaption></figure>
