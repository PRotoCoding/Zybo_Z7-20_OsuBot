
set_property PACKAGE_PIN V20 [get_ports {hdmi_in_data_p[0]}]
set_property PACKAGE_PIN T20 [get_ports {hdmi_in_data_p[1]}]
set_property PACKAGE_PIN N20 [get_ports {hdmi_in_data_p[2]}]
#create_clock -period 8.334 -waveform {0.000 4.167} [get_ports hdmi_in_clk_p]
create_clock -period 12.000 -waveform {0.000 6.000} [get_ports hdmi_in_clk_p]
set_property PACKAGE_PIN U18 [get_ports hdmi_in_clk_p]

set_property IOSTANDARD LVCMOS33 [get_ports hdmi_in_ddc_scl_io]
set_property PACKAGE_PIN W18 [get_ports hdmi_in_ddc_scl_io]
set_property IOSTANDARD LVCMOS33 [get_ports hdmi_in_ddc_sda_io]
set_property PACKAGE_PIN Y19 [get_ports hdmi_in_ddc_sda_io]

set_property PACKAGE_PIN C20 [get_ports {hdmi_out_data_p[1]}]
set_property PACKAGE_PIN B19 [get_ports {hdmi_out_data_p[2]}]
set_property PACKAGE_PIN D19 [get_ports {hdmi_out_data_p[0]}]
set_property PACKAGE_PIN H16 [get_ports hdmi_out_clk_p]

set_property IOSTANDARD LVCMOS33 [get_ports {hdmi_rx_hpd[0]}]
set_property PACKAGE_PIN W19 [get_ports {hdmi_rx_hpd[0]}]

set_property IOSTANDARD LVCMOS33 [get_ports {hdmi_tx_hpd[0]}]
set_property PACKAGE_PIN E18 [get_ports {hdmi_tx_hpd[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports TTC0_WAVE0_OUT_0]
set_property PACKAGE_PIN T10 [get_ports TTC0_WAVE0_OUT_0]

##Switches
set_property -dict {PACKAGE_PIN G15 IOSTANDARD LVCMOS33} [get_ports {sw[0]}]
set_property -dict {PACKAGE_PIN P15 IOSTANDARD LVCMOS33} [get_ports {sw[1]}]
set_property -dict {PACKAGE_PIN W13 IOSTANDARD LVCMOS33} [get_ports {sw[2]}]
set_property -dict {PACKAGE_PIN T16 IOSTANDARD LVCMOS33} [get_ports {sw[3]}]

##LEDs
set_property -dict {PACKAGE_PIN M14 IOSTANDARD LVCMOS33} [get_ports {leds[0]}]
set_property -dict {PACKAGE_PIN M15 IOSTANDARD LVCMOS33} [get_ports {leds[1]}]
set_property -dict {PACKAGE_PIN G14 IOSTANDARD LVCMOS33} [get_ports {leds[2]}]
set_property -dict {PACKAGE_PIN D18 IOSTANDARD LVCMOS33} [get_ports {leds[3]}]


set_property DRIVE 12 [get_ports TTC0_WAVE0_OUT_0]
set_property SLEW FAST [get_ports TTC0_WAVE0_OUT_0]


set_property IOSTANDARD TMDS_33 [get_ports {hdmi_in_data_p[2]}]
set_property IOSTANDARD TMDS_33 [get_ports {hdmi_in_data_p[1]}]
set_property IOSTANDARD TMDS_33 [get_ports {hdmi_in_data_p[0]}]
set_property IOSTANDARD TMDS_33 [get_ports hdmi_in_clk_p]

set_property IOSTANDARD LVCMOS33 [get_ports TTC1_CLK0_IN_0]

set_property PACKAGE_PIN U12 [get_ports TTC1_CLK0_IN_0]

set_property BITSTREAM.GENERAL.COMPRESS TRUE [current_design]
