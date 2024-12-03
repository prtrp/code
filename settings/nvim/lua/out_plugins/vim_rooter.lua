return {
  "airblade/vim-rooter",
  config = function()
    -- Imposta rooter per cambiare la directory alla radice del progetto
    vim.g.rooter_manual_only = 0 -- Cambia automaticamente
    vim.g.rooter_patterns = { ".git", "Makefile", "package.json" } -- Identifica la radice del progetto
  end,
}

