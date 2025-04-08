/* Copyright (C) 2010 Charles Gretton (c.gretton@bham.ac.uk)
 *
 * Authorship of this source code was supported by EC FP7-IST grant
 * 215181-CogX.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Dear CogX team member :: Please email (c.gretton@bham.ac.uk)
 * if you make a change to this and commit that change to SVN. In that
 * email, can you please attach the source files you changed as they
 * appeared before you changed them (i.e., fresh out of SVN), and the
 * diff files (*). Alternatively, you could not commit your changes,
 * but rather post me a patch (**) which I will test and then commit
 * if it does not cause any problems under testing.
 *
 * (*) see http://www.gnu.org/software/diffutils/diffutils.html --
 * GNU-09/2009
 *
 * (**) see http://savannah.gnu.org/projects/patch -- GNU-09/2009
 * 
 */
#ifndef DTP_PDDL_PARSING_INTERFACE_HH
#define DTP_PDDL_PARSING_INTERFACE_HH

#include "dtp_pddl_parsing_data.hh"

namespace Planning
{
    namespace Parsing
    {
        /* Parses a problem definition occurring in a file with name
         * \argument{problem__file_name}. The result of the parse is
         * stored in \global{Planning::Parsing::problem_stack}. Unless
         * otherwise specified, the domain associated with the problem
         * is that at \global{Planning::Parsing::domains} (with the
         * specified name -- as parsed) and otherwise that at
         * \global{Planning::Parsing::problem_stack}.
         *
         * Watch out, if you parse the same problem (wrt a particular
         * domain) twice using this function, then changes are not
         * merged. Rather that data which was first parsed is lost.*/ 
        void parse_problem(const std::string& problem_file_name);

        /* Parses a domain definition occurring in a file with name
         * \argument{domain__file_name}. The result of the parse is
         * stored in \global{Planning::Parsing::domain_stack}.
         *
         * Watch out, if you parse the same domain twice using this
         * function, then changes are not merged. Rather that data
         * which was first parsed is lost.*/
        void parse_domain(const std::string& domain__file_name);

        /* Internal use only. Removes comments from LISP (and
         * PDDL/DT-PDDL) formatted files.*/
        std::string pddl_preprocessor(const std::string& file_name);
    }
}


#endif
