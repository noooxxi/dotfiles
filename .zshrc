# History configuration
HISTFILE=~/.histfile
HISTSIZE=10000
SAVEHIST=10000
export SAVEHIST=$HISTSIZE
setopt hist_ignore_all_dups

# Binds
bindkey -v

# Compinstall
zstyle :compinstall filename '$HOME/.zshrc'

# Advanced tab-completion
autoload -Uz compinit
compinit
zstyle ':completion:*:descriptions' format '%U%B%d%b%u'
zstyle ':completion:*:warnings' format '%BSorry, no matches for: %d%b'

# Command correction
setopt correctall

# Prompt
autoload -Uz promptinit
promptinit
#PROMPT='%(?.%F{magenta}√.%F{blue}?%?)%f %B%F{240}%1~%f%b %# '
PROMPT='%1~ %(?.%F{cyan}>%F{red}>%F{green}>.%F{magenta}?%?)%f '

# Loads aliases
source $HOME/.aliases

# Adds directories to $PATH
export PATH="$PATH:$(du "$HOME/.local/bin" | cut -f2 | paste -sd ':')"

# Ssh unknown terminal fix
export TERM=xterm

# Default programs
export EDITOR="vim"
export TERMINAL="kitty"
export BROWSER="firefox"
export READER="zathura"

# Change directory without cd
setopt autocd
