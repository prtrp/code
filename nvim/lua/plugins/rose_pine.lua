return {
  "rose-pine/neovim",
  name = "rose-pine",
  lazy = false, -- Carica immediatamente
  priority = 1000, -- Carica prima di altri plugin
  config = function()
    require("rose-pine").setup({
      disable_background = true, -- Abilita il background trasparente
    })
  end
}

