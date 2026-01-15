
 void FillRom(byte * buffer) { 
    buffer[0] = 0xEA;  //NOP
    buffer[1] = 0xEA;
    buffer[2] = 0xEA;
    buffer[3] = 0xA9;  // LDA #$99  load 0x99 into A
    buffer[4] = 0x99;
    buffer[5] = 0xEA;  // The jump command below will come back to this address!
    buffer[6] = 0xEA;
    buffer[7] = 0x85;  // STA $55   store A to memory address 0x55
    buffer[8] = 0x55;
    buffer[9] = 0xA6;  // LDX $55    load memory contents 0x55 into X
    buffer[10] = 0x55;
    buffer[11] = 0xCA;  // DEX  decrement X
    buffer[12] = 0x8A;  // TXS  Transfer Index X to Accumulator
    buffer[13] = 0x48;  // PHA  push A onto stack
    buffer[14] = 0xEA;
    buffer[15] = 0x4C;  //JMP 0x8005
    buffer[16] = 0x05;
    buffer[17] = 0x80;
 }