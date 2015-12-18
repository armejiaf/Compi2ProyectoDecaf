.data
newLine: .asciiz "\n"
x: .word 15
y: .word 0
x_es_mayor_a_10 : .asciiz "x_es_mayor_a_10 "
x_es_mayor_a_7_pero_menor_que_10 : .asciiz "x_es_mayor_a_7_pero_menor_que_10 "
x_es_menor_que_7: .asciiz "x_es_menor_que_7"
.text
test_if:
jal main
li $v0, 10
syscall
main:
#Prologo
addi $sp, $sp, -32 
sw $s0, 0($sp)
sw $s1, 4($sp)
sw $s2, 8($sp)
sw $s3, 12($sp)
sw $s4, 16($sp)
sw $s5, 20($sp)
sw $s6, 24($sp)
sw $s7, 28($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
#READ
la $t1, x
lw $t1, 0($t1)

li $v0, 5
syscall
move $t1, $v0
la $t0, x
sw $t1, 0($t0)
la $t2, x
lw $t2, 0($t2)

li $t3, 3

sub $t2, $t2, $t3
la $t3, x
sw $t2, 0($t3)
la $t2, x
lw $t2, 0($t2)

li $t3, 10

mult $t2, $t3
mflo $t2
li $t3, 5

div $t2, $t3
mflo $t2
la $t3, y
sw $t2, 0($t3)
#If
#GT
la $t2, x
lw $t2, 0($t2)
li $t3, 10

slt $t2, $t3, $t2
beq $t2, $zero, Label3
#Print
la $t2, x_es_mayor_a_10 

move $a0, $t2
li $v0, 4
syscall
la $a0, newLine
li $v0, 4
syscall
#Print
la $t3, x
lw $t3, 0($t3)

move $a0, $t3
li $v0, 1
syscall
la $a0, newLine
li $v0, 4
syscall


j Label2
Label3: 
#If
#GT
la $t4, x
lw $t4, 0($t4)
li $t5, 7

slt $t4, $t5, $t4
beq $t4, $zero, Label7
#Print
la $t4, x_es_mayor_a_7_pero_menor_que_10 

move $a0, $t4
li $v0, 4
syscall
la $a0, newLine
li $v0, 4
syscall
#Print
la $t5, x
lw $t5, 0($t5)

move $a0, $t5
li $v0, 1
syscall
la $a0, newLine
li $v0, 4
syscall


j Label6
Label7: 
#Print
la $t6, x_es_menor_que_7

move $a0, $t6
li $v0, 4
syscall
la $a0, newLine
li $v0, 4
syscall


Label6:


Label2:



#Epilogo
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
lw $s0, 0($sp)
lw $s1, 4($sp)
lw $s2, 8($sp)
lw $s3, 12($sp)
lw $s4, 16($sp)
lw $s5, 20($sp)
lw $s6, 24($sp)
lw $s7, 28($sp)
addi $sp, $sp, 32
jr $ra

