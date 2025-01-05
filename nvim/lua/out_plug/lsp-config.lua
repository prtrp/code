return {
    -- Plugin per gestire l'installazione dei server
    {
        "williamboman/mason.nvim",
        config = function()
            require("mason").setup()
        end
    },
    -- Plugin per collegare Mason a lspconfig
    {
        "williamboman/mason-lspconfig.nvim",
        config = function()
            require("mason-lspconfig").setup({
                ensure_installed = { "lua_ls", "ts_ls", "pyright", "clangd" }
            })
        end
    },
    -- Plugin per configurare i Language Servers
    {
        "neovim/nvim-lspconfig",
        config = function()
            local lspconfig = require("lspconfig")

            -- Configura i vari server
            lspconfig.lua_ls.setup({})
            lspconfig.ts_ls.setup({})
            lspconfig.pyright.setup({})
            lspconfig.clangd.setup({})

            -- Scorciatoie da tastiera per LSP
            vim.keymap.set("n", "K", vim.lsp.buf.hover, {})
            vim.keymap.set("n", "gd", vim.lsp.buf.definition, {})
            vim.keymap.set("n", "<leader>ca", vim.lsp.buf.code_action, {})
            vim.cmd ("LspStop")
        end
    }
}

