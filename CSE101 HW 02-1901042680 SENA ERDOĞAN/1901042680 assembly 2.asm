load R1, 0
load R2, 12
load R3, 1
load R4, 255
xor RF, R2,R4
addi RF, RF,R3
load R5, 13
xor RF, R5,R4
addi RF, RF,R3
load R6, 14
xor RF, RF,R6
addi RF, RF,R3
load R7, 15
xor RF, RF,R7
addi RF, RF,R3
halt
