module Demultiplexer(in,s0,s1,s2,seg);
	input in,s0,s1,s2;
	reg d0,d1,d2,d3,d4,d5,d6,d7;
	assign d0=(in & ~s2 & ~s1 &~s0),
			d1=(in & ~s2 & ~s1 &s0),
			d2=(in & ~s2 & s1 &~s0),
			d3=(in & ~s2 & s1 &s0),
			d4=(in & s2 & ~s1 &~s0),
			d5=(in & s2 & ~s1 &s0),
			d6=(in & s2 & s1 &~s0),
			d7=(in & s2 & s1 &s0);
	output [6:0] seg;
	reg [6:0] seg;
	integer b;
	initial begin
		if (d0==1)begin
			b=0;
		end else if (d1==1)begin
			b=1;
		end else if (d2==1)begin
			b=2;
		end else if (d3==1)begin
			b=3;
		end else if (d4==1)begin
			b=4;
		end else if (d5==1)begin
			b=5;
		end else if (d6==1)begin
			b=6;
		end else if (d7==1)begin
			b=7;
		end
		
	end
	always @(b)
    begin
        case (b) //case statement
            0 : seg = 7'b0000001;
            1 : seg = 7'b1001111;
            2 : seg = 7'b0010010;
            3 : seg = 7'b0000110;
            4 : seg = 7'b1001100;
            5 : seg = 7'b0100100;
            6 : seg = 7'b0100000;
            7 : seg = 7'b0001111;
            //switch off 7 segment character when the bcd digit is not a decimal number.
            default : seg = 7'b1111111; 
        endcase
    end
endmodule
//test

