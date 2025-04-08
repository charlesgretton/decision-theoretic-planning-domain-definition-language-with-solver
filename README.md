
# About

This is a reference implementation of the decision-theoretic planning domain definition langauge from the Framework Program 7 COGX project. 

[![COGX Dora Demonstrator Platform](https://img.youtube.com/vi/0QcmSDZR-c4/hqdefault.jpg)](https://www.youtube.com/watch?v=0QcmSDZR-c4)

## Papers

 - Marc Hanheide, Moritz Göbelbecker, Graham S. Horn, Andrzej Pronobis, Kristoffer Sjöö, Alper Aydemir, Patric Jensfelt, Charles Gretton, Richard Dearden, Miroslav Janícek, Hendrik Zender, Geert-Jan M. Kruijff, Nick Hawes, Jeremy L. Wyatt:
[Robot task planning and explanation in open and uncertain worlds.](https://doi.org/10.1016/j.artint.2015.08.008) Artif. Intell. 247: 119-150 (2017)

 - Moritz Göbelbecker, Charles Gretton, Richard Dearden:
[A Switching Planner for Combined Task and Observation Planning.](https://doi.org/10.1609/aaai.v25i1.8011) AAAI 2011: 964-970

# Compilation

To compile the decision-theoretic planning component of CogX, the following should suffice.

First, our make scripts by default assume you have ccache installed. 

```bash
apt-get install ccache
```

Then build the tool.

```bash 
make clean; make -j 8
```

If you do not want to install ccache for some reason, then just
edit the Makefile and remove it from the CXXPREFIX variable.
