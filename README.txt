request :
- You must create a small 2D game where a dolphin
escapes earth after eating some fish

program name :
    so_long.

tools
- itch.io
- make file
    all, clean , fclean, re, bonus
- map format must be in .ber
- open 
    create a file descriptor for the file he opened
- close
    close a file descriptor so that the fd may be reussed
- read
- printf
- malloc
- free
- perror
    create an error message during a call system,
- strerror
    return a pointer to a string that decribe the error
All functions of the MinilibX.
libft

========================================================================================
contraint:

must use the miniLibX

management of the window must remain swooth, and closing it with X must end the program

the currenct number of move must be displayed. (either in shell or in the game itself)

must use 2D view (top-down or profile)

game doesn't need to be in real time

player can't move into walls

program :
    -WASD to move the player.
    -esc to close the window and quit the game
    -X to close the window and quit the game.
    -the map must have one exit
    -you don't need to check if there is a valid path
    -the map must be a rectangle
    -able to read any map respecting those rule

the map :
    - 0 for empty spaces
    - 1 for walls
    - c for collectible
    - e for exit
    - p for player
    
        exemple of map:
            1111111111111
            10010000000C1
            1000011111001
            1P0011E000001
            1111111111111
    
    if there is an error return an explicit error message

============================================================================================

