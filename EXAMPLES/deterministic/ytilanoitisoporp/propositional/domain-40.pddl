(define (domain ytilanoitisoporp)
(:requirements :action-costs :typing)
(:types boolean - object)
(:predicates (on ?b - boolean)
(off ?b - boolean)
(related ?b1 ?b2 - boolean)
(unrelated ?b - boolean))
(:functions (total-cost) - number
(switch-cost ?b - boolean) - number )
(:action switch-on
:parameters (?b1 ?b2 - boolean)
:precondition (and (off ?b1) (related ?b1 ?b2) )
:effect (and (not (off ?b1)) 
(off ?b2)
 (not (on ?b2))
(on ?b1)
(increase (total-cost) (switch-cost ?b1))
)
)
(:action unrelated-switch-on
:parameters (?b - boolean)
:precondition (and (off ?b) (unrelated ?b) )
:effect (and (not (off ?b)) 
(on ?b)
(increase (total-cost) (switch-cost ?b))
)
)
(:action switch-off
:parameters (?b - boolean)
:precondition (and (on ?b) )
:effect (and (not (on ?b))
(off ?b)
(increase (total-cost) (switch-cost ?b))
)
)
(:action super-switch
:parameters ()
:precondition ()
:effect (and 
(not (on o1 ))
(off o1 )
(on o2 )
(not (off o2 ))
(not (on o3 ))
(off o3 )
(on o4 )
(not (off o4 ))
(on o5 )
(not (off o5 ))
(not (on o6 ))
(off o6 )
(on o7 )
(not (off o7 ))
(on o8 )
(not (off o8 ))
(not (on o9 ))
(off o9 )
(not (on o10 ))
(off o10 )
(on o11 )
(not (off o11 ))
(not (on o12 ))
(off o12 )
(on o13 )
(not (off o13 ))
(not (on o14 ))
(off o14 )
(on o15 )
(not (off o15 ))
(on o16 )
(not (off o16 ))
(not (on o17 ))
(off o17 )
(not (on o18 ))
(off o18 )
(on o19 )
(not (off o19 ))
(on o20 )
(not (off o20 ))
(on o21 )
(not (off o21 ))
(not (on o22 ))
(off o22 )
(not (on o23 ))
(off o23 )
(on o24 )
(not (off o24 ))
(on o25 )
(not (off o25 ))
(not (on o26 ))
(off o26 )
(not (on o27 ))
(off o27 )
(on o28 )
(not (off o28 ))
(not (on o29 ))
(off o29 )
(on o30 )
(not (off o30 ))
(on o31 )
(not (off o31 ))
(on o32 )
(not (off o32 ))
(not (on o33 ))
(off o33 )
(on o34 )
(not (off o34 ))
(not (on o35 ))
(off o35 )
(not (on o36 ))
(off o36 )
(not (on o37 ))
(off o37 )
(not (on o38 ))
(off o38 )
(not (on o39 ))
(off o39 )
(on o40 )
(not (off o40 ))
(increase (total-cost) 100000))) 
)
