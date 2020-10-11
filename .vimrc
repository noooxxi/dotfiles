" Runs Pathogen
execute pathogen#infect()
syntax on
filetype plugin indent on

" Runs Lightline
set laststatus=2
set noshowmode
let g:lightline = { 'colorscheme': 'buddha', }

" Compiles on :w
autocmd BufWritePost *.tex silent! execute "!pdflatex %" | redraw!
"autocmd BufWritePost *.tex silent! execute "!pdflatex % >/dev/null 2>&1" | redraw!

" Reloads bibliography on C+O
autocmd FileType tex map <C-o> :!biber $(echo '%:r') >/dev/null 2>&1<CR><CR>

" Removes logs on :q
autocmd VimLeave *.tex !texclear %

" Opens pdf on Ctrl+P
autocmd FileType tex map <C-p> :!zathura $(echo '%:r.pdf') &<CR><CR>

" Opens bibliography on Ctrl+B
map <C-b> :!kitty -e vim ~/dox/school/bibliography.bib &<CR><CR>

" Sets the beloved relative number + number combo
set relativenumber
set number

" Disables automatic comment insertion
autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o

" Fixes word wrapping
:set formatoptions=l
:set lbr

" Miscellaneous hotkeys
map <C-n> :NERDTreeToggle<CR> 				" Toggle nerdtree
map <C-j> })zz						" Go one paragraph up
map <C-k> {(0zz 					" Go one paragraph down
map <F12> :setlocal spell! spelllang=en_us<CR>		" Toggle English spell check
map <F11> :setlocal spell! spelllang=sv<CR>		" Toggle Swedish spell check
map <F10> :setlocal spell! spelllang=es_es<CR>		" Toggle Spanish spell check
map cs :ThesaurusQueryReplaceCurrentWord<CR>		" Show synonyms of current word

" Split navigation
map <C-h> <C-w>h					" Go to left pane
map <C-j> <C-w>j					" Go to bottom pane
map <C-k> <C-w>k					" Go to top pane
map <C-l> <C-w>l					" Go to right pane

" HTML
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

" LaTeX
autocmd FileType tex inoremap <Space><Space> <Esc>/<++><Enter>4xi
autocmd FileType tex inoremap ;c \cite{} <++><Esc>F}i
autocmd FileType tex inoremap ;i \textit{} <++><Esc>F}i
autocmd FileType tex inoremap ;b \textbf{} <++><Esc>F}i
autocmd FileType tex inoremap ;e \emph{} <++><Esc>F}i
autocmd FileType tex inoremap ;u \underline{} <++><Esc>F}i
autocmd FileType tex inoremap ;S \section{}<Enter><Enter><++><Esc>2k$i
autocmd FileType tex inoremap ;s \subsection{}<Enter><Enter><++><Esc>2k$i
"autocmd FileType tex inoremap ;

set encoding=utf-8
