return {
  "lukas-reineke/indent-blankline.nvim",
  version = "v3.*", -- Assicurati di utilizzare la versione 3
  config = function()
    require("ibl").setup({
      indent = {
        char = "│", -- Carattere per l'indentazione
      },
      scope = {
        enabled = false, -- Disabilita completamente l'evidenziazione del contesto
      },
    })
  end,
}

