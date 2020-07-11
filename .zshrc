# Lines configured by zsh-newuser-install
HISTFILE=~/.histfile
HISTSIZE=10000
SAVEHIST=10000
bindkey -v
# End of lines configured by zsh-newuser-install
# The following lines were added by compinstall
zstyle :compinstall filename '/home/isak/.zshrc'

autoload -Uz compinit promptinit
compinit
promptinit
# End of lines added by compinstall
PROMPT='%(?.%F{magenta}√.%F{blue}?%?)%f %B%F{240}%1~%f%b %# '
source $HOME/.aliases
(cat ~/.cache/wal/sequences &)
export TERM=xterm
