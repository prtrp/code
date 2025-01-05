return {
    "ellisonleao/gruvbox.nvim",
    name = "gruvbox",
    lazy = false,
    priority = 1000,
    config = function()
        require("gruvbox").setup({
            contrast = "soft", -- Imposta il contrasto "soft"
            palette = "light", -- Imposta la palette "light"
            overrides = { -- (opzionale) Personalizza ulteriormente i colori
            }
        })
    end
}

