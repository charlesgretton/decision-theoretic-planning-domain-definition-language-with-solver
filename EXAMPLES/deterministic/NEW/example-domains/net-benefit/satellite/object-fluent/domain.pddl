(define (domain satellite)
  (:requirements :strips :equality :typing :fluents :durative-actions :goal-utilities)

  (:types satellite direction instrument mode)

  (:predicates 
   (on_board ?i - instrument ?s - satellite)
   (supports ?i - instrument ?m - mode)
   (power_avail ?s - satellite)
   (power_on ?i - instrument)
   (calibrated ?i - instrument)
   (have_image ?d - direction ?m - mode))

  (:functions
   (total-cost) - number
   (slew_time ?a ?b - direction) - number
   (calibration_time ?a - instrument ?d - direction) - number
   (traverse_cost ?a ?b - direction) - number
   (pointing ?s - satellite) - direction
   (calibration_target ?i - instrument) - direction)
 
  (:durative-action turn_to
   :parameters (?s - satellite ?d_new - direction ?d_prev - direction)
   :duration (= ?duration (slew_time ?d_prev ?d_new))
   :condition (at start (= (pointing ?s) ?d_prev))
   :effect (and (change (pointing ?s) ?d_new)
		(at end (increase (total-cost) (traverse_cost ?d_prev ?d_new))))
   )
 
  (:durative-action switch_on
   :parameters (?i - instrument ?s - satellite)
   :duration (= ?duration 2)
   :condition (and (over all (on_board ?i ?s)) 
		   (at start (power_avail ?s)))
   :effect (and (at end (power_on ?i))
                (at start (not (calibrated ?i)))
                (at start (not (power_avail ?s)))
		(at end (increase (total-cost) 3)))
   )

 
  (:durative-action switch_off
   :parameters (?i - instrument ?s - satellite)
   :duration (= ?duration 1)
   :condition (and (over all (on_board ?i ?s))
		   (at start (power_on ?i)))
   :effect (and (at start (not (power_on ?i)))
                (at end (power_avail ?s))
		(at end (increase (total-cost) 2)))
   )

  (:durative-action calibrate
   :parameters (?s - satellite ?i - instrument ?d - direction)
   :duration (= ?duration (calibration_time ?i ?d))
   :condition (and (over all (on_board ?i ?s))
		   (over all (= (calibration_target ?i) ?d))
		   (at start (= (pointing ?s) ?d))
		   (over all (power_on ?i))
		   (at end (power_on ?i)))
   :effect (and (at end (calibrated ?i))
		(at end (increase (total-cost) 2)))
   )

  (:durative-action take_image
   :parameters (?s - satellite ?d - direction ?i - instrument ?m - mode)
   :duration (= ?duration 7)
   :condition (and (over all (calibrated ?i))
		   (over all (on_board ?i ?s))
		   (over all (supports ?i ?m) )
		   (over all (power_on ?i))
		   (over all ( = (pointing ?s) ?d))
		   (at end (power_on ?i)))
   :effect (and (at end (have_image ?d ?m))
		(at end (increase (total-cost) 4)))
   )
)

;; EOF
