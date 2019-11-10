// ==============================================================
// File generated on Thu May 23 21:23:41 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
`timescale 1ns/1ps
module nodeDetector_CRTL_BUS_s_axi
#(parameter
    C_S_AXI_ADDR_WIDTH = 7,
    C_S_AXI_DATA_WIDTH = 32
)(
    // axi4 lite slave signals
    input  wire                          ACLK,
    input  wire                          ARESET,
    input  wire                          ACLK_EN,
    input  wire [C_S_AXI_ADDR_WIDTH-1:0] AWADDR,
    input  wire                          AWVALID,
    output wire                          AWREADY,
    input  wire [C_S_AXI_DATA_WIDTH-1:0] WDATA,
    input  wire [C_S_AXI_DATA_WIDTH/8-1:0] WSTRB,
    input  wire                          WVALID,
    output wire                          WREADY,
    output wire [1:0]                    BRESP,
    output wire                          BVALID,
    input  wire                          BREADY,
    input  wire [C_S_AXI_ADDR_WIDTH-1:0] ARADDR,
    input  wire                          ARVALID,
    output wire                          ARREADY,
    output wire [C_S_AXI_DATA_WIDTH-1:0] RDATA,
    output wire [1:0]                    RRESP,
    output wire                          RVALID,
    input  wire                          RREADY,
    // user signals
    output wire [7:0]                    enable_V,
    output wire [15:0]                   pos_0_V,
    output wire [15:0]                   pos_1_V,
    output wire [15:0]                   pos_2_V,
    output wire [15:0]                   pos_3_V,
    output wire [15:0]                   pos_4_V,
    output wire [15:0]                   pos_5_V,
    output wire [15:0]                   pos_6_V,
    output wire [15:0]                   horizontalPos_V
);
//------------------------Address Info-------------------
// 0x00 : reserved
// 0x04 : reserved
// 0x08 : reserved
// 0x0c : reserved
// 0x10 : Data signal of enable_V
//        bit 7~0 - enable_V[7:0] (Read/Write)
//        others  - reserved
// 0x14 : reserved
// 0x18 : Data signal of pos_0_V
//        bit 15~0 - pos_0_V[15:0] (Read/Write)
//        others   - reserved
// 0x1c : reserved
// 0x20 : Data signal of pos_1_V
//        bit 15~0 - pos_1_V[15:0] (Read/Write)
//        others   - reserved
// 0x24 : reserved
// 0x28 : Data signal of pos_2_V
//        bit 15~0 - pos_2_V[15:0] (Read/Write)
//        others   - reserved
// 0x2c : reserved
// 0x30 : Data signal of pos_3_V
//        bit 15~0 - pos_3_V[15:0] (Read/Write)
//        others   - reserved
// 0x34 : reserved
// 0x38 : Data signal of pos_4_V
//        bit 15~0 - pos_4_V[15:0] (Read/Write)
//        others   - reserved
// 0x3c : reserved
// 0x40 : Data signal of pos_5_V
//        bit 15~0 - pos_5_V[15:0] (Read/Write)
//        others   - reserved
// 0x44 : reserved
// 0x48 : Data signal of pos_6_V
//        bit 15~0 - pos_6_V[15:0] (Read/Write)
//        others   - reserved
// 0x4c : reserved
// 0x50 : Data signal of horizontalPos_V
//        bit 15~0 - horizontalPos_V[15:0] (Read/Write)
//        others   - reserved
// 0x54 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

//------------------------Parameter----------------------
localparam
    ADDR_ENABLE_V_DATA_0        = 7'h10,
    ADDR_ENABLE_V_CTRL          = 7'h14,
    ADDR_POS_0_V_DATA_0         = 7'h18,
    ADDR_POS_0_V_CTRL           = 7'h1c,
    ADDR_POS_1_V_DATA_0         = 7'h20,
    ADDR_POS_1_V_CTRL           = 7'h24,
    ADDR_POS_2_V_DATA_0         = 7'h28,
    ADDR_POS_2_V_CTRL           = 7'h2c,
    ADDR_POS_3_V_DATA_0         = 7'h30,
    ADDR_POS_3_V_CTRL           = 7'h34,
    ADDR_POS_4_V_DATA_0         = 7'h38,
    ADDR_POS_4_V_CTRL           = 7'h3c,
    ADDR_POS_5_V_DATA_0         = 7'h40,
    ADDR_POS_5_V_CTRL           = 7'h44,
    ADDR_POS_6_V_DATA_0         = 7'h48,
    ADDR_POS_6_V_CTRL           = 7'h4c,
    ADDR_HORIZONTALPOS_V_DATA_0 = 7'h50,
    ADDR_HORIZONTALPOS_V_CTRL   = 7'h54,
    WRIDLE                      = 2'd0,
    WRDATA                      = 2'd1,
    WRRESP                      = 2'd2,
    WRRESET                     = 2'd3,
    RDIDLE                      = 2'd0,
    RDDATA                      = 2'd1,
    RDRESET                     = 2'd2,
    ADDR_BITS         = 7;

//------------------------Local signal-------------------
    reg  [1:0]                    wstate = WRRESET;
    reg  [1:0]                    wnext;
    reg  [ADDR_BITS-1:0]          waddr;
    wire [31:0]                   wmask;
    wire                          aw_hs;
    wire                          w_hs;
    reg  [1:0]                    rstate = RDRESET;
    reg  [1:0]                    rnext;
    reg  [31:0]                   rdata;
    wire                          ar_hs;
    wire [ADDR_BITS-1:0]          raddr;
    // internal registers
    reg  [7:0]                    int_enable_V = 'b0;
    reg  [15:0]                   int_pos_0_V = 'b0;
    reg  [15:0]                   int_pos_1_V = 'b0;
    reg  [15:0]                   int_pos_2_V = 'b0;
    reg  [15:0]                   int_pos_3_V = 'b0;
    reg  [15:0]                   int_pos_4_V = 'b0;
    reg  [15:0]                   int_pos_5_V = 'b0;
    reg  [15:0]                   int_pos_6_V = 'b0;
    reg  [15:0]                   int_horizontalPos_V = 'b0;

//------------------------Instantiation------------------

//------------------------AXI write fsm------------------
assign AWREADY = (wstate == WRIDLE);
assign WREADY  = (wstate == WRDATA);
assign BRESP   = 2'b00;  // OKAY
assign BVALID  = (wstate == WRRESP);
assign wmask   = { {8{WSTRB[3]}}, {8{WSTRB[2]}}, {8{WSTRB[1]}}, {8{WSTRB[0]}} };
assign aw_hs   = AWVALID & AWREADY;
assign w_hs    = WVALID & WREADY;

// wstate
always @(posedge ACLK) begin
    if (ARESET)
        wstate <= WRRESET;
    else if (ACLK_EN)
        wstate <= wnext;
end

// wnext
always @(*) begin
    case (wstate)
        WRIDLE:
            if (AWVALID)
                wnext = WRDATA;
            else
                wnext = WRIDLE;
        WRDATA:
            if (WVALID)
                wnext = WRRESP;
            else
                wnext = WRDATA;
        WRRESP:
            if (BREADY)
                wnext = WRIDLE;
            else
                wnext = WRRESP;
        default:
            wnext = WRIDLE;
    endcase
end

// waddr
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (aw_hs)
            waddr <= AWADDR[ADDR_BITS-1:0];
    end
end

//------------------------AXI read fsm-------------------
assign ARREADY = (rstate == RDIDLE);
assign RDATA   = rdata;
assign RRESP   = 2'b00;  // OKAY
assign RVALID  = (rstate == RDDATA);
assign ar_hs   = ARVALID & ARREADY;
assign raddr   = ARADDR[ADDR_BITS-1:0];

// rstate
always @(posedge ACLK) begin
    if (ARESET)
        rstate <= RDRESET;
    else if (ACLK_EN)
        rstate <= rnext;
end

// rnext
always @(*) begin
    case (rstate)
        RDIDLE:
            if (ARVALID)
                rnext = RDDATA;
            else
                rnext = RDIDLE;
        RDDATA:
            if (RREADY & RVALID)
                rnext = RDIDLE;
            else
                rnext = RDDATA;
        default:
            rnext = RDIDLE;
    endcase
end

// rdata
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (ar_hs) begin
            rdata <= 1'b0;
            case (raddr)
                ADDR_ENABLE_V_DATA_0: begin
                    rdata <= int_enable_V[7:0];
                end
                ADDR_POS_0_V_DATA_0: begin
                    rdata <= int_pos_0_V[15:0];
                end
                ADDR_POS_1_V_DATA_0: begin
                    rdata <= int_pos_1_V[15:0];
                end
                ADDR_POS_2_V_DATA_0: begin
                    rdata <= int_pos_2_V[15:0];
                end
                ADDR_POS_3_V_DATA_0: begin
                    rdata <= int_pos_3_V[15:0];
                end
                ADDR_POS_4_V_DATA_0: begin
                    rdata <= int_pos_4_V[15:0];
                end
                ADDR_POS_5_V_DATA_0: begin
                    rdata <= int_pos_5_V[15:0];
                end
                ADDR_POS_6_V_DATA_0: begin
                    rdata <= int_pos_6_V[15:0];
                end
                ADDR_HORIZONTALPOS_V_DATA_0: begin
                    rdata <= int_horizontalPos_V[15:0];
                end
            endcase
        end
    end
end


//------------------------Register logic-----------------
assign enable_V        = int_enable_V;
assign pos_0_V         = int_pos_0_V;
assign pos_1_V         = int_pos_1_V;
assign pos_2_V         = int_pos_2_V;
assign pos_3_V         = int_pos_3_V;
assign pos_4_V         = int_pos_4_V;
assign pos_5_V         = int_pos_5_V;
assign pos_6_V         = int_pos_6_V;
assign horizontalPos_V = int_horizontalPos_V;
// int_enable_V[7:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_enable_V[7:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_ENABLE_V_DATA_0)
            int_enable_V[7:0] <= (WDATA[31:0] & wmask) | (int_enable_V[7:0] & ~wmask);
    end
end

// int_pos_0_V[15:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_pos_0_V[15:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_POS_0_V_DATA_0)
            int_pos_0_V[15:0] <= (WDATA[31:0] & wmask) | (int_pos_0_V[15:0] & ~wmask);
    end
end

// int_pos_1_V[15:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_pos_1_V[15:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_POS_1_V_DATA_0)
            int_pos_1_V[15:0] <= (WDATA[31:0] & wmask) | (int_pos_1_V[15:0] & ~wmask);
    end
end

// int_pos_2_V[15:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_pos_2_V[15:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_POS_2_V_DATA_0)
            int_pos_2_V[15:0] <= (WDATA[31:0] & wmask) | (int_pos_2_V[15:0] & ~wmask);
    end
end

// int_pos_3_V[15:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_pos_3_V[15:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_POS_3_V_DATA_0)
            int_pos_3_V[15:0] <= (WDATA[31:0] & wmask) | (int_pos_3_V[15:0] & ~wmask);
    end
end

// int_pos_4_V[15:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_pos_4_V[15:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_POS_4_V_DATA_0)
            int_pos_4_V[15:0] <= (WDATA[31:0] & wmask) | (int_pos_4_V[15:0] & ~wmask);
    end
end

// int_pos_5_V[15:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_pos_5_V[15:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_POS_5_V_DATA_0)
            int_pos_5_V[15:0] <= (WDATA[31:0] & wmask) | (int_pos_5_V[15:0] & ~wmask);
    end
end

// int_pos_6_V[15:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_pos_6_V[15:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_POS_6_V_DATA_0)
            int_pos_6_V[15:0] <= (WDATA[31:0] & wmask) | (int_pos_6_V[15:0] & ~wmask);
    end
end

// int_horizontalPos_V[15:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_horizontalPos_V[15:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_HORIZONTALPOS_V_DATA_0)
            int_horizontalPos_V[15:0] <= (WDATA[31:0] & wmask) | (int_horizontalPos_V[15:0] & ~wmask);
    end
end


//------------------------Memory logic-------------------

endmodule