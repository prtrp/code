return {
  "nvim-treesitter/nvim-treesitter",
  build = ":TSUpdate",
  config = function ()
    local config = require("nvim-treesitter.configs")
    config.setup({
      ensure_installed = {"c", "lua", "html", "css", "php", "javascript", "java", "rust", "latex", "asm"},
      highlight = {enable = true},
      indent = {enable = true},
    })
  end
}
