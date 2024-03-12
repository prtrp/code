vim.g.mapleader = ","

vim.keymap.set('n', '<c-n>', ':NvimTreeFindFileToggle<CR>')
vim.keymap.set('n', '<c-s>', ':w<CR>')
vim.keymap.set('n', '<c-x>', ':wq<CR>')
vim.keymap.set('i', 'jk', '<Esc>')
vim.api.nvim_set_keymap('n', '<leader>h', ':nohlsearch<CR>', { silent = true })

