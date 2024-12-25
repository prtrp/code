`timescale 10ns/1ns

module tb_exemple();
reg x0, x1, x2;
wire y;

circ c(.a(x0, .b(x1), .c(x2), .y(y));

initial begin
  $dumpfile("test.")
  $dumpvar;

  x0 = 0;
  x1 = 0;
  x2 = 0;
  #1;

  end
  endmodule
