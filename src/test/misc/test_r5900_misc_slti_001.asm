                TARGET      BIN, R5900
                INCLUDE     "..\..\tools\asm5900\ps2lib\macros.inc"
IF !CRUNCHED
                DB  7Fh,"ELF"   ; indentifier
                DB  1           ; File Class: 1=32bit, 2=64bit objects
                DB  1           ; Data Encoding: 1=ELFDATA2LSB, 2=ELFDATA2MSB
                DB  1           ; ELF header version (must be 1)
                DB  0,'n','S','X','2',0,0,0,0
                DH  2           ; ELF type: 0=NONE, 1=REL, 2=EXEC, 3=SHARED, 4=CORE
                DH  8           ; Processor: 8=MIPS
                DW  1           ; Version: 1=current
                DW  code.main   ; Entry point address
                DW  program     ; Start of program headers (offset from file start)
                DW  0           ; Start of section headers (offset from file start)
                DW  20924001h   ; Processor specific flags = 0x20924001 noreorder, mips
                DH  34h         ; ELF header size (0x34 = 52 bytes)
                DH  20h         ; Program headers entry size
                DH  1           ; Number of program headers
                DH  0           ; Section headers entry size
                DH  0           ; Number of section headers
                DH  0           ; Section header stringtable index
  program:      DW  1           ; Segment type: 1=Load the segment into memory, no. of bytes specified by 0x10 and 0x14
                DW  code._fofs  ; Offset from file start to program segment.
                DW  code._ofs   ; Virtual address of the segment
                DW  code._ofs   ; Physical address of the segment
                DW  code._fsize ; Number of bytes in the file image of the segment
                DW  ((code._size+15)>>4)<<4 ; Number of bytes in the memory image of the segment
                DW  0h          ; Flags for segment
               ;DW  0h          ; Alignment. The address of 0x08 and 0x0C must fit this alignment. 0=no alignment
code            SEGMENT     0x000000
                DW          0
ELSE
code            SEGMENT     0x400000
ENDIF

main:
;*********** YOUR CODE HERE **************

  slti t0, s0, -1  ; s0 == 00000000 00000000
  slti t1, s0,  0
  slti t2, s0,  1
  
  slti t3, s1,  0  ; s1 == 80000000 00000000
  slti t4, s1,  1  ; 80000000 00000000 - 00000000 00000001 上位wordで-側オーバーフローするケースは存在しない（immが16bitなので）
  slti t5, s1, -1
  
  slti t6, s2,  0  ; s2 == ffffffff ffffffff
  slti t7, s2, -1
  slti t8, s2, -2
  
  slti a0, s3,  0  ; s3 == 7fffffff ffffffff
  slti a1, s3, -1  ; 7fffffff ffffffff - ffffffff ffffffff 上位wordで+側オーバーフローが発生する
  slti a2, s3, 30000
  
  slti v0, s4,  1  ; 00000000 80000000 - 00000000 00000001 上位wordで-側オーバーフローが発生する
  slti v1, s5, -1  ; ffffffff 7fffffff - ffffffff ffffffff 上位wordで+側オーバーフローが発生する
  
  slti s2, s2,  0  ; srcとdstが同じケース

;*******************************************
  nop
code            ENDS
                END
