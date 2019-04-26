module alu(
           input [3:0] A,B,                  
           input [3:0] Sel,
           output [4:0] Out, 
           
    );
    reg [4:0] temp;
    assign Out = temp; 
    always @(*)
    begin
        case(Sel)
        4'b0000: // Addition
           temp= {1'b0,A} +{1'b0,B};
           
        4'b0001: // Subtraction
           temp = {1'b0,A} -{1'b0,B};
      
        4'b0010: // Multiplication
           temp= {1'b0,A} *{1'b0,B};
           
        4'b0011: // Division
           temp = {1'b0,A}/{1'b0,B};
         
        4'b0100: // Logical shift left
           temp  = {1'b0,A}<<1;
           
         4'b0101: // Logical shift right
           temp  = {1'b0,A}>>1;
  
         4'b0110: // Rotate left
           temp  = {0,A[2:0],A[3]};
         4'b0111: // Rotate right
           temp = {0,A[0],A[3:1]};
          4'b1000: //  Logical and 
           temp  = {1'b0,A} &{1'b0,B};

          4'b1001: //  Logical or
           temp = {1'b0,A} |{1'b0,B};
           
          4'b1010: //  Logical xor 
           temp = {1'b0,A} ^{1'b0,B};
           
          4'b1011: //  Logical nor
           temp = ~({1'b0,A} |{1'b0,B});

          4'b1100: // Logical nand 
           temp = ~({1'b0,A} &{1'b0,B});
          4'b1101: // Logical xnor
           temp = ~({1'b0,A} ^{1'b0,B});
          
          4'b1110: // Greater comparison
          temp  = (A>B)?5'd1:5'd0 ;
           
          4'b1111: // Equal comparison   
            temp = (A==B)?5'd1:5'd0 ;
            
          default:temp  = {1'b0,A} + {1'b0,B};
        endcase
    end

endmodule
