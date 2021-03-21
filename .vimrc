""""""""""PLUGINS""""""""""

" Enables the pathogen plugin manager
execute pathogen#infect()

" Enables plugins
filetype plugin on

" Runs Lightline
set laststatus=2
set noshowmode
let g:lightline = { 'colorscheme': 'buddha', }

""""""""""BASE SETTINGS""""""""""

" Enables syntax highlighting
syntax on

" Something important
filetype indent on

" Enables UTF-8 encoding by default
set encoding=utf-8

" Enables line numbers
set number

" Enables relative numbers
set relativenumber

" Disables automatic comment insertion
autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o

" Fixes word wrapping
set formatoptions=l
set lbr

""""""""""MISCELLANEOUS HOTKEYS""""""""""

" Go one paragraph down
map <C-j> })zz<CR><CR>

" Go one paragraph up
map <C-k> {(0zz<CR><CR>


""""""""""LATEX""""""""""

" Compiles on :w
autocmd BufWritePost *.tex silent! execute "!pdflatex %" | redraw!

" Reloads bibliography on C+O
autocmd FileType tex map <C-o> :!biber $(echo '%:r') >/dev/null 2>&1<CR><CR>

" Removes logs on :q
autocmd VimLeave *.tex !texclear %

" Opens pdf on Ctrl+P
autocmd FileType tex map <C-p> :!zathura $(echo '%:r.pdf') &<CR><CR>

" Opens bibliography on Ctrl+B
map <C-b> :!kitty -e vim ~/Documents/flugsvamp.txt &<CR><CR>

""""""""""SPLIT NAVIGATION""""""""""

" Go to left pane
map <C-h> <C-w>h

" Go to bottom pane
map <C-j> <C-w>j

" Go to top pane
map <C-k> <C-w>k

" Go to right pane
map <C-l> <C-w>l

""""""""""FUNCTION KEYS""""""""""

" Convert fileformat to unix
map <F4> :set fileformat=unix<CR> <bar> :echo "Fileformat converted to UNIX"<CR>

" Toggle Spanish spell check
map <F10> :setlocal spell! spelllang=es_es<CR>

" Toggle Swedish spell check
map <F11> :setlocal spell! spelllang=sv<CR>

" Toggle English spell check
map <F12> :setlocal spell! spelllang=en_us<CR>

""""""""""HTML SHORTCUTS""""""""""
autocmd FileType html inoremap <Space><Space> <Esc>/<++><Enter>4xi
autocmd FileType html inoremap ;p <p></p><Enter><Enter><++><Esc>2ki
autocmd FileType html inoremap ;b <b></b><Enter><Enter><++><Esc>2ki
autocmd FileType html inoremap ;i <em></em><Enter><Enter><++><Esc>2kli
autocmd FileType html inoremap ;a <a href=""><++></a><Enter><Enter><++><Esc>2k$9hi
autocmd FileType html inoremap ;h1 <h1></h1><Enter><Enter><++><Esc>2kli
autocmd FileType html inoremap ;h2 <h2></h2><Enter><Enter><++><Esc>2kli
autocmd FileType html inoremap ;h3 <h3></h3><Enter><Enter><++><Esc>2kli
autocmd FileType html inoremap ;ul <ul><Enter><Enter></ul><Enter><++><Esc>2kA
autocmd FileType html inoremap ;ol <ol><Enter><Enter></ol><Enter><++><Esc>2kA
autocmd FileType html inoremap ;li <li></li><Enter><++><Esc>k$bba
autocmd FileType html inoremap ;dc <div class=""><Enter><++><Enter></div><Esc>2k$hi
autocmd FileType html inoremap ;di <div id=""><Enter><++><Enter></div><Esc>2k$hi

""""""""""LATEX SHORTCUTS""""""""""
autocmd FileType tex inoremap <Space><Space> <Esc>/<++><Enter>4xi
autocmd FileType tex inoremap ;c \cite{} <++><Esc>F}i
autocmd FileType tex inoremap ;i \textit{} <++><Esc>F}i
autocmd FileType tex inoremap ;b \textbf{} <++><Esc>F}i
autocmd FileType tex inoremap ;e \emph{} <++><Esc>F}i
autocmd FileType tex inoremap ;u \underline{} <++><Esc>F}i
autocmd FileType tex inoremap ;S \section{}<Enter><Enter><++><Esc>2k$i
autocmd FileType tex inoremap ;s \subsection{}<Enter><Enter><++><Esc>2k$i
