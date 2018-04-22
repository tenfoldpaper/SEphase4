#Iteration 1

;
; stupid.buggy
;
_search: inst[search] = 0
 sense ahead food else _walk
 0. s.a. 1 inst[walk] f

 move else _search
 1. move 2 inst[search]

 pickup else _search
 goto _home
 2. p inst[home] inst[search]

_walk: inst[walk] = 3
 flip 3 else _searchright
 3. f3 4 inst[sright]

 turn left
 goto _search
 4. tl 1 inst[search] = 0

_searchright: inst[sright] = 5
 flip 2 else _searchstraight
 5. f2 6 inst[sstrght]

 turn right
 goto _search
 6. tr inst[searc] = 0
 6. tr 0 

_searchstraight: inst[sstrght] = 7 
 move else _walk
 goto _search 
 7. m inst[search] inst[walk]
 7. m 0 3 

_home: inst[home] = 8
 sense ahead home else _walkhome
 8. sa 9 inst[walkhome] home

 move else _home
 9. m 10 inst[home]
 
 drop
 goto _search
 10. d inst[search] 

_walkhome: inst[walkhome] = 11
 flip 3 else _walkhomeright
 11. f3 12 inst[walkhomeright]

 turn left
 goto _home
 12. tl inst[home]

_walkhomeright: inst[walkhomeright] = 13
 flip 2 else _walkhomestraight
 13. f2 14 inst[walkhomestraight]

 turn right
 goto _home
 14. tr inst[home]
 
_walkhomestraight: = inst[walkhomestraight] = 15
 move else walkhome
 goto home
 m inst[home] inst[walkhome]

#Iteration 2

;
; stupid.buggy
;
_search: inst[search] = 0
 sense ahead food else _walk
 0. s.a. 1 3 f

 move else _search
 1. move 2 0

 pickup else _search
 goto _home
 2. p 8 0

_walk: inst[walk] = 3
 flip 3 else _searchright
 3. f3 4 5

 turn left
 goto _search
 4. tl 1 0

_searchright: inst[sright] = 5
 flip 2 else _searchstraight
 5. f2 6 7

 turn right
 goto _search
 6. tr 0 

_searchstraight: inst[sstrght] = 7 
 move else _walk
 goto _search 
 7. m 0 3 

_home: inst[home] = 8
 sense ahead home else _walkhome
 8. sa 9 11 home

 move else _home
 9. m 10 8
 
 drop
 goto _search
 10. d 0 

_walkhome: inst[walkhome] = 11
 flip 3 else _walkhomeright
 11. f3 12 13

 turn left
 goto _home
 12. tl 8

_walkhomeright: inst[walkhomeright] = 13
 flip 2 else _walkhomestraight
 13. f2 14 15

 turn right
 goto _home
 14. tr 8
 
_walkhomestraight: = inst[walkhomestraight] = 15
 move else walkhome
 goto home
 m 8 11

#Dictionary of commands
sense arg1 arg2
move 
pickup
flip arg1
turn arg1
drop
goto
else

#Map of labels
l[label_1] = -1
...
l[label_n] = -1
 *After first iteration, these values will be changed to concrete line numbers.*

#Vector of input strings from .buggy
line_count = 0
invec[0] = line 1
...
invec[n] = line n

#2D Vector of answer strings
as[0] = line 1 chopped up
...
as[m-1] = line m chopped up

m would roughly be n - len(l)
