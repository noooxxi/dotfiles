<p align="center">
  <b>noxxi's dotfiles</b>
</p>

<p align="center">
<a href="#setup"><img width="150px" style="padding: 0 10px;" src=".assets/setup.png"></a>
<a href="https://github.com/noooxxi/dotfiles/wiki"><img width="150px" style="padding: 0 10px;" src=".assets/wiki.png"></a>
<a href="https://github.com/noooxxi/dotfiles/wiki/Gallery"><img width="150px" style="padding: 0 10px;" src=".assets/gallery.png"></a>
<a href="#tips"><img width="150px" style="padding: 0 10px;" src=".assets/tipjar.png"></a>
</p>

<img src="https://i.imgur.com/FXnnfHT.png">

+ **OS**: [Arch Linux](https://www.archlinux.org/about/)
+ **WM**: [dwm](https://dwm.suckless.org/)
+ **Shell**: [zsh](https://wiki.archlinux.org/index.php/Zsh)
+ **Terminal**: [kitty](https://github.com/kovidgoyal/kitty/)
+ **Editor**: [vim](https://www.vim.org/)
+ **File Manager**: [ranger](https://github.com/ranger/ranger)
+ **Launcher**: [Rofi](https://github.com/davatorium/rofi)
+ **Browser**: [Firefox](https://www.mozilla.org/en-US/firefox/new/)

## Setup

1. Install dwm
   ```shell
   git clone https://github.com/noooxxi/dotfiles
   cd dotfiles
   mkdir ~/.config/dwm && mv -vi .config/dwm/* ~/.config/dwm
   cd ~/.config/dwm && sudo make clean install
   ```

2. Install applications
```shell
yay -S kitty ranger mutt-wizard-git newsboat transmission-cli ncmpcpp mpd pulsemixer discord gotop htop weechat
cd dotfiles
mv -vi .config/* ~/.config/
```
Populate the urls file and run newsboat once pointing to the configuration file. This is necessary since newsboat uses ~/.newsboat by default and thus won't load our settings.
```shell
echo "https://www.youtube.com/feeds/videos.xml?channel_id=UC2eYFnH61tmytImy1mTYvhA" >> ~/.config/newsboat/urls
newsboat -C ~/.config/newsboat/config
```

3. Install zsh
```shell
sudo pacman -S zsh zsh-completions
zsh
```
Press q to exit out of <i>zsh-newuser-install</i>.
```shell
mv -vi .zshrc ~/.zshrc && mv -vi .aliases ~/.aliases
chsh -s /bin/zsh
```

4. Configure neomutt
If you don't have a GPG key pair, run ``gpg --full-gen-key`` first. Otherwise, continue as instructed below:
```shell
pass init <yourgpgemail>
mw
```

## Keybinds

#### Applications
+ <kbd>Super + ↵</kbd> - Spawn terminal
+ <kbd>Super + e</kbd> - Spawn ranger
+ <kbd>Super + E</kbd> - Spawn neomutt
+ <kbd>Super + r</kbd> - Spawn newsboat
+ <kbd>Super + R</kbd> - Spawn transmission
+ <kbd>Super + m</kbd> - Spawn ncmpcpp
+ <kbd>Super + M</kbd> - Spawn pulsemixer
+ <kbd>Super + d</kbd> - Spawn discord
+ <kbd>Super + g</kbd> - Spawn gotop
+ <kbd>Super + G</kbd> - Spawn htop
+ <kbd>Super + c</kbd> - Spawn weechat

#### System
+ <kbd>Super + ↑</kbd> - Increase brightness
+ <kbd>Super + ↓</kbd> - Decrease brightness
+ <kbd>Super + +</kbd> - Increase volume
+ <kbd>Super + -</kbd> - Decrease volume
+ <kbd>Super + b</kbd> - Toggle bar
+ <kbd>Super + L</kbd> - Lock session

#### Music
+ <kbd>Super + p</kbd> - Pause/resume music
+ <kbd>Super + ,</kbd> - Play previous song
+ <kbd>Super + ;</kbd> - Go to start of song
+ <kbd>Super + .</kbd> - Play next song
+ <kbd>Super + :</kbd> - Toggle repeat song

#### Windows
+ <kbd>Super + q</kbd> - Close selected window
+ <kbd>Super + f</kbd> - Toggle fullscreen
+ <kbd>Super + o</kbd> - Increase number of master windows
+ <kbd>Super + O</kbd> - Decrease number of master windows
+ <kbd>Super + h</kbd> - Decrease master size
+ <kbd>Super + l</kbd> - Increase master size
+ <kbd>Super + j</kbd> - Next window
+ <kbd>Super + k</kbd> - Previous window
+ <kbd>Super + J</kbd> - Demote window
+ <kbd>Super + K</kbd> - Promote window
+ <kbd>Super + s</kbd> - Toggle stickiness
+ <kbd>Super + v</kbd> - Select master window
+ <kbd>Super + Space</kbd> - Make selected window master window
+ <kbd>Super + Shift + Space</kbd> - Make selected window floating/stacked
+ <kbd>Super + Shift + α</kbd> - Send selected window to tag α where α∈<img src="https://wikimedia.org/api/rest_v1/media/math/render/svg/fdf9a96b565ea202d0f4322e9195613fb26a9bed"> and 9≥α≥1 
+ <kbd>Super + Shift + 0</kbd> - Sticky selected window

#### Layout
+ <kbd>Super + F</kbd> - Floating layout
+ <kbd>Super + t</kbd> - Tiling layout with master to the left
+ <kbd>Super + T</kbd> - Tiling layout with master on top
+ <kbd>Super + y</kbd> - Fibonacci layout
+ <kbd>Super + Y</kbd> - Dwindle layout
+ <kbd>Super + u</kbd> - Deck layout
+ <kbd>Super + U</kbd> - Monocle layout
+ <kbd>Super + i</kbd> - Centered master layout
+ <kbd>Super + I</kbd> - Centered floating master layout
+ <kbd>Super + α</kbd> - Show tag α where α∈<img src="https://wikimedia.org/api/rest_v1/media/math/render/svg/fdf9a96b565ea202d0f4322e9195613fb26a9bed"> and 9≥α≥1 
+ <kbd>Super + 0</kbd> - Show all tags
+ <kbd>Super + a</kbd> - Toggle gaps
+ <kbd>Super + A</kbd> - Default gap size
+ <kbd>Super + z</kbd> - Increase gap size
+ <kbd>Super + x</kbd> - Decrease gap size

## Tips

BTC: 31kKisow1DfWy2VkYSVYnBEkXNjgZacGKE

LTC: MCj8a6kCGSFmrcemjtF9PWsR4hFt81o9Cg

DGB: DRcaykvRzCksfv3TqWLsLJ5z8Xuf7FwD6c
