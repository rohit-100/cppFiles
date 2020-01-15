set nocompatible              " be iMproved, required
filetype off                  " required
set autoindent
set tabstop=4
set number
set shiftwidth=4
set expandtab
set softtabstop=4
inoremap {<CR> {<CR>}<C-o>O
" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
"Plugin 'tpope/vim-fugitive'
"Plugin 'Valloric/YouCompleteMe'
Plugin 'jiangmiao/auto-pairs'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
" Git plugin not hosted on GitHub
"Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
"Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': 'newL9'}

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
 let g:ycm_global_ycm_extra_conf = '~/.vim/bundle/YouCompleteMe/third_party/ycmd/.ycm_extra_conf.py'
 "let g:ycm_use_clangd = 0
 let g:ycm_show_diagnostics_ui = 0
 let g:ycm_min_num_of_chars_for_completion = 5




abbr fori for(int i=0;i< <esc>i


set wildmenu
set path+=**


"   :ls commmand list the local buffers
"   :b  lets you autocomplete any local buffer
"   :find filename   to open any file


"c++ abrreviations


abbr forn for(int i=0;i<n;i++){<CR>}<esc>k3li
abbr form for(int j=0;j<m;j++){<CR>}<esc>k3li
abbr test int t;<CR>cin>>t;<CR>while(t--){<CR>}<esc>k3li
abbr cpp #include<bits/stdc++.h><CR>using namespace std;<CR><CR>int main(){<CR><CR>}<esc>k3li
abbr nm int n,m;<CR>cin>>n>>m;<CR>
abbr vectn vector<int>arr;{int x;cin>>x;arr.push_back(x);}<CR>

abbr power int power(int a,int b,int mod=1e9+7){<CR> int res = 1;<CR> while(b){<CR> if(b&1)res = 1ll*res*a%mod;<CR> a=1ll*a*a%mod;<CR>b>>=1;}<CR> return res;}




