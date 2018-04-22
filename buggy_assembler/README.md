# Buggy file interpreter (Assembler) # 
# By Seongjin Bien, Majorka Thanasi and Oana Miron #
# Software Engineering Spring 2018

0. Commenting : Start any comment with ;. The assembler will ignore that line.

1. Input : bug.buggy file with labels starting with underscore (_)

2. Output : final.txt file with processed assembly file 

3. Return codes

0 : Success!

66 (B) : Buggy file failed to load
67 (C) : Chunk size error
70 (F) : final.txt unable to be created (permission?) 
79 (O) : output.txt unable to be created (permission?)
83 (S) : Step 2 of processing output.txt unsuccessful 

