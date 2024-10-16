vim.cmd("set expandtab")
vim.cmd("set tabstop=2")
vim.cmd("set softtabstop=2")
vim.cmd("set shiftwidth=2")
vim.cmd("set relativenumber")

vim.g.mapleader = " "

-- folding
vim.cmd("set foldenable")
vim.cmd("set foldmethod=indent")
vim.cmd("set foldlevel=3")

-- for rust
vim.api.nvim_create_autocmd("FileType", {
  pattern = "rust",
  command = "setlocal tabstop=2 shiftwidth=2 softtabstop=2 expandtab"
})

vim.api.nvim_create_autocmd("FileType", {
  pattern = "python",
  command = "setlocal tabstop=2 shiftwidth=2 softtabstop=2 expandtab"
})
