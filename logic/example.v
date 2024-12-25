module cirtc(a, b, c, y);

  input a, b, c;
  output y;

  wire w1, w2;

  not(w1, b);
  and(w2, a, w1);
  xor(y, w2, c);

endmodule
