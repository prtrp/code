module ha(a, b, sum, carry);
  input a, b;
  output sum, carry;

  and(carry, a, b);
  xor(sum, a, b);
endmodule

module fa(a, b, cin, sum, cout);
  input a, b, cin;
  output sum, cout;

  wire s1, c1, c2;

  ha ha1(.a(a), .b(b), .sum(s1), .carry(c1));
  ha ha2(.a(s1), .b(cin), .sum(sum), .carry(c2));
  or(cout, c1, c2);

endmodule
