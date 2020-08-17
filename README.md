# imgview
A light C application to display images. Made with SDL.

# Dependencies
Depends on:
- SDL2 / SDL2_image (make, runtime)
All dependencies are subject to change.

# Compilation
Tested on Linux, known to work on MacOS.

- Linux - `gcc imgview.c -o imgview -L/usr/lib -pthread -lSDL2 -I/usr/include/SDL2 -D_REENTRANT -lSDL2_image`

- MacOS - `gcc imgview.c -o imgview -L/usr/local/lib -lSDL2 -I/usr/local/include/SDL2 -D_THREAD_SAFE -lSDL2_image`

# Usage
`Usage ([required] <optional>): 
imgview [image-path] <display-height display-width> <window-height window-width>`

This is also available in the application.

# Controls
Arrow keys - move image

# Planned Features
- Zoom in and out with I and O (in development)
- Rotating image (Coming Soon™)
- Autodetect image size (Long term)
- Resizing window (Long term)

If you encounter an issue with the program, please tell me.

Made by **genericrandom64**

If you like imgview, check out [the Zalgo Media Editor!](https://github.com/genericrandom64/zalgomediaeditor)
