
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

#include "unsigned_integer__status_management.hh"

using namespace Planning;


Unsigned_Integer__Satisfaction_Status_Management::
Unsigned_Integer__Satisfaction_Status_Management(uint num)
    :status(num)
{
}

uint Unsigned_Integer__Satisfaction_Status_Management::size() const
{
    return status.size();
}


bool Unsigned_Integer__Satisfaction_Status_Management::valid_index(uint i) const
{
    return (i < status.size());
}

void Unsigned_Integer__Satisfaction_Status_Management::decrement_satisfaction(uint i)
{
    assert(valid_index(i));
    status.decrement(i);
}

void Unsigned_Integer__Satisfaction_Status_Management::increment_satisfaction(uint i)
{
    assert(valid_index(i));
    status.increment(i);
}

void Unsigned_Integer__Satisfaction_Status_Management::set_satisfaction(uint i, uint value)
{
    assert(valid_index(i));
    status.write(i, value);
}

uint Unsigned_Integer__Satisfaction_Status_Management::get_satisfaction_level(uint i) const
{
    assert(valid_index(i));
    return status.read(i);
}
