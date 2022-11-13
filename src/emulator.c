#include <stdlib.h>
#include <stdio.h>

int Disassemble8080Op(unsigned char* instr_buff, int pc, int* cntr) {
    unsigned char *code = &instr_buff[pc];    
    int instr_size = 1;
    printf ("%04x ", pc);

    switch (*code) {
        case 0x00: printf("NOP"); break;
        case 0x01: printf("LXI\tB,%02x %02x", code[2], code[1]); instr_size = 3; break;
        case 0x02: printf("STAX\tB"); break;
        case 0x03: printf("INX\tB"); break;
        case 0x04: printf("INR\tB"); break;
        case 0x05: printf("DCR\tB"); break;
        case 0x06: printf("MVI\tB,#%02x", code[1]); instr_size = 2; break;
        case 0x07: printf("RLC"); break;
        case 0x08: printf("NOP"); break;
        case 0x09: printf("DAD\tB"); break;
        case 0x0a: printf("LDAX\tB"); break;
        case 0x0b: printf("DCX\tB"); break;
        case 0x0c: printf("INR\tC"); break;
        case 0x0d: printf("DCR\tC"); break;
        case 0x0e: printf("MVI\tC,#%02x", code[1]); instr_size = 2; break;
        case 0x0f: printf("RRC"); break;

        case 0x10: printf("NOP"); break;
        case 0x1e: printf("MVI\tE,#%02x", code[1]); instr_size = 2; break;

        case 0x21: printf("LXI\tH,#$%02x%02x", code[2], code[1]); instr_size = 3; break;
        case 0x22: printf("SHLD\t%02x%02x", code[2], code[1]); instr_size = 3; break;
        case 0x27: printf("DAA"); break;
        case 0x2e: printf("MVI\tL,#%02x", code[1]); instr_size = 2; break;

        case 0x32: printf("STA\t%02x%02x", code[2], code[1]); instr_size = 3; break;
        case 0x35: printf("DCR\tM"); break;
        case 0x3a: printf("LDA\t$%02x%02x", code[2], code[1]); instr_size = 3; break;
        case 0x3e: printf("MVI\tA,#%02x", code[1]); instr_size = 2; break;

        case 0x70: printf("MOV\tM,B"); break;
		case 0x71: printf("MOV\tM,C"); break;
		case 0x72: printf("MOV\tM,D"); break;
		case 0x73: printf("MOV\tM.E"); break;
		case 0x74: printf("MOV\tM,H"); break;
		case 0x75: printf("MOV\tM,L"); break;
		case 0x76: printf("HLT");      break;
		case 0x77: printf("MOV\tM,A"); break;
		case 0x78: printf("MOV\tA,B"); break;
		case 0x79: printf("MOV\tA,C"); break;
		case 0x7a: printf("MOV\tA,D"); break;
		case 0x7b: printf("MOV\tA,E"); break;
		case 0x7c: printf("MOV\tA,H"); break;
		case 0x7d: printf("MOV\tA,L"); break;
		case 0x7e: printf("MOV\tA,M"); break;
		case 0x7f: printf("MOV\tA,A"); break;

        case 0x80: printf("ADD\tB"); break;
		case 0x81: printf("ADD\tC"); break;
		case 0x82: printf("ADD\tD"); break;
		case 0x83: printf("ADD\tE"); break;
		case 0x84: printf("ADD\tH"); break;
		case 0x85: printf("ADD\tL"); break;
		case 0x86: printf("ADD\tM"); break;
		case 0x87: printf("ADD\tA"); break;
		case 0x88: printf("ADC\tB"); break;
		case 0x89: printf("ADC\tC"); break;
		case 0x8a: printf("ADC\tD"); break;
		case 0x8b: printf("ADC\tE"); break;
		case 0x8c: printf("ADC\tH"); break;
		case 0x8d: printf("ADC\tL"); break;
		case 0x8e: printf("ADC\tM"); break;
		case 0x8f: printf("ADC\tA"); break;

		case 0x90: printf("SUB\tB"); break;
		case 0x91: printf("SUB\tC"); break;
		case 0x92: printf("SUB\tD"); break;
		case 0x93: printf("SUB\tE"); break;
		case 0x94: printf("SUB\tH"); break;
		case 0x95: printf("SUB\tL"); break;
		case 0x96: printf("SUB\tM"); break;
		case 0x97: printf("SUB\tA"); break;
		case 0x98: printf("SBB\tB"); break;
		case 0x99: printf("SBB\tC"); break;
		case 0x9a: printf("SBB\tD"); break;
		case 0x9b: printf("SBB\tE"); break;
		case 0x9c: printf("SBB\tH"); break;
		case 0x9d: printf("SBB\tL"); break;
		case 0x9e: printf("SBB\tM"); break;
		case 0x9f: printf("SBB\tA"); break;

		case 0xa0: printf("ANA\tB"); break;
		case 0xa1: printf("ANA\tC"); break;
		case 0xa2: printf("ANA\tD"); break;
		case 0xa3: printf("ANA\tE"); break;
		case 0xa4: printf("ANA\tH"); break;
		case 0xa5: printf("ANA\tL"); break;
		case 0xa6: printf("ANA\tM"); break;
		case 0xa7: printf("ANA\tA"); break;
		case 0xa8: printf("XRA\tB"); break;
		case 0xa9: printf("XRA\tC"); break;
		case 0xaa: printf("XRA\tD"); break;
		case 0xab: printf("XRA\tE"); break;
		case 0xac: printf("XRA\tH"); break;
		case 0xad: printf("XRA\tL"); break;
		case 0xae: printf("XRA\tM"); break;
		case 0xaf: printf("XRA\tA"); break;

		case 0xb0: printf("ORA\tB"); break;
		case 0xb1: printf("ORA\tC"); break;
		case 0xb2: printf("ORA\tD"); break;
		case 0xb3: printf("ORA\tE"); break;
		case 0xb4: printf("ORA\tH"); break;
		case 0xb5: printf("ORA\tL"); break;
		case 0xb6: printf("ORA\tM"); break;
		case 0xb7: printf("ORA\tA"); break;
		case 0xb8: printf("CMP\tB"); break;
		case 0xb9: printf("CMP\tC"); break;
		case 0xba: printf("CMP\tD"); break;
		case 0xbb: printf("CMP\tE"); break;
		case 0xbc: printf("CMP\tH"); break;
		case 0xbd: printf("CMP\tL"); break;
		case 0xbe: printf("CMP\tM"); break;
		case 0xbf: printf("CMP\tA"); break;

        case 0xc1: printf("POP\tB"); break;
        case 0xc2: printf("JNZ\t$%02x%02x", code[2], code[1]); instr_size = 3; break;
        case 0xc3: printf("JMP\t$%02x%02x", code[2], code[1]); instr_size = 3; break;
        case 0xc4: printf("CNZ\t$%02x%02x", code[2], code[1]); instr_size = 3; break;
        case 0xc5: printf("PUSH\tB"); break;
        case 0xc6: printf("ADI\t#$%02x", code[1]); instr_size = 2; break;
        case 0xca: printf("JZ \t$%02x%02x", code[2], code[1]); instr_size = 3; break;
        case 0xcb: printf("NOP"); break;
        case 0xcc: printf("CZ \t$%02x%02x", code[2], code[1]); instr_size = 3; break;
        case 0xcd: printf("CALL\t$%02x%02x", code[2], code[1]); instr_size = 3; break;

        case 0xd1: printf("POP\tD"); break;
        case 0xd5: printf("PUSH\tD"); break;
        case 0xda: printf("JC \t$%02x%02x", code[2], code[1]); instr_size = 3; break;
        case 0xdb: printf("IN \t%02x", code[1]); instr_size = 2; break;

        case 0xe1: printf("POP\tH"); break;
        case 0xe5: printf("PUSH\tH"); break;

        case 0xf1: printf("POP\tPSW"); break;
        case 0xf5: printf("PUSH\tPSW"); break;
        case 0xfb: printf("EI"); break;
        case 0xfe: printf("CPI\t#$%02x", code[1]); instr_size = 2; break;

        default:printf("Not implemented"); *cntr = *cntr + 1; break;
    }

    putchar('\n');
    return instr_size;
}

int main(int argc, char const *argv[]) {
    FILE *f= fopen(argv[1], "rb");    
    if (f == NULL) {
        printf("error: Couldn't open %s\n", argv[1]);    
        exit(1);    
    }

    fseek(f, 0L, SEEK_END);    
    int fsize = ftell(f);    
    fseek(f, 0L, SEEK_SET);    

    unsigned char *buffer=malloc(fsize);    

    fread(buffer, fsize, 1, f);    
    fclose(f);    

    int pc = 0;
    int cntr = 0;

    while (pc < fsize) {    
        pc += Disassemble8080Op(buffer, pc, &cntr);
    }
    printf("Not implemented: %d\n", cntr);
    return 0;
}
