"Runs pathogen
execute pathogen#infect()
syntax on
filetype plugin indent on

"Sets the beloved relative number + number combo
set relativenumber
set number

"Disables automatic comment insertion
autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o
autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o

"Omnisharp
let g:OmniSharp_server_stdio = 1

"Fixes word wrapping
:set formatoptions=l
:set lbr

"Hotkeys
map <C-n> :NERDTreeToggle<CR>
map <C-j> })zz
map <C-k> {(0zz
map <F12> :setlocal spell! spelllang=en_us<CR>
map <F11> :setlocal spell! spelllang=sv<CR>
map <F10> :setlocal spell! spelllang=es_es<CR>

"Lightline
set laststatus=2
set noshowmode
let g:lightline = {
      \ 'colorscheme': 'buddha',
      \ }
