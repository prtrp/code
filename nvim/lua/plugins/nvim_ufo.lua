return {
  "kevinhwang91/nvim-ufo",
  dependencies = {
    "kevinhwang91/promise-async", -- Dipendenza necessaria per nvim-ufo
    "nvim-treesitter/nvim-treesitter", -- Dipendenza per il folding avanzato
  },
  config = function()
    -- Impostazioni di base per il folding
    vim.o.foldcolumn = '0' -- Mostra colonna del folding
    vim.o.foldlevel = 99   -- Mantieni espanso di default
    vim.o.foldlevelstart = 99
    vim.o.foldenable = true -- Abilita il folding

    -- Configurazione di nvim-ufo
    require('ufo').setup({
      provider_selector = function(_, filetype, _)
        return { "treesitter", "indent" } -- Usa Tree-sitter come provider principale
      end,
    })

    -- Tasti rapidi per controllare i fold
    vim.keymap.set('n', 'zR', require('ufo').openAllFolds, { desc = "Apri tutti i fold" })
    vim.keymap.set('n', 'zM', require('ufo').closeAllFolds, { desc = "Chiudi tutti i fold" })
    vim.keymap.set('n', 'zr', require('ufo').openFoldsExceptKinds, { desc = "Apri fold parzialmente" })
    vim.keymap.set('n', 'zm', require('ufo').closeFoldsWith, { desc = "Chiudi fold parzialmente" })
  end,
}
