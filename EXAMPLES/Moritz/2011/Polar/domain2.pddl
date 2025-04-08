(define (domain cogx-dt-domain-0)

(:requirements :quantified-preconditions :numeric-fluents :equality :typing :negative-preconditions :conditional-effects :action-costs :adl :disjunctive-preconditions :partial-observability)

(:types  node - object)

(:functions  
             (reward ) - number
)


(:constants  
           N1 N2 N3 - node
)

(:predicates (on ?x - node))

(:action one 
	 :parameters (?x - node)
	 :effect (and (on ?x) 
		      (when (or (on N1) (on N2)) (assign (reward ) 555))
		      (when (or (not (on N1)) (not (on N2))) (assign (reward ) -333)))
)
(:action two 
	 :parameters (?x - node)
	 :effect (and (not (on ?x) )
		      (when (or (on N1) (on N2)) (assign (reward ) 555))
		      (when (or (not (on N1)) (not (on N2))) (assign (reward ) -333)))
))