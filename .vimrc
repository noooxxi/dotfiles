" Runs Pathogen
execute pathogen#infect()
syntax on
filetype plugin indent on

" Runs Lightline
set laststatus=2
set noshowmode
let g:lightline = { 'colorscheme': 'buddha', }

set relativenumber 									" Sets the beloved relative number + number combo
set number 										" Sets the beloved relative number + number combo
autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o		" Disables automatic comment insertion
:set formatoptions=l									" Fixes word wrapping
:set lbr										" Fixes word wrapping

" Hotkeys
map <C-n> :NERDTreeToggle<CR> 								" Toggle nerd tree
map <C-j> })zz										" Go to next paragraph
map <C-k> {(0zz 									" Go to previous paragraph 
map <F12> :setlocal spell! spelllang=en_us<CR>						" Toggle English spell check
map <F11> :setlocal spell! spelllang=sv<CR>				 		" Toggle Swedish spell check
map <F10> :setlocal spell! spelllang=es_es<CR>				 		" Toggle Spanish spell check
map cs :ThesaurusQueryReplaceCurrentWord<CR>				 		" Show synonyms of current word

" Split navigation
map <C-h> <C-w>h									" Go to left pane
map <C-j> <C-w>j									" Go to bottom pane
map <C-k> <C-w>k									" Go to top pane
map <C-l> <C-w>l									" Go to right pane

"HTML
autocmd FileType html inoremap ;p <p></p><Enter><Enter><++><Esc>2ki 			" Make p tag
autocmd FileType html inoremap ;b <b></b><Enter><Enter><++><Esc>2ki 			" Make b tag
autocmd FileType html inoremap ;i <em></em><Enter><Enter><++><Esc>2ki 			" Make i tag
autocmd FileType html inoremap ;h1 <h1></h1><Enter><Enter><++><Esc>2kli 		" Make h1 tag
autocmd FileType html inoremap ;h2 <h2></h2><Enter><Enter><++><Esc>2kli 		" Make h2 tag
autocmd FileType html inoremap ;h3 <h3></h3><Enter><Enter><++><Esc>2kli 		" Make h3 tag
autocmd FileType html inoremap ;a <a<Space>href=""><++></a><Space><++><Esc>13h		" Go to marker
