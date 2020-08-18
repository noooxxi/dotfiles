#!/bin/sh

# Sets keyboard layout to Swedish
setxkbmap -layout se

# Starts the compositor daemon
picom -b --experimental-backends

# Starts the torrent daemon
transmission-daemon

# Starts power managment utility
# sudo powertop --auto-tune

# Sets wallpaper and defines colorscheme
wal -i "/usr/share/wallpapers/1920x1080.png" --saturate 0.8

# Starts the music player dameon
mpd

# Starts the status bar
~/.config/polybar/launch.sh

# Desktop display configuration
xrandr --output DVI-D-0 --mode 1920x1080 --rate 144 --output DVI-I-1 --right-of DVI-D-0 --mode 1920x1080 --rate 144

# Laptop display configuration
# xrandr --output eDP1 --rate 60

# Hides the mouse
unclutter -idle 1 -jitter 2 -root &

# Starts lockscreen daemon
light-locker &

# Starts the window manager
exec ~/.config/dwm/startdwm
