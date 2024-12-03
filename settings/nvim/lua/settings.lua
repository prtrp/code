vim.cmd("set expandtab")
vim.cmd("set tabstop=2")
vim.cmd("set softtabstop=2")
vim.cmd("set shiftwidth=2")
vim.cmd("set relativenumber")
vim.cmd("set clipboard=unnamedplus")

vim.g.mapleader = " "

vim.api.nvim_create_autocmd("FileType", {
  pattern = "python",
  callback = function()
    vim.cmd("set expandtab")
    vim.cmd("set tabstop=2")
    vim.cmd("set softtabstop=2")
    vim.cmd("set shiftwidth=2")
  end,
})

