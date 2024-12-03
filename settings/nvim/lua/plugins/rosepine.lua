return {
  "rose-pine/neovim",
  name = "rose-pine", 
  priority = 1000,
  config = function()
    -- Set the colorscheme
    require('rose-pine').setup({
      -- Add your desired settings here
      variant = 'main', -- Options: 'main', 'moon', 'dawn'
    })
    vim.cmd('colorscheme rose-pine') -- Apply the colorscheme
  end,
}

