let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
let Db_ui_buffer_name_generator =  0 
let NvimTreeSetup =  1 
let NvimTreeRequired =  1 
let Db_ui_table_name_sorter =  0 
silent only
silent tabonly
cd ~/Projects/qmk/vial-qmk
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +1 Session.vim
badd +780 keyboards/crkbd/keymaps/jufralice/keymap.c
argglobal
%argdel
$argadd keyboards/crkbd/keymaps/jufralice/keymap.c
edit keyboards/crkbd/keymaps/jufralice/keymap.c
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
wincmd =
argglobal
balt Session.vim
setlocal fdm=indent
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=1000
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 1 - ((0 * winheight(0) + 36) / 72)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("keyboards/crkbd/keymaps/jufralice/keymap.c", ":p")) | buffer keyboards/crkbd/keymaps/jufralice/keymap.c | else | edit keyboards/crkbd/keymaps/jufralice/keymap.c | endif
if &buftype ==# 'terminal'
  silent file keyboards/crkbd/keymaps/jufralice/keymap.c
endif
balt Session.vim
setlocal fdm=indent
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=1000
setlocal fml=1
setlocal fdn=20
setlocal fen
680
normal! zo
689
normal! zo
731
normal! zo
832
normal! zo
832
normal! zo
832
normal! zo
832
normal! zo
832
normal! zo
832
normal! zo
832
normal! zo
832
normal! zo
832
normal! zo
832
normal! zo
832
normal! zo
832
normal! zo
832
normal! zo
868
normal! zo
868
normal! zo
868
normal! zo
868
normal! zo
868
normal! zo
868
normal! zo
868
normal! zo
868
normal! zo
868
normal! zo
953
normal! zo
954
normal! zo
let s:l = 806 - ((36 * winheight(0) + 36) / 72)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 806
normal! 07|
wincmd w
2wincmd w
wincmd =
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
