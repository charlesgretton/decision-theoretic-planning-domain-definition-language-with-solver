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
#include "dtp_pddl_parsing_interface.hh"


#include "dtp_pddl_domain.hh"
#include "dtp_pddl_parsing_data_domain.hh"

using namespace pegtl;

using namespace Planning::Parsing;



void Planning::Parsing::parse_domain(const std::string& domain_file_name)
{
//     Domain_Stack* domain_Stack = new Domain_Stack;

    Planning::Parsing::domain_Stack.reset(new Domain_Stack());//domain_file_name)); = CXX__PTR_ANNOTATION(Domain_Stack)(new Domain_Stack());//domain_file_name));//

//     exit(0);
    
//     pegtl::smart_parse_file< Planning::Parsing::PDDL_Preamble_Domain >
//         ( true/*_trace*/, domain_file_name, *Planning::Parsing::domain_Stack );

    
    std::string preprocessed_file_contents = pddl_preprocessor(domain_file_name);
    
    VERBOSER(18, preprocessed_file_contents);
    
    pegtl::smart_parse_string< Planning::Parsing::PDDL_Preamble_Domain >
        ( true/*_trace*/,
          preprocessed_file_contents/*contents*/,
          *Planning::Parsing::domain_Stack );    

    Planning::Domain_Name domain_Name = domain_Stack->get__domain_Name();
    
    Planning::Parsing::domains[domain_Name] = Planning::Parsing::domain_Stack;
}
