vim.cmd("set expandtab")
vim.cmd("set tabstop=4")
vim.cmd("set softtabstop=4")
vim.cmd("set shiftwidth=4")
vim.cmd("set relativenumber")
vim.cmd("set nonumber")
mapleader = " "

vim.opt.swapfile = false

-- Navigate vim panes better
vim.keymap.set('n', '<c-k>', ':wincmd k<CR>')
vim.keymap.set('n', '<c-j>', ':wincmd j<CR>')
vim.keymap.set('n', '<c-h>', ':wincmd h<CR>')
vim.keymap.set('n', '<c-l>', ':wincmd l<CR>')

vim.keymap.set('n', '<leader>h', ':nohlsearch<CR>')
vim.wo.number = true


vim.api.nvim_create_autocmd("FileType", {
  pattern = "python",
  callback = function()
    vim.cmd("set nonumber")
    vim.cmd("set expandtab")
    vim.cmd("set tabstop=4")
    vim.cmd("set softtabstop=4")
    vim.cmd("set shiftwidth=4")
  end,
})
