return {
  'nvim-telescope/telescope.nvim',
  tag = '0.1.8',
  dependencies = {
    'nvim-lua/plenary.nvim',
    'nvim-telescope/telescope-file-browser.nvim', -- Estensione del file browser
  },
  config = function()
    local telescope = require("telescope")
    local builtin = require("telescope.builtin")

    -- Configurazione di base di Telescope
    telescope.setup({
      extensions = {
        file_browser = {
          -- Configurazioni opzionali per il file browser
          hijack_netrw = true, -- Usa il file browser al posto di netrw
        },
      },
    })

    -- Carica l'estensione del file browser
    telescope.load_extension("file_browser")

    -- Mappature dei comandi Telescope
    vim.keymap.set('n', '<leader>p', builtin.find_files, {})
    vim.keymap.set('n', '<leader>fg', builtin.live_grep, {})
    vim.keymap.set('n', '<leader>fb', telescope.extensions.file_browser.file_browser, { desc = "File Browser" })
  end
}

