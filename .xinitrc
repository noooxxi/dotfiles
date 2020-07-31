#!/bin/sh

# Sets keyboard layout to Swedish
setxkbmap -layout se

# Starts the compositor daemon. Commented out due to power consumption
# picom -b --experimental-backends

# Starts the torrent daemon
# transmission-daemon

# Starts power managment utility
# sudo powertop --auto-tune

# Sets wallpaper and defines colorscheme
wal -i "/usr/share/wallpapers/buddha.png" --saturate 0.8

# Starts the music player dameon
mpd

# Starts the status bar
~/.config/polybar/launch.sh

# Defines the primary display's refresh rate
xrandr --output eDP1 --rate 60

# Hides the mouse
unclutter -idle 1 -jitter 2 -root &

# Starts lockscreen daemon
light-locker &

# Starts the window manager
exec dwm
