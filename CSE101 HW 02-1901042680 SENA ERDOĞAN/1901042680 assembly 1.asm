load R1, 0
load R2, 12
load R3, 1
load R4, 255
xor RF, R2,R4
addi RF, RF,R3
load R5, 13
xor RF, R5,R4
addi RF, RF,R3
halt
